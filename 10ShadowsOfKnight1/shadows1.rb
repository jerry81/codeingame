STDOUT.sync = true # DO NOT REMOVE
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = gets.split(" ").collect { |x| x.to_i }
n = gets.to_i # maximum number of turns before game over.
x0, y0 = gets.split(" ").collect { |x| x.to_i }
lbound = 0
ubound = 0
rbound = w-1
dbound = h-1
# game loop
loop do
  bomb_dir = gets.chomp # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
  # gets - get user input
  # chomp - removes whitespace 
  # Write an action using puts
  # To debug: STDERR.puts "Debug messages..."
  case bomb_dir
  when "U"
    dbound = y0 - 1
    y0 = (ubound + dbound) / 2
  when "UR"
    dbound = y0 - 1
    y0 = (ubound + dbound) / 2
    lbound = x0 + 1
    x0 = (lbound + rbound) / 2
  when "R"
    lbound = x0 + 1
    x0 = (lbound + rbound) / 2
  when "DR"
    ubound = y0 - 1
    y0 = (ubound + dbound) / 2
    lbound = x0 + 1
    x0 = (lbound + rbound) / 2
  when "D"
    STDERR.puts "ubound is #{ubound}"
    ubound = y0 + 1
    y0 = (ubound + dbound) / 2
  when "DL"
    ubound = y0 + 1
    y0 = (ubound + dbound) / 2
    rbound = x0 - 1
    x0 = (lbound + rbound) / 2
  when "L"
    rbound = x0 - 1
    x0 = (lbound + rbound) / 2
  else
    dbound = y0 - 1
    y0 = (ubound + dbound) / 2
    rbound = x0 - 1
    x0 = (lbound + rbound) / 2
  end
  puts "#{x0} #{y0}"
  # the location of the next window Batman should jump to.
  
end
