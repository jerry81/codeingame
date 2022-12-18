# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w, h, count_x, count_y = gets.split(" ").collect { |x| x.to_i }
inputs = gets.split(" ")
xs = [0,w]
ys = [0,h]
w_d = {w=>1}
h_d = {h=>1}
# new stategy - 
# make lookup table of widths 
# width: count 
for i in 0..(count_x-1)
  x = inputs[i].to_i
  xs.each do |j|
    diff = (j - x).abs
    if w_d[diff].nil?
      w_d[diff] = 1 
    else 
      w_d[diff] += 1
    end
  end
  xs << x
end
inputs = gets.split(" ")
for i in 0..(count_y-1)
  y = inputs[i].to_i
  ys.each do |j|
    diff = (j - y).abs
    if h_d[diff].nil?
      h_d[diff] = 1 
    else 
      h_d[diff] += 1
    end
  end
  ys << y 
end

sq_count = 0 
h_d.each do |k,v|
  if !w_d[k].nil?
    sq_count += w_d[k] * v 
  end
end
puts sq_count

