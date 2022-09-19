The aim of this game is to gain as many followers as possible. You win if your opponent's number of units drops to 0 or if you have more units than your enemy by the last round.

 	Rules
The game is played on a grid 13 units wide and 7 units high. The coordinate X=0, Y=0 is the top left tile. The positions of obstacles and neutral units is randomly generated, but is symmetric.

The source code of the game is available here: https://bitbucket.org/Nixerrr/cultist-wars/src

Units, there are three types:
Neutral unit: Technically cultists but move randomly and cannot shoot until converted.

Cult Leader: This is your initial unit and you have only one of it. It can WAIT, MOVE or CONVERT neutral and enemy units. It has 10 hp.

Cultist: Neutral units become cultists when you convert them. It can WAIT, MOVE or SHOOT enemy units. It has 10 hp.


Turns play out in the following way:
A player performs 1 action / turn. The action can be perfomed by any of the player's units.
A random neutral unit moves in a random direction.
The player's turn ends.
Moving works in the following way:
Units can MOVE in four directions.
Units can MOVE one tile per round.
Units cannot move on tiles with obstacles or with other units.


Shooting works in the following way:
Damage is 7 - distance. Therefore, the maximum damage is 6 hp.
The range of Cultists is 6. Distances are calculated using Manhattan distance.
The path of bullets is calculated based on Bresenham's line algorithm, always drawing the line from lower Y towards higher Y.
If an obstacle or any unit is on the bullet path between the shooter and the target, then it's hit instead of the target.
Obstacles are indestructible.


Converting units works in the following way:
Cult leaders can convert neutral units or enemy cultists. The enemy cult leader cannot be converted.
A cult leader can convert units standing on neighboring tiles in the four directions (they cannot convert diagonally).


Pathfinding works in the following way:
If a unit is told to move to a non-adjacent tile, convert a unit on a non-adjacent tile, or told to shoot at a target beyond its range, it will move towards the target tile on the shortest available path to the target tile. If no path is available, it'll still move along the shortest path until it hits the obstacle.


Victory Conditions
Have more units by the last round than your opponent.
Destroy all enemy units.
Loss Conditions
Have less units by the last round than your opponent.
Your number of units drops to 0.
You output an invalid action.

 	Game Input
Initial Input
Line 1: myId: 0 - first player, 1 - second player

Line 2: width, height: The width and height of the game board

Next height lines: A string y representing a row of the grid ("." is an empty tile, "x" is a tile with an obstacle).

Input
Line 1: numOfUnits: the total number of units on the board.

Next numOfUnits lines:

unitId: individual id of the unit.
type: The type of the unit. 0 = CULTIST, 1 = CULT LEADER.
hp: current health points of the unit
x: x coordinate of the unit.
y: y coordinate of the unit.
owner: ID of the owning player. 0 - Player 1, 1 - Player 2, 2 - neutral
Output
A single line, one of the following:
WAIT
unitId MOVE x y
unitId SHOOT targetId
unitId CONVERT targetId

Constraints
Allotted response time to output is ≤ 50 milliseconds.
Health points = 10.
Damage = 7 - distance
Board width is 13, height is 7.
Shooting range is 6.
Total number of units is 14.
Number of turns is 150.