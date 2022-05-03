# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = gets.to_i
lines = []
count = 0
n.times do
  operation, arg_1, arg_2 = gets.split(" ")
  case operation
  when "VALUE"
    if arg_1[0] == '$'
        STDERR.puts "var hit"
    end
    lines[count] = arg_1
  when "ADD"
    if arg_1[0] == '$'
        STDERR.puts "var hit"
    end
    lines[count] = arg_1 + arg_2
  when "SUB"
    if arg_1[0] == '$'
        STDERR.puts "var hit"
    end
    lines[count] = arg_1 - arg_2
  when "MULT"
    if arg_1[0] == '$'
        STDERR.puts "var hit"
    end
    lines[count] = arg_1 * arg2
  end
  count += 1
end
count = 0
n.times do
  puts "#{lines[count]}"
  # Write an answer using puts
  # To debug: STDERR.puts "Debug messages..."
  
  count += 1
end
