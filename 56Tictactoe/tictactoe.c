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
void modify_arr(char *arr, size_t row, size_t col)
{
  *(arr + (row * 4 + col)) = 'O';
}

int check_line(char line[3])
{
  int o_count = 0;
  int space_count = 0;
  int space_pos = -1;
  for (int i = 0; i < 3; ++i)
  {
    if (line[i] == 'O')
    {
      ++o_count;
    }
    if (line[i] == '.')
    {
      ++space_count;
      space_pos = i;
    }
  }
  if (space_count == 1 && o_count == 2) {
    return space_pos;
  } else {
    return -1;
  }
}

void print_matrix(char mat[3][4]) {
  for (int i = 0; i < 3; i++)
  {
    printf("%s\n", mat[i]);
  }
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
    // fprintf(stderr, "line is %s\n", line);
    strcpy(mat[i], line);
  }

  // char test[3] = { 'O', 'O', ' '};
  // char test2[3] = { 'X', 'O', ' '};
  // int res = check_line(test);
  // int res2 = check_line(test2);
  // fprintf(stderr, "res is %d\n", res);
  // fprintf(stderr, "res2 is %d\n", res2);

  // horizontals first
  for (int i = 0; i < 3; ++i) {
    char h_line[3];
    char v_line[3];
    for (int j = 0; j < 3; ++j) {
      h_line[j] = mat[i][j];
      v_line[j] = mat[j][i];
    }
    // for (int k = 0; k < 3; ++k) {
    //   fprintf(stderr, "h_line[%d] is %c\n", k, h_line[k]);
    // }

    int check = check_line(h_line);

    if (check > 0) {
      // update matrix
      // print matrix
      modify_arr((char *)mat, i, check);
      print_matrix(mat);
      return 0;
    };

    int vcheck = check_line(v_line);
    if (vcheck > 0) {
      modify_arr((char *)mat, vcheck, i);
      print_matrix(mat);
      return 0;
    }
  }

  // modify_arr((char *)mat, 2, 2);


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

/*
   00 01 02
   10 11 12
   20 21 22

   8 total checks
*/