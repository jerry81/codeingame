STDOUT.sync = true # DO NOT REMOVE
# Don't let the machines win. You are humanity's last hope...

width = gets.to_i # the number of cells on the X axis
height = gets.to_i # the number of cells on the Y axis

grid = []
nodes = []
STDERR.puts "height #{height} width #{width}"
for j in 0..height-1 do
  line = gets.chomp # width characters, each either 0 or .
  grid[j] = []
  for i in 0..width-1 do
    STDERR.puts "loop #{line[i]}"
    grid[j][i] = line[i]
    if line[i] == '0'
      nodes << { :x => i, :y => j }
    end
  end
end
STDERR.puts "i am out"
STDERR.puts "grid #{grid} nodes #{nodes}"
# Write an action using puts
# To debug: STDERR.puts "Debug messages..."


# Three coordinates: a node, its right neighbor, its bottom neighbor

nodes.each do | node |
    x = node[:x]
    y = node[:y]
    rightX = x < width - 1 ? x+1 : -1
    rightY = x < width - 1 ? y : -1
    downX = y < height - 1 ? x : -1
    downY = y < height - 1 ? y+1 : -1
    if rightX > 0 
        right = grid[rightX, rightY]
        if right == '.'
            rightX = -1
            rightY = -1
        end
    end
    if downY > 0
        down = grid[rightX, rightY]
        if down == '.'
           downX = -1
           downY = -1
        end
    end
    puts "#{x} #{y} #{rightX} #{rightY} #{downX} #{downY}"
end
