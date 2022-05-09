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
startPositionFound = false
startPositions = []

# unfortunately a path that is very high or low y on the map performs terribly as i will always try to
# place from the top down 

# next step - pre-game path analysis 
# from the start - identify all exit locations and as a first step build one at each exit location 
# different map types 
# single entrance 
  # easy - build one at each entrance 
# multi entrance 


my_towers = {} # ids of towers (for upgrading)

def add_tower(towers,id)
  if towers[id].nil?
      towers[id]=true
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
    paths.each do |y|
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

def build_output(arr) 
    str = "PASS;"
    arr.each do |i|
        str += "BUILD #{i[:x]} #{i[:y]} GUNTOWER;"
    end
    return str
end

def in_bounds(x,y)
    return x >= 0 && x < 17 && y >= 0 && x < 17
end
outputarr = []
counter = 0
# game loop
loop do
  my_money, my_lives = gets.split(" ").collect { |x| x.to_i }
  opponent_money, opponent_lives = gets.split(" ").collect { |x| x.to_i }
  tower_count = gets.to_i
  tower_count.times do
    tower_type, tower_id, owner, x, y, damage, attack_range, reload, cool_down = gets.split(" ")
    if owner.to_s == player_id.to_s
        my_towers = add_tower(my_towers, tower_id)
    end
    tower_id = tower_id.to_i
    owner = owner.to_i
    x = x.to_i
    y = y.to_i
    damage = damage.to_i
    attack_range = attack_range.to_f
    reload = reload.to_i
    cool_down = cool_down.to_i
    lines[x][y] = tower_id.to_s
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

  offset = counter % 6
  counter += 1
  # round 1 grab the center
  center = 8
  STDERR.puts "lines is #{lines}"
  STDERR.puts "my towers are #{my_towers}"
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
    str = build_output(locs)
    puts str
  else
    paths = find_paths(center, lines)
    locs = getUnsaturated(center,paths, lines)
    str = build_output(locs)
    puts str
  end
end


# # # # # # # # # # # # # # # # #
# 0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0 x == 8 is midpoint 