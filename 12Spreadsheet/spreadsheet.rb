# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = gets.to_i
lines = []
count = 0
# tests did not pass because i did not consider backwards dependencies
# we cannot resolve all dependencies with a single pass thru while reading in the lines for the first time.
dependencies = {}
original = []
def getValue(operation, arg_1, arg_2, lines, count, dependencies)
  asInt = 0
  asInt2 = 0
  if arg_1[0] == '$'
      rem = arg_1[1..]
      idx = rem.to_i
      asInt = lines[idx]
      if asInt.nil?
        if dependencies[count].nil?
            dependencies[count] = []
        end
        dependencies[count] << idx 
      end
  else 
     asInt = arg_1.to_i
  end
  if arg_2[0] == '$'
    rem = arg_2[1..]
    idx = rem.to_i
    asInt2 = lines[idx]
    if asInt2.nil?
        if dependencies[count].nil?
            dependencies[count] = []
        end
        dependencies[count] << idx
    end
  elsif arg_2[0] == '_'
    asInt2 = 0
  else 
    asInt2 = arg_2.to_i
  end
  if (asInt.nil? || asInt2.nil?)
    return nil
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
end

n.times do
  operation, arg_1, arg_2 = gets.split(" ")
  original << [operation, arg_1, arg_2]
  val = getValue(operation,arg_1,arg_2,lines,count,dependencies)
  count += 1
end
STDERR.puts " original #{original}"
STDERR.puts " dep #{dependencies}"
STDERR.puts " lines #{lines}"

def recalcDependency(dependencies, lines, original)
  dependencies.each do |k,v|
    STDERR.puts "k #{k} v #{v}"
    v.each do |d|
        if lines[d]
            oline = original[k]
            newVal = getValue(oline[0], oline[1], oline[2], lines, k, dependencies)
        end
    end
  end
end

recalcDependency(dependencies, lines, original)

count = 0
n.times do
  puts "#{lines[count]}"
  # Write an answer using puts
  # To debug: STDERR.puts "Debug messages..."
  count += 1
end
