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

  if (slots * 12) > target then
    return 0
  end
end

n = tonumber(io.read())
alloptions = { 1: 1 }
for i=1,12 do
  for j=1,2 do
    alloptions.insert(i)
  end
end

for k,v in ipairs(alloptions) do
  io.stderr:write("v"..v..",")
end

print("answer")