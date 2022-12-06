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

lookup={'n1'}
for i=2,12 do
  table.insert(lookup,"n"..i)
  table.insert(lookup,"p"..i)
end

valmap={}

for _,v in ipairs(lookup) do
    valmap[v]=tonumber(string.sub(v,2))
end


function generic_permute(target, accum, limit, sum, results)
  if limit == 0 then
    if sum==target then
      results[accum] = true
    end
    return
  end
  for i=1,23 do
    nextv = valmap[lookup[i]]
    generic_permute(target, accum..lookup[i], limit-1, sum+nextv, results)
  end
end

n = tonumber(io.read())

target = 50 - n

count = 0

for i=1,4 do
  subcount = 0
  res = {}
  generic_permute(target, "", i, 0, res)
  for i,v in pairs(res) do
    subcount=subcount+1
  end  -- same ol gotcha: "#" for count only counts int indexes
  count = count + subcount
end

print(count)
