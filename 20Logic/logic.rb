# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# _ == 0
# - == 1
def do_logic(operator,a,b)
    case operator
    when 'AND'
        return (a=='-' && b=='-') ? '-' : '_'
    when 'OR'
        return (a=='-' || b =='-') ? '-' : '_'
    when 'XOR'
        return (a!=b) ? '-' : '_'
    when 'NAND'
        return !(a=='-' && b=='-') ? '-' : '_' # TODO: extract
    when 'NOR'
        return !(a=='-' || b =='-') ? '-' : '_' # TODO: dry 
    #when 'NXOR'
    else
        return (a==b) ? '-' : '_'
    end
end

n = gets.to_i
m = gets.to_i
n.times do
  input_name, input_signal = gets.split(" ")
end
m.times do
  output_name, type, input_name_1, input_name_2 = gets.split(" ")
end
m.times do

  # Write an answer using puts
  # To debug: STDERR.puts "Debug messages..."

  puts "output name and signal"
end
