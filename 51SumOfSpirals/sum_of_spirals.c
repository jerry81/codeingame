/*
	Goal
Given a matrix of shape N×N arranged in a "spiral", with its numbers spiralling from 1 to N² inward, what is the sum of its diagonals? See examples to clarify what a spiral is.

Example 1:
The input: 3
Gives the following spiral:
1     2     3
8     9     4
7     6     5
The sum of the diagonals is:
1 + 3 + 5 + 7 + 9 = 25


Example 2:
The input: 4
Gives the following spiral:
1    2      3     4
12   13    14     5
11   16    15     6
10   9      8     7
The sum of the diagonals is:
1 + 4 + 7 + 10 + 13 + 14 + 15 + 16 = 80
Input
N the number of layers of the spiral
Output
S the sum of the diagonals
Constraints
0 < N < 1500
0 < S < 2^32 - 1
Example
Input
5
Output
133
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
    int n;
    scanf("%d", &n);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    // build spiral
    int mat[n][n];
    int cx = 0;
    int cy = 0;
    int mxx = n;
    int mxy = n;
    int mnx = 0;
    int mny= 1;
    int dir = 0;
    for (int i = 0; i < (n*n); ++i) {
      mat[cy][cx] = (i+1);
      if (dir == 0) {
        int nx = cx + 1;
        if (nx >= mxx) {
          dir = 1;
          cy += 1;
          --mxx;
          continue;
        } else {
          cx = nx;
        }
      }
      if (dir == 1) {
        int ny = cy + 1;
        if (ny >= mxy) {
          dir = 2;
          cx -= 1;
          --mxy;
          continue;
        } else {
          cy = ny;
        }
      }
      if (dir == 2) {
        int nx = cx - 1;
        if (nx < mnx) {
          dir = 3;
          cy -= 1;
          ++mnx;
          continue;
        } else {
          cx = nx;
        }
      }
      if (dir == 3) {
        int ny = cy - 1;
        if (ny < mny) {
          dir = 0;
          cx += 1;
          ++mny;
          continue;
        } else {
          cy = ny;
        }
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     fprintf(stderr, "%d ", mat[i][j]);
    //   }
    //   fprintf(stderr, "\n");
    // }

    // sum diagonals

    int s = 0;
    bool even = ((n%2) == 0);
    for (int i = 0; i < n; ++i) {
      s += mat[i][i];
      s += mat[n-i-1][i];
    }
    // if not even, subtract the middle element (largest)
    if (!even) {
      s -= n*n;
    }
    printf("%d\n", s);

    return 0;
}