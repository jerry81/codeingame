STDOUT.sync = true # DO NOT REMOVE
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
# 1920x1000
# queen size 30 units (r)
# movement - 60 units 
$barracks = {:knight => "BARRACKS-KNIGHT", :archer => "BARRACKS-ARCHER", :giant => "BARRACKS-GIANT"}

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

$build_knight = true
loop do
  # touched_site: -1 if none - this is the building i am touching 
  gold, touched_site = gets.split(" ").collect { |x| x.to_i }
  STDERR.puts "touched_site is #{touched_site}"
  open_sites = []
  my_sites = []
  enemy_sites = []
  my_site_types = {}
  my_knight_sites = []
  my_archer_sites = []
  my_giant_sites = []
  my_tower_sites = []
  enemy_towers = []
  num_sites.times do
    # ignore_1: used in future leagues
    # ignore_2: used in future leagues
    # structure_type: -1 = No structure, 2 = Barracks
    # owner: -1 = No structure, 0 = Friendly, 1 = Enemy
    site_id, ignore_1, ignore_2, structure_type, owner, param_1, param_2 = gets.split(" ").collect { |x| x.to_i }
    site = $sites[site_id]

    if owner == -1 
        open_sites << site_id
    end
    
    if owner == 0 
        my_sites << {:id => site_id, :type => param_2}
        my_site_types[site_id] = param_2
        if structure_type == 1
          my_tower_sites << { :id => site_id, :x => site[:x], :y => site[:y] }
        end

        if structure_type == 2 
          case param_2
          when 0
            my_knight_sites << { :id => site_id, :x => site[:x], :y => site[:y]}
          when 1
            my_archer_sites << { :id => site_id, :x => site[:x], :y => site[:y]}
          else 
            my_giant_sites << { :id => site_id, :x => site[:x], :y => site[:y]}
          end
        end
    end

    if owner == 1
      enemy_sites << site_id 
    end
  end
  STDERR.puts "open sites are #{open_sites}"
  STDERR.puts "my sites are #{my_sites}"
  num_units = gets.to_i
  q_loc = {}
  my_archers = []
  my_knights = []
  my_giants = []
  enemy_archers = []
  enemy_knights = []
  enemy_giants = []
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
  STDERR.puts "my_towers #{my_tower_sites}"
  STDERR.puts "my_knight_sites #{my_knight_sites}"
  STDERR.puts "my_archer_sites #{my_archer_sites}"
  STDERR.puts "my_giant_sites #{my_giant_sites}"
  STDERR.puts "myknights #{my_knights} my archers #{my_archers}"
  STDERR.puts "enemeyk #{enemy_knights} enemy archers #{enemy_archers}"
  STDERR.puts "queen loc is #{q_loc}"
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  can_build = touched_site > -1 && open_sites.include?(touched_site)
  queen_action = "WAIT"
  train_action = "TRAIN"
  if can_build
    build_sym = $build_knight ? :knight : :archer
    $build_knight = !$build_knight
    queen_action = "BUILD #{touched_site} #{$barracks[build_sym]}"
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
  site_ids = my_sites.map do |y| 
    y[:id]
  end
  dists = make_distances_map(q_loc, site_ids)
  sorted_barracks = dists.sort_by { |x| x[:dist] }
  filtered_barracks = []
  if enemy_knights.count == 0 || my_archers.count > 4
    # build knights 
    filtered_barracks = sorted_barracks.select do |x| 
      my_site_types[x[:id]] == 0
    end
  else 
    # build archers 
    filtered_barracks = sorted_barracks.select do |x| 
      my_site_types[x[:id]] == 1
    end
  end
  filtered_barracks.first(lim).each do |x|
    train_action << " #{x[:id].to_i}"
  end
  # First line: A valid queen action
  # Second line: A set of training instructions
  puts queen_action
  puts train_action
end
