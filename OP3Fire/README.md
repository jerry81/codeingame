	The Goal
The fire just started in a forest. It will spread and destroy all its environment composed of three types of cells:
valuable cells, represented with houses
less valuable cells, represented with trees
safe cells, represented with a beige ground
You have the ability to make cell safe in order to block the spreading of the fire. This action will be called "cutting" (for the trees, but may also be made on houses). It will enable you to prevent some cells from burning. However this action takes time and the fire doesn't wait for you. You will have to choose carefully which cells to cut in order to protect as much value as you can before the fire reaches these cells.
 	Rules
A cell is either a safe cell or a tree cell or a house cell. All tree and house cells have three parameters:
fireDuration: number of turns a cell remains on fire before propagating into the adjacent cells.
cutDuration: number of turns needed to make the cell safe.
value: score represented by this cell and lost if this cell is burnt or cut.
These three parameters are the same for each "tree" cells and the same for each "house" cells. You are given these parameters (6 values), the size of the map, the starting cell of the fire, and finally the type of each cell of the map. By blocking the spreading fire, you must save as much value as you can.

Spread of fire
A cell in fire stays in fire during fireDuration turns. Each cell has a fireProgress incremented each turns. Once this fireProgress reaches fireDuration, the tile is considered as burnt and propagates into the four adjacent cells (North, South, East, West) if they are not safe and not burnt (with fireProgress == -1).

Block the spreading fire
You can cut cells to make them safe and block the spreading of the fire. When you cut a cell, a cooldown is set to the cutDuration of the cell. It will decrease during the next turns until it reaches 0. While the cooldown is non zero, you may not give another cell to cut.
You cannot cut cells which are safe (it would be useless) and cells which are on fire (or you will burn with the cell). Otherwise the game will end. Also, a cell is considered safe as soon as you start to cut it. That is, a fire in an adjacent cell cannot spread into the cell where you already are.

Score evaluation
It is an optimization game. So your goal is to keep as much value as possible. The score for a test is the sum of the value of cells which were not burnt or cut. The score for this game is the sum of the score for each test.
Note: Tests cannot fail. If a test is ended because of a timeout or a bad output, the game will compute the spreading of the remaining fire (if any) for the final score.
 	Game Input
Initialization input
1st line: three space-separated integers treeCuttingDuration, treeFireDuration and treeValue the parameters of the tree cells, as explained in the rules.
2nd line: three space-separated integers houseCuttingDuration, houseFireDuration and houseValue the parameters of the house cells, as explained in the rules.
3rd line: two space-separated integers width, height, the dimensions of the map.
4th line: two space-separated integers fireStartX, fireStartY, the position where the fire starts.
Next height lines: character sequence of length width representing a row of the grid. Each character represents the type of a cell. '#' is a safe cell. '.' is a tree cell. 'X' is a house cell.
Input for one game turn
1st line: an integer cooldown, the number of turns before you can give the instruction of cutting a cell (≥ 1 means you have to WAIT / == 0 means you can give a cell to cut).
Next height lines: width space-separated integers representing the fireProgress of each cell of a line of the grid.
fireProgress == -2 means the cell is safe
fireProgress == -1 means there is no fire
0 ≤ fireProgress < fireDuration means the cell is on fire
fireProgress == fireDuration means the cell is burnt

Output for one game turn
One line containing either "WAIT" if your cooldown is not 0, or "x y" the position of the cell to cut. You can also WAIT if your cooldown is 0, but it is not really productive :p
If an invalid input format is given or if you try to cut a cell while your cooldown is non zero, then you lose. If you give a cell to cut, then at the beginning of the next turn, your cooldown will be cellCuttingDuration-1.
Constraints
0 ≤ width, height ≤ 50
0 ≤ fireDuration ≤ 10
0 ≤ cuttingDuration ≤ 10
0 ≤ value ≤ 1000
8000 ≤ [Sum of value for each cell] ≤ 12000
All cells on the border of the map will be SAFE cells.

Allotted response time to output for the first turn is ≤ 5000 ms.
Allotted response time to output for the other turns is ≤ 100 ms.

# strategy

- first, don't be idle when we can't cut a neighbor.  need a "minimize losses" strategy 
- in one of the test cases, it seems we can cut in a "v shaped" pattern to try to catch up with the fires 