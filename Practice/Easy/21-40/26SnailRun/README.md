	Goal
We have a snail race we will have to determine the winner !
-You have a number of snails given to you in the numberSnails
- Each snail has a speed given to you in the variable speedSnail
- You have a map of the game with a mapHeight and mapWidth

on the map we have:
number that represents a snail from 1 to numberSnails
* which represents a place where you can go
# which represents the destination

Snails can go right, left, up, down. Snails cannot go diagonally.
the snail takes the path closest to it.


exemple of the game :

snail 1 speed 2
snail 2 speed 1

start :

1****#
2****#

time = 1

**1**#
*2***#

time = 2

****1#
**2**#

time=3

*****1
***2*#

End :

return 1

For each race there is only one winner
Input
Line 1: An integer numberSnails for the number of snails.
Next numberSnails lines: An integer speedSnail for the speed of a snail.
Next line: An integer mapHeight which is the height of the map.
Next line: An integer mapWidth which is the width of the map.
Next mapHeight lines: A string ROW for one line of the map.
Output
a number that represents the winner of the race
Constraints
2<numberSnails<6
0<speedSnail<6
2<mapHeight<6
5<mapWidth<9
Example
Input
3
2
3
5
3
6
1****#
2****#
3****#
Output
3