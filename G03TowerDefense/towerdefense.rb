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

# heatmap.each do |i|
#   STDERR.puts "item is #{i}"
# end

# sort the heat map by neighbor count and by distance 

sorted = heatmap.sort_by { |item| [item[:nc], item[:dist]] }

# sorted.reverse.each do |i| 
#   STDERR.puts "sorted is #{i}"
# end

# on first step - 
# grab the squares with 6+ surrounding paths first and put fire towers there.

# next step - further optimize tower distribution - 
# spread out the glues 
# ensure glues are followed by guns
# wherever there is a canyon with more than x paths surrounding it, place a firetower 

# OR

# i lose to players that greedily take all bendy paths (most adjacent paths)
# it also seems placing near own base and opponents base doesn't matter as much 


startPositionFound = false
startPositions = []



# next step - pre-game path analysis 
# from the start - identify all exit locations and as a first step build one at each exit location 
# different map types 
# single entrance 
  # easy - build one at each entrance 
# multi entrance 


my_towers = {} # ids of towers (for upgrading)


def add_tower(towers,id,type)
  if towers[id].nil?
      towers[id]={:type => type}
  end
  towers
end

def findStartPosition(sp, h, l)
    pos = sp[0]
    x = pos[:x]
    y = pos[:y]
    for i in 0..h-1
        if l[i][x] == '.' && i != y
          sp << { :x=>x, :y=>i }
        end
    end
    sp
end



def find_paths(x, lines) 
    returned = []
    for i in 0..16
        item = lines[i][x]
        if item == '.'
            returned << i 
        end
    end
    returned
end

def getUnsaturated(x, paths, lines)
    locations = []
    l = [0, x-1].max 
    r = [16, x+1].min
    sortedPaths = paths.sort {
      |a,b| (8-a).abs() <=> (8-b).abs()
    }
    STDERR.puts "sortedPaths is #{sortedPaths}"
    sortedPaths.each do |y|
        u = [y-1, 0].max
        d = [y+1, 16].min
        li = lines[y][l]
        ri = lines[y][r]
        ui = lines[u][x]
        di = lines[d][x]
        # check if any spot is open 
        lio = li == '#'
        rio = ri == '#'
        uio = ui == '#'
        dio = di == '#'
        if lio
            locations << { :x => l, :y => y }
        end
        if rio 
            locations << { :x => r, :y => y }
        end 
        if uio
            locations << { :x => x, :y => u }
        end
        if dio
            locations << { :x => x, :y => d }
        end
    end
    locations
end

def find_starts(lines)
  l = find_paths(0, lines)
  r = find_paths(16, lines)
  STDERR.puts "l is #{l} and r is #{r}"
end

find_starts(lines)


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

def in_bounds(x,y)
    return x >= 0 && x < 17 && y >= 0 && x < 17
end
outputarr = []
counter = 0
glueFlag = false 
initial = true
# game loop
loop do
  my_money, my_lives = gets.split(" ").collect { |x| x.to_i }
  opponent_money, opponent_lives = gets.split(" ").collect { |x| x.to_i }
  tower_count = gets.to_i
  if my_money < 70
    glueFlag = true
  end
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
    lines[y][x] = tower_id.to_s
  end
  attacker_count = gets.to_i
  attacker_count.times do
    attacker_id, owner, x, y, hit_points, max_hit_points, current_speed, max_speed, slow_time, bounty = gets.split(" ")
    attacker_id = attacker_id.to_i
    if (owner.to_s == player_id.to_s && !startPositionFound)
        xf = x.to_f.round
        yf = y.to_f.round
        if in_bounds(xf,yf)
          startPositions << { :x => xf, :y => yf }
          startPositionFound = true
          newStartPositions = findStartPosition(startPositions, height, lines)
          STDERR.puts "found all start positions #{newStartPositions}"
        end
    end
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

  offset = counter % 3
  gunCounter = counter % 10 
  counter += 1
  if counter % 25 == 0 
    glueFlag = false
  end
  # round 1 grab the center
  center = 8
  
  # next, adapt the first step into general strategy
  # on every step - try to grab the hottest spots and put guntowers there
  
  filtered = sorted.select { |i| i[:nc] > 2 } # like filter
  sfil = filtered.sort_by { |j| [j[:nc], j[:dist]] }.reverse
  STDERR.puts "sfil is #{sfil}"
  first_output = "PASS;"
  sfil.each do |i|
    x = i[:x] 
    y = i[:y]
    first_output << "BUILD #{x} #{y} GUNTOWER;"
  end
  puts first_output
  next
  if startPositionFound
    nextCol = 8
    if startPositions[0][:x] < center
      nextCol = center - offset 
      STDERR.puts "nextCol is #{nextCol}"
    else 
      nextCol = center + offset
      STDERR.puts "nextCol is #{nextCol}"
    end
    paths = find_paths(nextCol, lines)
    locs = getUnsaturated(nextCol,paths, lines)
    str = build_output(locs, gunCounter, glueFlag, my_towers, false)
    puts str
  else
    paths = find_paths(center, lines)
    locs = getUnsaturated(center,paths, lines)
    str = build_output(locs, gunCounter, glueFlag, my_towers, true)
    puts str
  end
end


# # # # # # # # # # # # # # # # #
# 0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0 x == 8 is midpoint 