# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = gets.to_i
lines = []
count = 0
n.times do
  operation, arg_1, arg_2 = gets.split(" ")
  asInt = 0
  asInt2 = 0
  if arg_1[0] == '$'
      rem = arg_1[1..]
      idx = rem.to_i
      asInt = lines[idx]
  else 
     asInt = arg_1.to_i
  end
  if arg_2[0] == '$'
    rem = arg_2[1..]
    idx = rem.to_i
    asInt2 = lines[idx]
  elsif arg_2[0] == '_'
    asInt2 = 0
  else 
    asInt2 = arg_2.to_i
  end
  case operation
  when "VALUE"
    lines[count] = asInt
  when "ADD"
    lines[count] = asInt + asInt2
  when "SUB"
    lines[count] = asInt - asInt2
  when "MULT"
    lines[count] = asInt * asInt2
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
