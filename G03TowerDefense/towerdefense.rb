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
STDERR.puts(lines)
# step 1: get your own location simple case - 1 starting point 
startPositionFound = false
startPositions = []
# step 2: find multiple locations - done 
# step 3: keep track of towers built 
# goal: build a map like the following
# towers = { 0 => { 0 => true }, 3 => { 1 => true, 12 => true } } 
# this means (0,0) (3,1) and (3,12) all have towers 
# step 4: add helper - find paths in a given column
towers = {}
def findStartPosition(sp, h, l)
    pos = sp[0]
    x = pos[:x]
    y = pos[:y]
    for i in 0..h-1
        if l[i][x] == '.' and i != y
          sp << { :x=>x, :y=>i }
        end
    end
    sp
end

def add_tower(towers, x, y)
    if towers[x].nil?
        towers[x]={}
    end
    if towers[x][y].nil? 
        towers[x][y] = true
    end
    towers
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

def in_bounds(x,y)
    return x >= 0 && x < 17 && y >= 0 && x < 17
end
counter = 0
# game loop
loop do
  my_money, my_lives = gets.split(" ").collect { |x| x.to_i }
  opponent_money, opponent_lives = gets.split(" ").collect { |x| x.to_i }
  tower_count = gets.to_i
  tower_count.times do
    tower_type, tower_id, owner, x, y, damage, attack_range, reload, cool_down = gets.split(" ")
    if owner.to_s == player_id.to_s
        STDERR.puts "tower id is #{tower_id}"
    end
    tower_id = tower_id.to_i
    owner = owner.to_i
    x = x.to_i
    y = y.to_i
    damage = damage.to_i
    attack_range = attack_range.to_f
    reload = reload.to_i
    cool_down = cool_down.to_i
  end
  attacker_count = gets.to_i
  attacker_count.times do
    attacker_id, owner, x, y, hit_points, max_hit_points, current_speed, max_speed, slow_time, bounty = gets.split(" ")
    attacker_id = attacker_id.to_i
    if (owner.to_s == player_id.to_s and !startPositionFound)
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

  offset = counter % 4
  counter += 1
  STDERR.puts "offset is #{offset}"
  # round 1 grab the center
  center = 8
  paths = find_paths(center, lines)
  STDERR.puts "paths is #{paths}"
  if startPositionFound
    nx = startPositions[0][:x]
    ny = startPositions[0][:y]
    STDERR.puts "ny before is #{ny}"
    STDERR.puts "nx before is #{nx}"
    case offset
    when 0
      if ny < 17
        ny += 1
      end
    when 1
      if nx < 17
        nx += 1
      end
    when 2
      if nx > 0
        nx -= 1
      end
    else
      if ny > 0
        ny -= 1
      end
    end
    if (lines[ny][nx] == '#')
      towers = add_tower(towers, nx, ny)
    else 
      puts "PASS"
    end
  else
    puts "PASS"
  end
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  # step 2: build a fortress around start position
  # we expect 2 towers to be built
end


# # # # # # # # # # # # # # # # #
# 0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0 x == 8 is midpoint 