# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w, h, t1, t2, t3 = gets.split(" ").collect { |x| x.to_i }
# w width
# h height
# t1 time 1 
# t2 time 2
# t3 time 3
# output the picture 
# store the first picture
p1 = []
p2 = []
# store the second picture 
h.times do
  first_picture_row, second_picture_row = gets.split(" ")
  p1 << first_picture_row
  p2 << second_picture_row 
end
STDERR.puts "p1 #{p1}"
STDERR.puts "p2 #{p2}"

# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts "answer"