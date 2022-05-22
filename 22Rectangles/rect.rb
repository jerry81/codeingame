# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w, h, count_x, count_y = gets.split(" ").collect { |x| x.to_i }
inputs = gets.split(" ")
xs = [0,w]
ys = [0,h]
for i in 0..(count_x-1)
  x = inputs[i].to_i
  xs << x
end
inputs = gets.split(" ")
for i in 0..(count_y-1)
  y = inputs[i].to_i
  ys << y 
end
points = []
xs.each do |i| 
  ys.each do |j|
    points << {:x => i, :y => j}
  end
end
STDERR.puts "points are #{points}"
STDERR.puts "12 is #{points.size}"
sq_count = 0 
memox = {}
memoy = {}
points.each_with_index do |po,i|
  x1 = po[:x] # p seems to be reserved? - yes p is a method like "puts"
  y1 = po[:y]
  if memox[x1].nil? 
    memox[x1] = {}
  end

  if memoy[y1].nil? 
    memoy[y1] = {}
  end

  sl = points[i..]
  sl.each do |q|
    x2 = q[:x]
    y2 = q[:y]
    
    if (x2 == x1) || (y2 == y1)
      next 
    end

    if memox[x1][x2].nil?
      memox[x1][x2] = x2-x1
    end

    if memoy[y1][y2].nil?
      memoy[y1][y2] = y2-y1 
    end
    # now check if it is a square 
    if (memox[x1][x2]) == (memoy[y1][y2]) 
      sq_count += 1
    end
  end
end

# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts sq_count
