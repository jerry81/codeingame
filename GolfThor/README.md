	The Goal
Your program must allow Thor to reach the light of power. You need to have the shortest code possible.
 	Rules
Thor moves on a map which is 40 wide by 18 high. Note that the coordinates (X and Y) start at the top left! This means the most top left cell has the coordinates "X=0,Y=0" and the most bottom right one has the coordinates "X=39,Y=17".

Once the program starts you are given:
the variable lightX: the X position of the light of power that Thor must reach.
the variable lightY: the Y position of the light of power that Thor must reach.
the variable initialTX: the starting X position of Thor.
the variable initialTY: the starting Y position of Thor.
At the end of the game turn, you must output the direction in which you want Thor to go among:
	
N (North)
NE (North-East)
E (East)
SE (South-East)
S (South)
SW (South-West)
W (West)
NW (North-West)
Each movement makes Thor move by 1 cell in the chosen direction.
 
 
Victory Conditions
You win when Thor reaches the light of power
 
Lose Conditions
Thor moves outside the map
 	Pseudo Code Algorithm
To success your mission, you can use this algorithm:

 
Before the game loop, create two variables thorX et thorY, that will hold the current position of Thor. Initialize these variables to initialTX and initialTY.

 
For each game turn, execute the following actions:

Initialize two variables of type string with two empty strings: directionX and directionY.
If thorX is greater than lightX, directionX receives the value W else if thorX is lower than lightX, directionX receives the value E.
If thorY is greater than lightY, directionY receives the value N else if thorY is lower than lightY, directionY receives the value S.
Update the variables thorX and thorY in function of the chosen direction (+1 or -1).
Indicate, before the end of the turn, the chosen direction as the concatenation of directionY and directionX.

Initial phase
Thor starts on the map at position (3, 6). The light is at position (3, 8).

Tour 1
Action S: Thor moves towards south.
New position is (3, 7).

Tour 2
Action S: Thor moves towards south.
New position is (3, 8).
 	Note
Do not forget to execute the tests from the "Test cases" panel.
Beware: the tests given and the validators used to compute the score are slightly different in order to avoid hard coded solutions.
 	Game Input
The program must first read the initialization data from the standard input, then, in an infinite loop, provides on the standard output the instructions to move Thor.
Initialization input
Line 1: 4 integers lightX lightY initialTX initialTY. (lightX, lightY) indicates the position of the light. (initialTX, initialTY) indicates the initial position of Thor.
Input for a game round
Line 1: the number of remaining moves for Thor to reach the light of power: remainingTurns. You can ignore this data but you must read it.
Output for a game round
A single line providing the move to be made: N NE E SE S SW W or NW
Constraints
0 ≤ lightX < 40
0 ≤ lightY < 18
0 ≤ initialTX < 40
0 ≤ initialTY < 18
Response time for a game round ≤ 100ms