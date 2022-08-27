/*
	Goal
Find the winning move for the O player on the following tic-tac-toe board.
Input
3 lines: a 3-character string (ex: ".OX") displaying the board current state
- "." for an empty square
- "X" for square occupied by X player
- "O" for square occupied by O player
Output
3 lines: a 3-character string (ex: ".OX") displaying the board state after an O winning move.
- "." for an empty square
- "X" for square occupied by X player
- "O" for square occupied by O player

If there is no winning move, print "false".
Constraints
- The final board must be the input board plus a new square for O player.
- The board cannot be already in a won situation in the inputs.
Example
Input
OO.
...
...
Output
OOO
...
...
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    for (int i = 0; i < 3; i++) {
        char line[4];
        scanf("%[^\n]", line); fgetc(stdin);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("answer\n");

    return 0;
}