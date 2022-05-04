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

def limiths(hs, t, close)
    angle = 0
    case t 
    when 'L' 
        angle = 45
    when 'R'
        angle = -45
    end
    if close 
      if hs > 45
        angle = 45
      elsif hs > 25 
        angle = 45
      elsif hs < -45
        angle = -45
      elsif hs < -25
        angle = -45
      end
    end
    if hs > 50
        angle = 45
    elsif hs < -50
        angle = -45
    end
    angle 
end

def limitv(originalAngle, vs, close)
    ret = originalAngle 
    if vs < -50 && close
        ret = 0
    end
    ret
end

def limitt(vs, close)
    ret = 4
    if vs < -40 && close
        ret = 4
    end
    if vs > 37 && close
        ret = 3
    end
    ret
end
# step 1 - handle angle 
loop do
  # hs: the horizontal speed (in m/s), can be negative.
  # vs: the vertical speed (in m/s), can be negative.
  # f: the quantity of remaining fuel in liters.
  # r: the rotation angle in degrees (-90 to 90).
  # p: the thrust power (0 to 4).
  x, y, hs, vs, f, r, p = gets.split(" ").collect { |x| x.to_i }
  STDERR.puts "gettarget"
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  distToLanding = y - longesty
  t = get_target(x, longestx1, longestx2)
  STDERR.puts "gettarget #{t}"
  
  angle = 0
  thrust = 4
  close = distToLanding < 2000
  angle = limiths(hs, t, close)

  angle = limitv(angle, vs, close)
  thrust = limitt(vs, close)
  STDERR.puts "angle is #{angle}"
  
  # most important guards go at the bottom 
  # R P. R is the desired rotation angle. P is the desired thrust power.
  puts "#{angle} #{thrust}"
end
