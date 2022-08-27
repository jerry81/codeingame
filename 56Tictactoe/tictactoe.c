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
void modifyArrTest(char *arr)
{
  *(arr+(2*1+2)) = 'M';
}

int main()
{
  size_t rows = 3; // size of returns size_t
  size_t cols = 4; // accounting for \0
  char mat[rows][cols];
  /*
  According to the 1999 ISO C standard (C99),
  size_t is an unsigned integer type of at least 16 bit (see sections 7.17 and 7.18.3).
  */
  for (int i = 0; i < 3; i++)
  {
    char line[4];
    scanf("%[^\n]", line);
    fgetc(stdin);
    fprintf(stderr, "line is %s\n", line);
    strcpy(mat[i], line);
  }

  modifyArrTest((char *)mat);
  for (int i = 0; i < 3; i++)
  {
    fprintf(stderr, "lines[i] is %s\n", mat[i]);
  }

  // Write an answer using printf(). DON'T FORGET THE TRAILING \n
  // To debug: fprintf(stderr, "Debug messages...\n");

  printf("answer\n");

  return 0;
}

/*
pointer and array fundamentals
&arr[0] is equal to arr and arr[0] is equal to *arr. Similarly,

&arr[1] is equal to (arr + 1) and arr[1] is equal to *(arr + 1).
&arr[2] is equal to (arr + 2) and arr[2] is equal to *(arr + 2) and so on.
...
Finally, we can write the above expressions in a fundamental form as :
&arr[i] is equal to (arr + i) and arr[i] is equal to *(arr + i).
*/