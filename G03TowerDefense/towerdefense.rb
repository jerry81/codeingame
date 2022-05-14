STDOUT.sync = true # DO NOT REMOVE
# Survive the attack waves
# map is 17x17 
# startx is either 0 or 17?
player_id = gets.to_i
width, height = gets.split(" ").collect { |x| x.to_i }
lines = []
height.times do
  line = gets.chomp
  lines << line
end
heatmap = []

def dist_from_cent(x,y)
  return (x-8)**2 + (y-8)**2
end

def count_neighbors(lines,x,y)
  count = 0
  [-1, 0, 1].each do |o1|
    [-1,0,1].each do |o2|
      if o1 == 0 && o2 == 0 
        next
      end
      
      newx = x + o1 
      newy = y + o2 
      if newx < 0 || newx > 16 
        next
      end

      if newy < 0 || newy > 16
        next
      end

      if lines[newy][newx] == '.'
        count += 1
      end
    end
  end
  count 
end

def build_heat_map(lines, height, width) 
  # { 0: { 0: { :adjacent_paths => 1, :dist_from_center => 7.33 }}}
  ar = []
  for y in 0..height-1 do
    for x in 0..width-1 do
      c = lines[y][x]
      if c=="#"
        dist = dist_from_cent(x,y)
        nc = count_neighbors(lines,x,y)
        ar << { :x => x, :y => y, :dist => -dist, :nc => nc }
      end
    end
  end
  ar 
end 

heatmap = build_heat_map(lines, height, width)

sorted = heatmap.sort_by { |item| [item[:nc], item[:dist]] }


my_towers = {} # ids of towers (for upgrading)
$overflow = {} # lookup table for tower ids 

def add_tower(towers,id,type)
  if towers[id].nil?
      towers[id]={:type => type}
  end
  towers
end

def get_my_towers_count(towers, type)
  return towers.select { |k,v| v[:type] == type }.count
end


def build_output(arr, curCount, noGlues, towers, first) 
    str = "PASS;"
    glueStr = noGlues ?  "HEALTOWER" : "GLUETOWER"
    if arr.empty?
      towers.each do |k,t| 
        type = 'RELOAD'
        STDERR.puts "type is #{t}"
        if t[:type] == "GLUETOWER" || t[:type] == "HEALTOWER"
          i = rand(1)
          type = ['RANGE', 'RELOAD'][i]
        else 
          i = rand(2)
          type = ['DAMAGE', 'RANGE', 'RELOAD'][i]
        end
        str << "UPGRADE #{k} #{type};"
      end
    end
    if first && arr.count > 2
      STDERR.puts "first step and large array"
      gons = ["GLUETOWER", "FIRETOWER", "GUNTOWER"]
      for i in 0..2
        loc = arr[i]
        str << "BUILD #{loc[:x]} #{loc[:y]} #{gons[i]};"
      end
      return str
    end
    arr.each do |i|
        guns = ["GUNTOWER", "FIRETOWER", "HEALTOWER"]
        for _ in 0..5 
          guns << "GUNTOWER"
        end
        for _ in 0..2
          guns << "FIRETOWER"
        end
        c = rand(12)
        gun = guns[c]
        if first
          gun = "GLUETOWER"
          first = false
        end
        str += "BUILD #{i[:x]} #{i[:y]} #{gun};"
    end
    return str
end


def get_spot_for_glue(lines, x, y, my_t)
  # check if glue is within 2 squares, if nearby return nil 
  # else return { x: gluex, y: gluey }
  offsets = *(-2..2) # splat to create array from number range 

  spot = nil
  offsets.each do |xoff| 
    offsets.each do |yoff|
      cur_x = xoff + x 
      cur_y = yoff + y 
      lines_item = lines[cur_y][cur_x]

      if lines_item != '#' 
        if lines_item == 'T'
          lines_item = $overflow.dig(curx, cury)
          STDERR.puts "im in function using global overflow #{$overflow}"
        end
        type = my_t.dig(lines_item, :type)
        STDERR.puts "type is #{type}"
        if type == "GLUETOWER"
          return nil 
        end

        next
      end

      nc = count_neighbors(lines, cur_x, cur_y)
      if nc < 3 
        next
      end
      
      STDERR.puts "found spot for #{x}, #{y}"
      spot = { :x => cur_x, :y => cur_y }
    end
  end
  spot 
end
# in the order of the filtered canyon hotspots, find if there is a glue tower "nearby"
def find_spot_for_glue(lines, sfil, my_t) # sfil = sorted and filtered canyons
  sfil.each do |canyon|
    map_item = lines[canyon[:y]][canyon[:x]]

    if map_item != '#'
      if map_item == 'T'
        map_item = $overflow.dig(canyon[:y], canyon[:x])
      end

      if my_t[map_item].nil? 
        next
      end

      spot = get_spot_for_glue(lines, canyon[:x], canyon[:y], my_t)
      if spot.nil?
        next
      end
      return spot
    end
  end
  nil 
end

prev_tower_count = 0
upgrade_phase = false 
turn_count = 0
# game loop
loop do
  my_money, my_lives = gets.split(" ").collect { |x| x.to_i }
  opponent_money, opponent_lives = gets.split(" ").collect { |x| x.to_i }
  tower_count = gets.to_i
  tower_count.times do
    tower_type, tower_id, owner, x, y, damage, attack_range, reload, cool_down = gets.split(" ")
    if owner.to_s == player_id.to_s
        my_towers = add_tower(my_towers, tower_id, tower_type)
    end
    tower_id = tower_id.to_i
    owner = owner.to_i
    x = x.to_i
    y = y.to_i
    damage = damage.to_i
    attack_range = attack_range.to_f
    reload = reload.to_i
    cool_down = cool_down.to_i
    new_id = tower_id.to_i < 10 ? tower_id.to_i : 'T'
    lines[y][x] = new_id.to_s # the entire map is updated every turn with new towers
    # but now we need a an overflow lookup table 
    if new_id == 'T' 
      if $overflow[y].nil?
        $overflow[y] = {}
      end
      
      if $overflow[y][x].nil?
        $overflow[y][x] = {}
      end
      $overflow[y][x][:id] = tower_id.to_s
    end
  end
  attacker_count = gets.to_i
  attacker_count.times do
    attacker_id, owner, x, y, hit_points, max_hit_points, current_speed, max_speed, slow_time, bounty = gets.split(" ")
    attacker_id = attacker_id.to_i
    owner = owner.to_i
    x = x.to_f
    y = y.to_f
    hit_points = hit_points.to_i
    max_hit_points = max_hit_points.to_i
    current_speed = current_speed.to_f
    max_speed = max_speed.to_f
    slow_time = slow_time.to_i
    bounty = bounty.to_i
  end

  # should make a method to clean up the sorted table 

  STDERR.puts "gun towers count #{get_my_towers_count(my_towers, "GUNTOWER")}"

  STDERR.puts "fire towers count #{get_my_towers_count(my_towers, "FIRETOWER")}"

  STDERR.puts "glue towers count #{get_my_towers_count(my_towers, "GLUETOWER")}"

  atk_c = get_my_towers_count(my_towers, "GUNTOWER") + get_my_towers_count(my_towers, "FIRETOWER")
  glue_c = get_my_towers_count(my_towers, "GLUETOWER")
  turn_count += 1
  total_c = atk_c + glue_c 
  stagnating = (total_c == prev_tower_count) && (my_money > 200) && (turn_count > 50)
  if total_c > 7 || stagnating 
    upgrade_phase = true 
  end

  prev_tower_count = total_c
  
  filtered = sorted.select { |i| i[:nc] > 3 } # like filter
  sfil = filtered.sort_by { |j| [j[:nc], j[:dist]] }.reverse

  if upgrade_phase 
    lines.each do |l| 
      STDERR.puts "line is #{l}"
    end
    # upgrade logic goes here 
    # upgrade priority goes by the sfil list 
    # focus on the top 3 towers 
    # we need to find id by location 
    top_ids = sfil.map do |item| 
      li = lines[item[:y]][item[:x]]
      li == 'T' ? $overflow.dig(item[:y], item[:x]) : li
      STDERR.puts "item is  #{li}"
    end
    STDERR.puts "top 3 ids upgrade are #{top_ids}"
  end

  if glue_c < 2 && atk_c > 1
    if atk_c > (glue_c * 2)
      spot = find_spot_for_glue(lines, sfil, my_towers)
      if !spot.nil?
        puts "BUILD #{spot[:x]} #{spot[:y]} GLUETOWER"
        next
      end
    end
  end
  first_output = "PASS;"
  sfil.each do |i|
    x = i[:x] 
    y = i[:y]
    gun = i[:nc] > 7 ? "FIRETOWER" : "GUNTOWER"
    first_output << "BUILD #{x} #{y} #{gun};"
  end
  puts first_output
end


# # # # # # # # # # # # # # # # #
# 0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0 x == 8 is midpoint 