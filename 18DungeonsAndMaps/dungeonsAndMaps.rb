# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

maps = []
w, h = gets.split(" ").collect { |x| x.to_i }
start_row, start_col = gets.split(" ").collect { |x| x.to_i }
n = gets.to_i
n.times do
  map = []
  h.times do
    map_row = gets.chomp
    map << map_row
  end
  maps << map 
end

STDERR.puts "maps are #{maps}"
# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts "mapIndex"
