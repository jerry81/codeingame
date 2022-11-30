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
end

ARROWS = {['>']="x+1", ['^']="y-1", ['v']="y+1", ['<']="x-1"}

function analyze()
    for i,v in ipairs(lines) do
        io.stderr:write(i)
        io.stderr:write("\n")
        io.stderr:write(v)
        io.stderr:write("\n")
        for ii=1,#v do
            c = v:sub(ii,ii)
            if ARROWS[c] ~= nil then
                io.stderr:write("arrow found at \n")
                io.stderr:write(i)
                io.stderr:write(",")
                io.stderr:write(ii)
                io.stderr:write("\n")
            end
            io.stderr:write(ii)
            io.stderr:write("\n")
            io.stderr:write(v:sub(ii,ii))
            io.stderr:write("\n")
        end
    end
end

next_token = string.gmatch(io.read(), "[^%s]+")
H = tonumber(next_token())
W = tonumber(next_token())
lines = {}
arrows = {}
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