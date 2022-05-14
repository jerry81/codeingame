STDOUT.sync = true # DO NOT REMOVE
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# 1920x1000
# queen size 30 units (r)
# movement - 60 units 
$barracks = {:knight => "BARRACKS-KNIGHT", :archer => "BARRACKS-ARCHER"}

$sites = {}
num_sites = gets.to_i
num_sites.times do
  site_id, x, y, radius = gets.split(" ").collect { |x| x.to_i }
  $sites[site_id] = {
      :x => x,
      :y => y,
      :radius => radius
    }
end
# game loop

def make_distances_map(q_loc, open_sites)
    qx = q_loc[:x]
    qy = q_loc[:y]
    distances = open_sites.map do |id|
        site_loc = $sites[id]
        sx = site_loc[:x]
        sy = site_loc[:y]
        dist = (sx-qx)**2 + (sy-qy)**2 
        {:id=>id, :dist=>dist, :x=>sx, :y=>sy}
    end
    distances 
end

loop do
  # touched_site: -1 if none - this is the building i am touching 
  gold, touched_site = gets.split(" ").collect { |x| x.to_i }
  STDERR.puts "touched_site is #{touched_site}"
  open_sites = []
  my_sites = []
  num_sites.times do
    # ignore_1: used in future leagues
    # ignore_2: used in future leagues
    # structure_type: -1 = No structure, 2 = Barracks
    # owner: -1 = No structure, 0 = Friendly, 1 = Enemy
    site_id, ignore_1, ignore_2, structure_type, owner, param_1, param_2 = gets.split(" ").collect { |x| x.to_i }
    if owner == -1 
        open_sites << site_id
    end
    
    if owner == 0 
        my_sites << {:id => site_id, :type => param_2}
    end
  end
  STDERR.puts "open sites are #{open_sites}"
  STDERR.puts "my sites are #{my_sites}"
  num_units = gets.to_i
  q_loc = {}
  my_archers = []
  my_knights = []
  enemy_archers = []
  enemy_knights = []
  num_units.times do
    # unit_type: -1 = QUEEN, 0 = KNIGHT, 1 = ARCHER
    x, y, owner, unit_type, health = gets.split(" ").collect { |x| x.to_i }
    if unit_type == -1 && owner == 0
        q_loc = {:x=>x, :y=>y}
    end
    if unit_type == 0 
        case owner 
        when 0
            my_knights << {:x=>x,:y=>y}
        when 1
            enemy_knights << {:x=>x,:y=>y}
        end
    end
    if unit_type == 1 
        case owner 
        when 0
            my_archers << {:x=>x,:y=>y}
        when 1
            enemy_archers << {:x=>x,:y=>y}
        end
    end
  end

  STDERR.puts "myknights #{my_knights} my archers #{my_archers}"
  STDERR.puts "enemeyk #{enemy_knights} enemy archers #{enemy_archers}"
  STDERR.puts "queen loc is #{q_loc}"
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  can_build = touched_site > -1 && open_sites.include?(touched_site)
  queen_action = "WAIT"
  train_action = "TRAIN"
  if can_build
    queen_action = "BUILD #{touched_site} #{$barracks[:archer]}"
  elsif open_sites.count > 0
    # find next site 
    qx = q_loc[:x]
    qy = q_loc[:y]
    distances = make_distances_map(q_loc, open_sites)
    sorted_d = distances.sort_by { |x| x[:dist] }
    closest = sorted_d.first
    queen_action = "MOVE #{closest[:x]} #{closest[:y]}"
  else

  end

  lim = gold / 100
  my_sites.first(lim).each do |x|
    site_ids = my_sites.map do |y| 
        y[:id]
    end
    dists = make_distances_map(q_loc, site_ids)
    STDERR.puts "dists in training is #{dists}"
    train_action << " #{x[:id].to_i}"
  end
  # First line: A valid queen action
  # Second line: A set of training instructions
  puts queen_action
  puts train_action
end
