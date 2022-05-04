STDOUT.sync = true # DO NOT REMOVE
# Save the Planet.
# Use less Fossil Fuel.

n = gets.to_i # the number of points used to draw the surface of Mars.

# first find flat land
longest = 0
longestx1 = nil
longestx2 = nil
longesty = nil
prevx = nil
prevy = nil
n.times do
  # land_x: X coordinate of a surface point. (0 to 6999)
  # land_y: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
  land_x, land_y = gets.split(" ").collect { |x| x.to_i }
  if !prevx.nil? 
    if land_y == prevy 
        len = land_x - prevx 
        if len > longest
            longest = len 
            longestx1 = prevx 
            longestx2 = land_x
            longesty = land_y
        end
    end
  end
  prevx = land_x 
  prevy = land_y
end

STDERR.puts "longest is #{longest} x is #{longestx1} x2 is #{longestx2} y is #{longesty}"
# game loop

def get_target(x,lx,lx2) 
    # returns L, T, or R
    if x < lx
        return 'R'
    end
    if x > lx2
        return 'L'
    end
    return 'T'
end

STABLE_ANGLE = 30
AGRESSIVE_ANGLE = 40
EXTREME_ANGLE = 50
# step 1 - handle angle 
loop do
  # hs: the horizontal speed (in m/s), can be negative.
  # vs: the vertical speed (in m/s), can be negative.
  # f: the quantity of remaining fuel in liters.
  # r: the rotation angle in degrees (-90 to 90).
  # p: the thrust power (0 to 4).
  x, y, hs, vs, f, r, p = gets.split(" ").collect { |x| x.to_i }
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  distToLanding = y - longesty

  t = get_target(x, longestx1, longestx2)
  angle = 0
  thrust = 4
  distToL = (x - longestx1).abs
  distToR = (x - longestx2).abs
  STDERR.puts "distToL #{distToL}"
  STDERR.puts "distToR #{distToR}"
  STDERR.puts "T is #{t}"
  STDERR.puts "r is #{r}"
  # step 1 - get in range
  if t == 'L'
    if hs < -50
      if distToR < 1000
        angle = -STABLE_ANGLE
      else
        angle = 0
        if vs >= 0 
            thrust = 0
        end
      end
    else 
        angle = STABLE_ANGLE
    end
  elsif t == 'R'
    if hs > 50
        if distToL < 2000
            angle = STABLE_ANGLE
        else
            angle = 0
            if vs >= 0 
                thrust = 0
            end
        end
    else 
        angle = -STABLE_ANGLE
    end
  else
    # step 2 - make hs 0 
    if hs > 5
      angle = AGRESSIVE_ANGLE
    elsif hs < -5
        angle = -AGRESSIVE_ANGLE
    else 
        angle = 0
        # step 3 - freefall/keep speed above -39 
        thrust = vs > -35 ? 0 : 4
    end
  
  
  end
  # most important guards go at the bottom 
  # R P. R is the desired rotation angle. P is the desired thrust power.
  puts "#{angle} #{thrust}"
end
