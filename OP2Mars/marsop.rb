STDOUT.sync = true # DO NOT REMOVE
# Save the Planet.
# Use less Fossil Fuel.

n = gets.to_i # the number of points used to draw the surface of Mars.

# first find flat land
longestFlatX = 0
longestFlatY = 0
longest = 0
curLen = 0
curX = -1
curY = -1
curFX = 0
curFY=0
n.times do
  # land_x: X coordinate of a surface point. (0 to 6999)
  # land_y: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
  land_x, land_y = gets.split(" ").collect { |x| x.to_i }
  if curX == -1
    curX = land_x
    curY = land_y
  else
    if curY == land_y
        curLen += 1
        if curLen > longest
            longestFlatY = longestFlatY
            longestFlatX = curFX
        end
    else
        curFX = land_x 
        curFY = land_y
    end
    curX = land_x 
    curY = land_y
  end
end

# game loop
loop do
  # hs: the horizontal speed (in m/s), can be negative.
  # vs: the vertical speed (in m/s), can be negative.
  # f: the quantity of remaining fuel in liters.
  # r: the rotation angle in degrees (-90 to 90).
  # p: the thrust power (0 to 4).
  x, y, hs, vs, f, r, p = gets.split(" ").collect { |x| x.to_i }

  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."


  # R P. R is the desired rotation angle. P is the desired thrust power.
  puts "-20 3"
end
