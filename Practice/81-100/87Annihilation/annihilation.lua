--[[
Goal
Starting with an HxW grid at t=0, at each time step the arrows ^v<> move one space up/down/left/right respectively (wrapping around if they go off the edge). After each time step, if two or more arrows are in the same position they are all destroyed. How many time steps does it take until there are no arrows remaining?
Input
Line 1: H W
Next H lines: The grid values.
Output
The number of time steps until there are no arrows remaining.
Constraints
4 ≤ H,W ≤ 50
Example
Input
5 5
.....
..v..
.>.<.
..^..
.....
Output
1
]]--

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.
function p(arrowmap)
    io.stderr:write("nil count test \n") --- ugh! we found out that we have to manage non-integer counts ourselves
    test = {a=nil, b=nil, c="ya"}
    if next(test) then
        io.stderr:write("test yes\n")
    end

    test2 = {a=nil}
    if not next(test2) then
        io.stderr:write("test2 yes\n")
    end

    io.stderr:write("lines\n")
    for i,v in ipairs(lines) do
        io.stderr:write(i)
        io.stderr:write("\n")
        io.stderr:write(v)
        io.stderr:write("\n")
    end
    io.stderr:write("arrowsy size\n")
    sy = #arrowmap
    io.stderr:write(sy)
    io.stderr:write("\n")
    for k,v in pairs(arrowmap) do
        io.stderr:write("key\n")
        io.stderr:write(k)
        io.stderr:write("\n")
        for kk,vv in pairs(v) do
            io.stderr:write("key2\n")
            io.stderr:write(kk)
            io.stderr:write("\n")
            io.stderr:write("value\n")
            io.stderr:write(vv)
            io.stderr:write("\n")
        end
    end
end

ARROWS = {['>']="x+1", ['^']="y-1", ['v']="y+1", ['<']="x-1"}

function analyze()
    for i,v in ipairs(lines) do
        for ii=1,#v do
            c = v:sub(ii,ii)
            if ARROWS[c] ~= nil then
                arrowsy[i] = arrowsy[i] or {}
                arrowsy[i][ii] = c
            end
        end
    end
end

function nextPosition(c,x,y)
  uy = y > 1 and y-1 or H
  dy = y < H and y+1 or 1
  rx = x < W and x+1 or 1
  lx = x > 1 and x-1 or W
  if c == '>' then return { x=rx, y=y } end
  if c == '<' then return { x=lx, y=y } end
  if c == 'v' then return { x=x, y=dy } end
  if c == '^' then return { x=x, y=uy } end
end

next_token = string.gmatch(io.read(), "[^%s]+")
H = tonumber(next_token())
W = tonumber(next_token())
lines = {}
arrowsy = { }
for i=0,H-1 do
    line = io.read()
    table.insert(lines,line)
end

analyze()
p(arrowsy)
count = 0
while next(arrowsy) do
    count = count+1
    newPositions = {}
    io.stderr:write("arrowsy\n")
    for y,ax in pairs(arrowsy) do
        for x,c in pairs(ax) do
            io.stderr:write("update position for \n")
            io.stderr:write(y)
            io.stderr:write(",")
            io.stderr:write(x)
            io.stderr:write(" with value\n")
            io.stderr:write(c)
            io.stderr:write("\n")
            nxt = nextPosition(c,x,y)
            newPositions[nxt.y] = newPositions[nxt.y] or {}
            newPositions[nxt.y][nxt.x] = 'delete' or c
        end
    end
    for y,v in pairs(newPositions) do
        for x,vv in pairs(v) do
            if vv == 'delete' then
                newPositions[y][x] = nil
            end
        end
        if not next(newPositions[y]) then
            newPositions[y] = nil
        end
    end
    arrowsy = newPositions
end

-- simulation approach
-- just lay down the rules and iterate until end condition

-- math approach
-- do an O(1) calculation - not equipped to do this yet

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print(count)