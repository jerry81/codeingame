STDOUT.sync = true # DO NOT REMOVE
# Save humans, destroy zombies!

def calc_dist(x,y,x2,y2)
  return Math.sqrt((x-x2)**2 + (y-y2)**2)
end

# test distance
STDERR.puts "expect 5 #{calc_dist(0,0,3,4)}"

def build_hz_map(h,z)
    r = {}
    h.each do |i|
        hi = i[:id]
        hx = i[:x]
        hy = i[:y]
        r[hi] = []
        z.each do |j|
            zx = j[:x]
            zy = j[:y]
            dist = calc_dist(hx,hy,zx,zy)
            r[hi] << {:id=>hi, :x=>hx, :y=>hy, :d=>dist}
        end
        r[hi] = r[hi].sort_by do |v|
          [v[:d]]
        end
        r[hi] = r[hi].first 
    end
    r
end

def add_savable_info(hh,hz)
  hz.each do |_,z|
    hero_d_o = hh[z[:id]]
    hero_d = hero_d_o[:d]
    z_d = z[:d]
    savable = hero_d < ((z_d*(10/4))+2000)
    STDERR.puts "#{z[:id]} savable is #{savable}"
  end
end
# game loop
loop do
  x, y = gets.split(" ").collect { |x| x.to_i }
  human_count = gets.to_i
  humans = []
  zombies = []
  human_count.times do
    human_id, human_x, human_y = gets.split(" ").collect { |x| x.to_i }
    humans << { :id => human_id, :x => human_x, :y => human_y }
  end
  zombie_count = gets.to_i
  zombie_count.times do
    zombie_id, zombie_x, zombie_y, zombie_xnext, zombie_ynext = gets.split(" ").collect { |x| x.to_i }
    zombies << { :id => zombie_id, :x => zombie_x, :y => zombie_y, :xn => zombie_xnext, :yn => zombie_ynext}
  end
  STDERR.puts "humans #{humans} and zombies #{zombies}"
  human_to_zombie_distance_map = build_hz_map(humans,zombies)
  hero_to_h_d_m = build_hz_map(humans, [{:x=>x, :y=>y}])
  STDERR.puts "hzmap is #{human_to_zombie_distance_map}"
  STDERR.puts "hhmap is #{hero_to_h_d_m}"
  add_savable_info(hero_to_h_d_m, human_to_zombie_distance_map)
  # hero moves 1000
  # zombie moves 400 
  # filter unsavable humans 
  # only save human if it is savable 
  closestD = nil
  closestMidX = nil
  closestMidY = nil
  zombies.each do |z|
    humans.each do |h|
      midx = ((h[:x] + z[:x]) / 2)
      midy = ((h[:y] + z[:y]) / 2)
      dist = calc_dist(h[:x],h[:y],z[:x],z[:y])
      if closestD.nil? || closestD > dist
        closestD = dist
        closestMidX = z[:xn]
        closestMidY = z[:yn]
      end
    end
  end
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."

  puts "#{closestMidX} #{closestMidY}" # Your destination coordinates
end
