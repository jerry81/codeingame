STDOUT.sync = true # DO NOT REMOVE
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = gets.split(" ").collect { |x| x.to_i }
n = gets.to_i # maximum number of turns before game over.
x0, y0 = gets.split(" ").collect { |x| x.to_i }
# game loop
loop do
  bomb_dir = gets.chomp # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
  # gets - get user input
  # chomp - removes whitespace 
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  case bomb_dir
  when "U"
    y0 -= 1
  when "UR"
    y0-=1
    x0+=1
  when "R"
    x0+=1
  when "DR"
    y0+=1
    x0+=1
  when "D"
    y0+=1
  when "DL"
    y0+=1
    x0-=1
  when "L"
    x0-=1
  else
    y0-=1
    x0-=1
  end
  puts "#{x0} #{y0}"
  # the location of the next window Batman should jump to.
  
end
