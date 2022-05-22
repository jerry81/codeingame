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
inputs = {}
n.times do
  input_name, input_signal = gets.split(" ")
  inputs[input_name] = input_signal
end
outputs = {}
m.times do
  output_name, type, input_name_1, input_name_2 = gets.split(" ")
  o = ""
  i1 = inputs[input_name_1].split('')
  i2 = inputs[input_name_2].split('')
  i1.each_with_index do |v,i|
    ch = v
    ch2 = i2[i]
    o << do_logic(type, ch, ch2)
  end
  outputs[output_name] = o
end
STDERR.puts "inputlookup is #{inputs}"
outputs.each do |k,v|

  # Write an answer using puts
  # To debug: STDERR.puts "Debug messages..."

  puts "#{k} #{v}"
end
