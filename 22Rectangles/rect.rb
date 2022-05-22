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
points.each do |po|
  x1 = po[:x] # p seems to be reserved? - yes p is a method like "puts"
  y1 = po[:y]
  points.each do |q|
    x2 = q[:x]
    y2 = q[:y]
    if (x2 == x1) || (y2 == y1)
      next 
    end

    # now check if it is a square 
    if (x2 - x1) == (y2 - y1) 
      sq_count += 1
    end
  end
end

# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts sq_count
