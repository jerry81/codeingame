--[[
	Goal
A growing number is a number where each digit, from left to right, is greater than or equal to the previous one.

Given a number n, which may or may not be a growing number, you have to find the first growing number > n.

Example:
With n = 19, the first growing number greater than n is 22, because both 20 and 21 have a second digit that is smaller than the first one.

Note: This problem can be solved without converting n to a number.
Input
line 1: a string representing the number n
Output
line 1: the first growing number > n
Constraints
n < 10^19
Example
Input
19
Output
22
]]--

-- Auto-generated code below aims at helping you parse
-- the standard input according to the problem statement.

n = io.read()
io.stderr:write("type is "..type(n).."\n")
function findbreakpoint()
    previous = 0
	for i=1,#n do
		num=tonumber(string.sub(n,i,i))
        if num < previous then
            return i
        end
        previous = num
	end
    return 0
end

breakpoint = findbreakpoint()
io.stderr:write("breakpoint is "..breakpoint.."\n")

function getsuffix(remaining, baseline)
    ret = ""
    for i=1,#remaining do
        c = string.sub(remaining,i,i)
        appended = (tonumber(c) < baseline) and baseline or c
        ret = ret..appended
    end
    return ret
end

function getnextallascending()
    for i=#n,1,-1 do
        local as_n = tonumber(string.sub(n,i,i))

        if as_n ~= 9 then
            io.stderr:write("i is "..i.."\n")
            plusOne = as_n+1
            newstr = i == 1 and "" or string.sub(n,1,i)
            suff = getsuffix(string.sub(n,1,i), plusOne)
            io.stderr:write("suffix is "..suff.."\n")
            return newstr..tostring(plusOne)..suff
        end
    end
end

function getnext(bk)
	if bk==0 then
        return getnextallascending()
    end
end
ans = getnext(breakpoint)
-- Write an answer using print()
-- To debug: io.stderr:write("Debug message\n")

print(ans)