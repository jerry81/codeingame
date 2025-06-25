``` 	The Goal
Defeat your opponent by grouping colored blocks.
 	Rules

Each player plays in their own grid 6 cells wide and 12 cells high. Every turn, both players are given two connected blocks, one on top of the other, they must place inside their grid. This is called a pair. The blocks work as follows:
Every pair of block has a random color. The colors are labeled 1 to 5.
You are given the next pairs of blocks to place 8 turns in advance.
Both players are given the same pairs of blocks.
The placement of blocks works as follows:
The blocks are dropped into the grid from above, and stop once they reach the bottom or another block in the same column.
When 4 or more blocks of the same color line up adjacent to each other, they disappear. Blocks connect horizontally or vertically, but not diagonally. The whole group need not be a straight line.
When all groups of the grid have cleared, the blocks above them all fall until they reach the bottom or another block. If this causes new groups to form, those groups will also disappear. This is called a chain.
Aiming for large chains increase your offensive power and lets you automatically attack your opponent.

Attacking works as follows:
As you create groups and perform chains, you will generate nuisance points. As soon as you have enough nuisance points, Skull blocks will appear in the opponent's grid.
Skull blocks act like colored blocks but they will not disappear when they form a group. They are only removed from the grid if a colored block is cleared next to them.
The Skull blocks are dropped into the player's grids in a line, 6 at a time, one in each column.
Skull blocks are labeled 0.

Victory Conditions
Survive your opponent or have a higher score than them after the time limit.

Lose Conditions
Your program provides incorrect output.
Your program times out.
You fail to place the pair of blocks into free cells of your grid.
 	Expert Rules
Groups and chains give score points and nuisance points.
The score points are used as a tie break if both players are still alive after 200 turns.

More information will be available in the next leagues, in which extra rules will be unlocked.
 	Note
The program must first read within an infinite loop, read the contextual data from the standard input and provide to the standard output the desired instructions.
 	Game Input
Input for one game turn
First 8 lines: 2 space separated integers colorA and colorB: the colors of the blocks you must place in your grid by order of appearance. In this league, colorA is always equal to colorB.
Next line: Your current score.
Next 12 lines: 6 characters representing one line of your grid, top to bottom.
Next line: The score of your opponent.
Next 12 lines: 6 characters representing one line of the opponent's grid, top to bottom.

Each line of the grid can contain the characters:
. for an empty cell.
0 for a skull block.
An integer from 1 to 5 for a colored block.
Output for one game turn
A single line: 1 integer: x for the column in which to drop your pair of blocks. You may append text to your instructions, it will be displayed in the viewer.
Constraints
1 ≤ colorA ≤ 5
colorB = colorA
0 ≤ x < 6
Response time per turn ≤ 100ms
Townatropolis, rooftop of Flame Tower, present day...
The terrifying Doctor Darken is plotting to use the immense power of Artificial Intelligence to subdue and control the entire world with the help of super intelligent Kill-Bots.
Fortunately, Captain Wonderface has managed to intercept the villain just as he is about to trigger the start of his invasion.
A mighty battle for the triumph of Light begins as both Super Humans face each other...

```

## wood 2 strat

- maximize chains

- print board
- first build function to "test" a piece at a particular column - done
  - input column
  - output board after

- function to flood and remove those items, should also indicate if no items were removed

- function to drop

- function that uses the above two in a loop to count how many chains

- how do chains happen
```
x1
122
```
- off color sandwiched between single color
- off color gets removed from side
```
1
1
222
222
1x1
1x1
```  <-- first col chains

- start with single chains

- heuristic
- try to replicate situation 2
- most common
```
21
21
12
12
```

- pass wood 2 first
- reserve 3 rows to make chains with 2 colors
- the remaining 3 rows are reserved for the other 2 colors

- TODO: use top non-empty item instead of hardcoded place

## wood 1 strat

- rotate all and just give each color a col
  - worse
- cpu stacks alternating colors on sides to begin (wont die if skulls drop over the playable board apparently)

- stack alternating colors on row 0,5,1,4 in that order

- use 2 and 3 to ff when others are stacked

- so row 11 is the bottom
- row 0 is the top

- get color count on the column

- strat
```
first test for any column: height under 10
0 - top color match ? next : choose 0
repeat for 5,1,4

row 2,3 look for floodfills
  2 options
	vertical 2 vertical 3
else place flat
```

```
int floodfill(board, col, color) // already obsolete
```

```
int floodfill(board, col, rot, colorA, colorB) // returns number of blocks removed
```

- helper get next board state - just place the peice
```
string[] place_peice(board, col, rot, colorA, colorB)
```

- helper - eliminate blocks, get next state and num of blocks eliminated
```
(string[], int) process(board)
```

## current state 6-25-2025
- well, did some vibe coding, had cursor write most of the functions, and the bot is working poorly
- it's hardly performing any elims and not placing like colors together
- let's review the code