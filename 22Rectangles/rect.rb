# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w, h, count_x, count_y = gets.split(" ").collect { |x| x.to_i }
inputs = gets.split(" ")
xs = [0,w]
ys = [0,y]
for i in 0..(count_x-1)
  x = inputs[i].to_i
  xs << x
end
inputs = gets.split(" ")
for i in 0..(count_y-1)
  y = inputs[i].to_i
  ys << y 
end
STDERR.puts "xs are #{xs}"
STDERR.puts "ys are #{ys}"

# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts "0"
