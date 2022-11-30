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
function p()
    io.stderr:write("lines\n")
    for i,v in ipairs(lines) do
        io.stderr:write(i)
        io.stderr:write("\n")
        io.stderr:write(v)
        io.stderr:write("\n")
    end
    io.stderr:write("arrowsy size\n")
    sy = #arrowsy
    io.stderr:write(sy)
    io.stderr:write("\n")
    for k,v in pairs(arrowsy) do
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
p()


-- simulation approach
-- just lay down the rules and iterate until end condition

-- math approach
-- do an O(1) calculation - not equipped to do this yet

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print("timesteps")