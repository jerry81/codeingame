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

function buildstr(len, baseline)
    ret = ""
    for i=1,len do
        ret = ret..baseline
    end
    return ret
end

function buildOnesString(len)
	return buildstr(len,"1")
end


function getnextallascending()
    for i=#n,1,-1 do
        local as_n = tonumber(string.sub(n,i,i))

        if as_n ~= 9 then -- code smell - nesting (extract)
            plusOne = as_n+1
            newstr = i == 1 and "" or string.sub(n,1,i-1)
            suff = buildstr(#n-i+1, plusOne)
            return newstr..suff
        end
    end

    len = #n+1
    return buildOnesString(len)

end

function getsuffixhappy(prev, bk)
    len = #n - bk + 1
    ret = {}
    for _=1,len do
        table.insert(ret, tostring(prev))
    end
    return table.concat(ret, "")
end

function getnexthappy(bk)
  prev = string.sub(n,bk-1,bk-1)
  return string.sub(n,1,bk-1)..getsuffixhappy(prev, bk)
end

function getnext(bk)
	if bk==0 then
        return getnextallascending()
    end

    return getnexthappy(bk)
end
if (#n == 1 and n ~= "9") then
    print(tonumber(n)+1)
    return
end

if n=="0" then
	print(1)
	return
end
ans = getnext(breakpoint)

print(ans)