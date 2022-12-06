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

lookup = {["P1"]=1}
for i = 2,12 do
  lookup[tostring(i)] = i;
  lookup["P"..i] = i
end

for i,v in pairs(lookup) do
  io.stderr:write("i is "..i.." and ")
  io.stderr:write("v is "..v)
  io.stderr:write("\n")
end

function permute_four_slots(limit)
  results = {}
  cur = {}
  for i=1,9 do
    sum1 = i
    for j=1,9 do
      sum2=sum1+j
      for k=1,9 do
        sum3=sum2+k
        for l=1,9 do
          sum4=sum3+l
          --io.stderr:write("sum"..sum.."\n")
          if sum4 == limit then
            results[i..j..k..l]=true
          end
        end
      end
    end
  end
  return results
end

function permute_three_slots(limit)
  results = {}
  cur = {}
  for j=1,9 do
      sum2=j
      for k=1,9 do
        sum3=sum2+k
        for l=1,9 do
          sum4=sum3+l
          --io.stderr:write("sum"..sum.."\n")
          if sum4 == limit then
            results[j..k..l]=true
          end
        end
      end
    end
  return results
end

function permute_two_slots(limit)
  results = {}
  cur = {}
      for k=1,9 do
        sum3=k
        for l=1,9 do
          sum4=sum3+l
          --io.stderr:write("sum"..sum.."\n")
          if sum4 == limit then
            results[j..k..l]=true
          end
        end
      end
  return results
end

res = permute_four_slots(5)

for i,v in pairs(res) do
  io.stderr:write('results iteration\n')
  io.stderr:write("i "..i.."\n")
end

res = permute_three_slots(5)

for i,v in pairs(res) do
  io.stderr:write('results iteration 2 \n')
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

print("answer")

--[[

review: combinations and permutations

permutation - order matters
combination - order does not matter

- permutation formula: choose r things from set of n things WITHOUT REPLACMENT - not this problem
n! / (n-r)!

- combination - choose r from n without replacement - order doesn't matter
n!/r!(n-r)!

]]--