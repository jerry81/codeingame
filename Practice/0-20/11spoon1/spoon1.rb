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

nodes.each do |node|
    x = node[:x]
    STDERR.puts "x is #{x}"
    y = node[:y]
    rx = -1
    ry = -1
    dx = -1
    dy = -1 
    cx = x + 1
    cy = y + 1
    while cx < width do
        cn = grid[y][cx]
        if cn == '0'
            rx = cx
            ry = y
            break
        end
        cx += 1
    end
    while cy < height do
        cn = grid[cy][x]
        if cn == '0'
           dy = cy
           dx = x
           break
        end
        cy += 1
    end
    puts "#{x} #{y} #{rx} #{ry} #{dx} #{dy}"
end
