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

next_token = string.gmatch(io.read(), "[^%s]+")
H = tonumber(next_token())
W = tonumber(next_token())
for i=0,H-1 do
    line = io.read()
end

-- simulation approach
-- just lay down the rules and iterate until end condition

-- math approach
-- do an O(1) calculation - not equipped to do this yet

-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print("timesteps")