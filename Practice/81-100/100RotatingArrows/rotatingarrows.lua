--[[

A contribution by Mortis_666
 Approved by Westicles,ByteWolfandradioctiv
 	Goal
A W x H grid is filled with arrows, each arrow will point to any one direction (UP, DOWN, RIGHT or LEFT).
You can know which direction the arrow is pointing to by knowing its ascii image,
^, >, v, < represent UP, RIGHT, DOWN and LEFT.

You can rotate an arrow clockwise, for example: ^ after rotation will become >.
After you rotate the arrow, the other arrow that the arrow is pointing at will start rotating clockwise too, this process continues until the last rotated arrow points back to the first arrow you rotate or the last rotated arrow points to the edge of the grid.

After you rotated the arrow at position (x, y), how many times of rotation will occur?
(Index starts with 0)

For example:
W=2, H=2
x=0, y=0

Grid:
^>
<v

First we start at the arrow at position (0, 0), after rotating the arrow clockwise, the arrow now points to the right. New grid:
>>
<v

Now we rotate the arrow at (1, 0), and it will now point down, and we now rotate the arrow at (1, 1), and the arrow will point to the left. Next, we rotate the arrow at (0, 1), and the arrow will point to up, which is the arrow at (0, 0).

The arrow points back to the first arrow you rotate! So the result is 4, 4 rotation occurs!
Input
Line 1: Two integers W and H
Line 2: Two integers x and y
Next H lines: A line with W arrows represented by ascii char ^v<>
Output
The number of rotation times
Constraints
1 ≤ W, H ≤ 10
0 ≤ x < W
0 ≤ y < H
Example
Input
2 1
0 0
^v
Output
2

]]--


next_token = string.gmatch(io.read(), "[^%s]+")
W = tonumber(next_token())
H = tonumber(next_token())
next_token = string.gmatch(io.read(), "[^%s]+")
x = tonumber(next_token())
y = tonumber(next_token())
grid = {}


for i=0,H-1 do
    table.insert(grid,{})
    line = io.read() -- The line of w arrows represented by ascii char ^v<>
    for j=1,#line do
      table.insert(grid[i+1], string.sub(line,j,j))
    end
end

count = 0

X_ORIGINAL = x+1
Y_ORIGINAL = y+1

function getnext(x,y)
  local nx, ny =  nil, nil
  current_arrow = grid[y][x]
  if current_arrow == '<' then
    grid[y][x] = '^'
    if (y-1) < 1 then return -1,-1 end

    nx = x
    ny = y-1
  elseif current_arrow == '>' then
    grid[y][x] = 'v'
    if (y+1) > H then return -1,-1 end

    nx = x
    ny = y+1
  elseif current_arrow == 'v' then
    grid[y][x] = '<'
    if (x-1) < 1 then return -1,-1 end

    nx = x-1
    ny = y
  else
    -- turn the arrow, set nextx, nexty
    grid[y][x] = '>'
    if (x+1) > W then return -1,-1 end

    nx = x+1
    ny = y
  end
  if nx == X_ORIGINAL and Y_ORIGINAL == ny then return -1,-1 end

  return nx,ny
end


nextx, nexty = X_ORIGINAL, Y_ORIGINAL
repeat
  count = count+1
  nextx,nexty = getnext(nextx,nexty)
until (nextx < 0)

print(count)