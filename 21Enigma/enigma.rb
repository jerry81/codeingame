# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

$counter = 0 
$idx_lookup = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.split('')
$rotors = []

operation = gets.chomp
pseudo_random_number = gets.to_i
3.times do |i| # times can accept an arg 
  rotor = gets.chomp
  $rotors[i] = rotor.split('')
end
message = gets.chomp
as_arr = message.split('')
out_arr = []
# apply ceaser first 
if operation == "ENCODE"
  as_arr.each_with_index do |x,i|
      cur_idx = $idx_lookup.find_index(x)
      shift = (pseudo_random_number+$counter+cur_idx) % 26
      STDERR.puts "shift is #{shift}"
      $counter+=1
      out_arr << $idx_lookup[shift]
  end
  $rotors.each do |r|
      temp = []
      out_arr.each do |c| 
          idx = $idx_lookup.find_index(c)
          temp << r[idx]
      end
      out_arr = temp 
  end
else  # TODO: DRY 
  $rotors.reverse!.each do |r|
      temp = []
      as_arr.each do |c| 
          idx = r.find_index(c)
          temp << $idx_lookup[idx]
      end
      as_arr = temp 
  end
  as_arr.each_with_index do |x,i|
    cur_idx = $idx_lookup.find_index(x)
    shift = cur_idx-pseudo_random_number-$counter
    if shift < 0 
        shift = 26 + shift
    end
    STDERR.puts "shift is #{shift}"
    $counter+=1
    out_arr << $idx_lookup[shift]
  end
end
# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts "#{out_arr.join('')}"
