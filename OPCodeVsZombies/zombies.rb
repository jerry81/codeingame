STDOUT.sync = true # DO NOT REMOVE
# Save humans, destroy zombies!

def calc_dist(x,y,x2,y2)
  return Math.sqrt((x-x2)**2 + (y-y2)**2)
end

# test distance
STDERR.puts "expect 5 #{calc_dist(0,0,3,4)}"
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
