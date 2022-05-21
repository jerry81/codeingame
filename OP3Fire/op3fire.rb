STDOUT.sync = true # DO NOT REMOVE
# Read the constant data of the map before the main loop, then read the state of the fire and give an action at each turn

# tree_treatment_duration: cooldown for cutting a "tree" cell
# tree_fire_duration: number of turns for the fire to propagate on adjacent cells from a "tree" cell
# tree_value: value lost if a "tree" cell is burnt or cut
tree_treatment_duration, tree_fire_duration, tree_value = gets.split(" ").collect { |x| x.to_i }
# house_treatment_duration: cooldown for cutting a "house" cell
# house_fire_duration: number of turns for the fire to propagate on adjacent cells from a "house" cell
# house_value: value lost if a "house" cell is burnt or cut
house_treatment_duration, house_fire_duration, house_value = gets.split(" ").collect { |x| x.to_i }
# width: number of columns in the grid
# height: number of rows in the grid
width, height = gets.split(" ").collect { |x| x.to_i }
# fire_start_x: column where the fire starts
# fire_start_y: row where the fire starts
fire_start_x, fire_start_y = gets.split(" ").collect { |x| x.to_i }

# step 1 build grid 
grid = []
height.times do
  grid_line = gets.chomp
  grid << grid_line 
end

grid.each do |l|
  STDERR.puts "grid is #{l}"
end
# game loop
loop do
  cooldown = gets.to_i # number of turns remaining before you can cut a new cell
  height.times do
    inputs = gets.split(" ")
    for j in 0..(width-1)
      # fire_progress: state of the fire in this cell (-2: safe, -1: no fire, 0<=.<fireDuration: fire, fireDuration: burnt)
      fire_progress = inputs[j].to_i
    end
  end

  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."


  # WAIT if your intervention cooldown is not zero, else position [x] [y] of your intervention.
  puts "WAIT"
end
