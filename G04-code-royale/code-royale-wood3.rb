STDOUT.sync = true # DO NOT REMOVE
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# 1920x1000
# queen size 30 units (r)
# movement - 60 units 
barracks = {:knight => "BARRACKS-KNIGHT", :archer => "BARRACKS-ARCHER"}

$sites = {}
num_sites = gets.to_i
num_sites.times do
  site_id, x, y, radius = gets.split(" ").collect { |x| x.to_i }
  sites[side_id] = {
      :x => x,
      :y => y,
      :radius => radius
    }
end
STDERR.puts "sites are #{sites}"
# game loop
loop do
  # touched_site: -1 if none - this is the building i am touching 
  gold, touched_site = gets.split(" ").collect { |x| x.to_i }
  num_sites.times do
    # ignore_1: used in future leagues
    # ignore_2: used in future leagues
    # structure_type: -1 = No structure, 2 = Barracks
    # owner: -1 = No structure, 0 = Friendly, 1 = Enemy
    site_id, ignore_1, ignore_2, structure_type, owner, param_1, param_2 = gets.split(" ").collect { |x| x.to_i }
  end
  num_units = gets.to_i
  num_units.times do
    # unit_type: -1 = QUEEN, 0 = KNIGHT, 1 = ARCHER
    x, y, owner, unit_type, health = gets.split(" ").collect { |x| x.to_i }
  end

  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."


  # First line: A valid queen action
  # Second line: A set of training instructions
  puts "WAIT"
  puts "TRAIN"
end
