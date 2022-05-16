# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

maps = []
w, h = gets.split(" ").collect { |x| x.to_i }
start_row, start_col = gets.split(" ").collect { |x| x.to_i }
n = gets.to_i
n.times do
  map = []
  h.times do
    map_row = gets.chomp
    map << map_row
  end
  maps << map 
end
$sy = start_row
$sx = start_col
STDERR.puts "maps are #{maps}"

def find_path_len(m) 
  cx = $sy
  cy = $sx
  next_pos = m[cy][cx]
  count = 0
  while ['>', '^', 'v', '<'].include?(next_pos)
    case next_pos 
    when '>'
      cx += 1
    when '^'
      cy -= 1
    when 'v'
      cy += 1
    when '<'
      cx -=1 
    end
    count += 1
    next_pos = m[cy][cx]
  end
  next_pos == 'T' ? count : nil 
end

m_c = 400
output = 'TRAP'
maps.each_with_index do |x, i| 
  count = find_path_len(x)
  STDERR.puts "count is #{count} idx is #{i}"
  if !count.nil? && count < m_c 
    m_c = count
    output = i.to_s
  end
end
# Write an answer using puts
# To debug: STDERR.puts "Debug messages..."

puts output
