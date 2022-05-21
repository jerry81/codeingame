STDOUT.sync = true # DO NOT REMOVE
# Read the constant data of the map before the main loop, then read the state of the fire and give an action at each turn

# tree_treatment_duration: cooldown for cutting a "tree" cell
# tree_fire_duration: number of turns for the fire to propagate on adjacent cells from a "tree" cell
# tree_value: value lost if a "tree" cell is burnt or cut
tree_treatment_duration, tree_fire_duration, tree_value = gets.split(" ").collect { |x| x.to_i }
STDERR.puts "tree_treatment_duration, tree_fire_duration, tree_value #{tree_treatment_duration} #{tree_fire_duration} #{tree_value}"
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
STDERR.puts "house_treatment_duration, house_fire_duration, house_value #{house_treatment_duration} #{house_fire_duration} #{house_value}"
# step 1 build grid 
grid = []
houses = []
count = 0 
height.times do
  grid_line = gets.chomp
  grid << grid_line 
  grid_line.split('').each_with_index do |ch,i| 
    # index houses and safe
    if ch == 'X'
      houses << {:y => count, :x => i}
    end
  end
  count += 1
end

grid.each do |l|
  STDERR.puts "grid is #{l}"
end

houses.each do |h|
    STDERR.puts "h is #{h}"
  end
# game loop
cut = []
loop do
  cooldown = gets.to_i # number of turns remaining before you can cut a new cell
  fire_progress_grid = []
  cuttable = []
  y = 0
  fires = []
  height.times do
    inputs = gets.split(" ")
    fire_progress_grid << []
    for j in 0..(width-1)
      # fire_progress: state of the fire in this cell (-2: safe, -1: no fire, 0<=.<fireDuration: fire, fireDuration: burnt)
      fire_progress = inputs[j].to_i
      if fire_progress >= 0 
        fires << {:x => j, :y => y, :v => fire_progress}
      end
      if fire_progress == -1 
        cuttable << {:x => j, :y => y}
      end
      fire_progress_grid[y][j] = fire_progress
    end
    y+=1
  end

  fires.each do |f|
    STDERR.puts "f is #{f}"
  end

  cuttable.each do |c|
    STDERR.puts "c is #{c}"
  end

  # naive approach - find the most urgent fires 
  fires.sort_by! do |f| 
    [f[:fire_progress]]
  end

  urgent_fire = fires.first
  STDERR.puts "tfd #{tree_fire_duration}"
  STDERR.puts "urgent #{urgent_fire}"
  time_till_burnt = tree_fire_duration - urgent_fire[:v] 
  x = urgent_fire[:x]
  y = urgent_fire[:y]
  possibilities = []
  if time_till_burnt > tree_treatment_duration # TODO: cut ahead of time 
    # cut a neighbor - TODO: optimize by cutting neighbor between fire and closest house 
    # check neighbors 
    uy = y-1 
    dy = y+1 
    rx = x+1 
    lx = x-1
    # u, r, d, l 
    if uy > -1
        usq = fire_progress_grid[uy][x] # TODO: DRY 
        if usq == -1 
            possibilities << {:x=>x, :y=>uy}
        end
    end
    if rx < width 
        rsq = fire_progress_grid[y][rx]
        if rsq == -1 
            possibilities << {:x=>rx, :y=>y}
        end
    end
    if dy < height 
        dsq = fire_progress_grid[dy][x]
        if dsq == -1 
            possibilities << {:x=>x, :y=>dy}
        end
    end
    if lx > -1 
        lsq = fire_progress_grid[y][lx]
        if lsq == -1 
            possibilities << {:x=>lx, :y=>y}
        end
    end
  end
  # WAIT if your intervention cooldown is not zero, else position [x] [y] of your intervention.
  if cooldown > 0 || possibilities.empty?
    puts "WAIT"
  else 
    STDERR.puts "possibilities are #{possibilities}"
    cut = possibilities.first
    puts "#{cut[:x]} #{cut[:y]}"
  end

  

  # fires always spread n,s,e,w when the fire_condition reaches the limit 

end
