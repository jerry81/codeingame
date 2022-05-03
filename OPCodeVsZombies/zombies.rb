STDOUT.sync = true # DO NOT REMOVE
# Save humans, destroy zombies!


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
  # find closest zombie to human
  closestD = nil
  closestMidX = nil
  closestMidY = nil
  zombies.each do |z|
    humans.each do |h|
      dx = (h[:x] - z[:x]).abs
      dy = (h[:y] - z[:y]).abs
      midx = ((h[:x] + z[:x]) / 2)
      midy = ((h[:y] + z[:y]) / 2)
      dist = Math.sqrt((dx ** 2) + (dy ** 2))
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