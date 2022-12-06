--[[

Goal
In recent years a very old game has become more and more famous: Mölkky. It is an authentic Finnish game that combines skill and luck. The goal is simple. Players must throw a wooden cylinder called Mölkky, in order to knock down the pin group (consisted of 12 pins numbered from 1 to 12) located 3 or 4 meters from the pitcher to score points and reach exactly 50 points.

Points are scored in this way:
- If a player knocks down only one pin, he scores the number of points marked on that pin.
- If a player knocks down more than one pin, he scores the number of pins knocked down (the numbers marked on the pins become irrelevant).

The purpose of this puzzle is to know how many possibilities there are to make 50 points from an initial score in 4 rounds or fewer.

We count only those possibilities which do not exceed 4 rounds, otherwise, the player would take too long to succeed and risk losing the game.

Also, we count only those possibilities where in each round at least 1 pin is knocked down, that is, at least 1 point is scored.

Example

When P is placed in front of a number, it means that only one pin is knocked down and the number following the letter P is the number marked on the pin. On the contrary when the number is not accompanied it means the number of pins knocked down. The spaces separate the rounds. Before each round, all pins are put back in place.

If we start from a score of 47 then the possibilities are:
P1 P1 P1
P2 P1
P1 P2
2  P1
P1 2
P3
3

There are 7 possibilities.
Input
An integer N that matches the initial score.
Output
An integer corresponding to the number of possibilities to reach 50 from the initial score in 4 rounds or fewer.
Constraints
0 ≤ N ≤ 49
Example
Input
47
Output
7

]]--

--[[
brute force it
make the whole set
2,3,4,5,6,7,8,..12, P1,...P12
- map P1-P12 to values
- make function to convert a "permutaton" into sum
- get all permutations with repeats for 1-4 digits
- dedup permutations
- convert all into sums
- filter the sums

]]--

--[[
easier brute force?
loop x 4
1 to 23
  1 to 23
    1 to 23
      1 to 23
]]--

lookup={'1'}
for i=2,12 do
  table.insert(lookup,tostring(i))
  table.insert(lookup,"p"..i)
end

valmap={}

for _,v in ipairs(lookup) do
  if string.find(v, "p") then
    valmap[v]=tonumber(string.sub(v,2))
  else
    valmap[v]=tonumber(v)
  end
end


function generic_permute(target, accum, limit, sum, results)
  if limit == 0 then
    if sum==target then
      if results[accum]
      results[accum] = true
    end
    return
  end
  for i=1,23 do
    nextv = valmap[lookup[i]]
    generic_permute(target, accum..lookup[i], limit-1, sum+nextv, results)
  end
end


res={}
generic_permute(5, "", 4, 0, res)

for i,v in pairs(res) do
  io.stderr:write('results iteration\n')
  io.stderr:write("i "..i.."\n")
end

res2={}
generic_permute(5, "", 3, 0, res2)

for i,v in pairs(res2) do
  io.stderr:write('results iteration 2\n')
  io.stderr:write("i "..i.."\n")
end

function count_sums(target, slots)
  if slots==1 then
    if target == 1 then
      return 1
    elseif target < 13 then
      return 2
    else
      return 0
    end
  end

  if (slots * 12) < target then
    return 0
  end
end

n = tonumber(io.read())

target = 50 - n

io.stderr:write("target is "..target.."\n")


count = 0

for i=1,4 do
  res = {}
  generic_permute(target, "", i, 0, res)
  for _,_ in pairs(res) do
    count++
  end  -- same ol gotcha: "#" for count only counts int indexes
end

print(count)

--[[

review: combinations and permutations

permutation - order matters
combination - order does not matter

- permutation formula: choose r things from set of n things WITHOUT REPLACMENT - not this problem
n! / (n-r)!

- combination - choose r from n without replacement - order doesn't matter
n!/r!(n-r)!

]]--