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

# apply ceaser first 
as_arr = message.split('')
out_arr = []
as_arr.each_with_index do |x,i|
    shift = (pseudo_random_number+$counter) % 26
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
# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts "#{out_arr.join('')}"
