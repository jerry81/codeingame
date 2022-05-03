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
    humans << { id => human_id, x => human_x, y => human_y }
  end
  zombie_count = gets.to_i
  zombie_count.times do
    zombie_id, zombie_x, zombie_y, zombie_xnext, zombie_ynext = gets.split(" ").collect { |x| x.to_i }
    zombies << { id => zombie_id, x => zombie_x, y => zombie_y }
  end

  # find closest zombie to human 

  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."

  puts "0 0" # Your destination coordinates
end
