/*
The Goal
Thanks to your help, Detective Pikaptcha was able to get a sense of where he was trapped: a space-warp maze! Pikaptcha knows well that a space-warp maze has no visible exit; he must find his own way.

“Time to test a good old trick and see what happens: follow a wall and keep a count for each cell of how many times I stepped into it.”

Your objective is to write a program that will compute, for each cell of a maze, the number of times Pikaptcha will step into the cell by following a wall until he reaches his original location.
wall-following
Left wall following
 	Rules
The maze is given to you as a grid filled with 0s and #s, where 0 represents a passage, and # represents a wall: an impassable cell.
The initial position and direction of Pikaptcha is given to you in the grid as a special character:
>: facing right
v: facing down
<: facing left
^: facing up
An additional character indicates which wall Pikaptcha must follow:
R for the wall on his right
L for the wall on his left
We’re considering the 4-adjacency, meaning a cell has a maximum of 4 adjacent cells (a diagonal cell is not adjacent).

You must analyze the given maze and return it with a small transformation: for each empty cell, instead of a 0, you must return the number of times Pikaptcha stepped into that cell while striding along the maze, following a wall. For each impassable cell, you change nothing: you still return #.
 	Game Protocol
Game Input
First line: 2 integers width and height for the size of the maze.
Next height lines: a string line of length width where 0 is a passage and # is a wall and >, v, < or ^ is the initial position of Pikaptcha.
Next line: a character side for which wall to follow (from Pikaptcha's perspective).
The maze is enclosed in impassable rocks that are not included in the data.
Game Output
height line of width characters each containing the transformed grid.
Constraints
1 ≤ width & height ≤ 100

Allotted response time to output is ≤ 2s


Example
Input
5 3
>000#
#0#00
00#0#
L
Output
1322#
#2#31
12#1#
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
global vars, quick lesson
static vs extern
static - used only by program
extern - can be used in other c programs

// (both done outside fn)
extern int num1;
static int num2;
*/

static int WIDTH;
static int HEIGHT;

int getNextDirByWall(int curd, int wall) {
  switch (curd) {
    case 0:
      return (wall == 0) ? 1 : 2;
      break;
    case 1:
      return (wall == 0) ? 3 : 0;
      break;
    case 2:
      return (wall == 0) ? 0 : 3;
      break;
    case 3:
      return (wall == 0) ? 2 : 1;
      break;
    default:
      return -1;
      break;
  }
}

bool trapped(int cury, int curx, char grid[][256]) {
  int lx = curx - 1;
  int rx = curx + 1;
  int uy = cury - 1;
  int dy = cury + 1;
  if (rx < WIDTH && grid[cury][rx] != '#') {
    return false;
  }
  if (uy >= 0 && grid[uy][curx] != '#') {
    return false;
  }
  if (dy < HEIGHT && grid[dy][curx] != '#') {
    return false;
  }
  if (lx >= 0 && grid[cury][lx] != '#') {
    return false;
  }
  return true;
}

// extend this to find "#s"
int getNextDir(int cury, int curx, int curd, int wall /* 0 L 1 R */ , char grid[][256]) {
  int lx = curx - 1;
  int rx = curx + 1;
  int uy = cury - 1;
  int dy = cury + 1;
  int naturalNext = getNextDirByWall(curd, wall);
  switch (naturalNext) {
    case 0: // R
      if (rx < WIDTH) {
        char rsq = grid[cury][rx];
        if (rsq != '#') {
          return 0;
        }
      }
      break;
    case 1: // U
      if (uy >= 0) {
        char usq = grid[uy][curx];
        if (usq != '#') {
          return 1;
        }
      }
      break;
    case 2: // D
      if (dy < HEIGHT) {
        char dsq = grid[dy][curx];
        if (dsq != '#') {
          return 2;
        }
      };
      break;
    case 3: // L
      if (lx >= 0) {
        char lsq = grid[cury][lx];
        if (lsq != '#') {
          return 3;
        }
      };
      break;
    default:
      break;
  }
  naturalNext = getNextDirByWall(curd, (wall == 0) ? 1:0);
  return getNextDir(cury, curx, naturalNext, wall, grid);
}

/* helper to convert L/R to 0/1 */

int convertWall(char *side) {
  return (strcmp(side,"L") == 0) ? 0 : 1;
}

int main()
{
    // test getdirbywall
    WIDTH=2;
    HEIGHT=3;
    // dtest1 = getNextDir(0,0,0,0);
    // dtest2 = getNextDir(1,2,0,0);
    // dtest3 = getNextDir(0,2,0,0);
    // dtest4 = getNextDir(0,0,1,1);
    // fprintf(stderr, "expect 0 %d, expect 1 %d, expect 3 %d, expect 0 %d\n", dtest1, dtest2, dtest3, dtest4);
    char sidetest[2];
    sidetest[0] = 'R';
    sidetest[1] = '\0';
    int width;
    int height;
    int px = 0;
    int py = 0;
    int startx = 0;
    int starty = 0;
    int curd = 0;
    scanf("%d%d", &width, &height);
    int counts[height][width]; // use -1 for #
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        counts[i][j] = 0;
      }
    }
    WIDTH = width;
    HEIGHT = height;
    char grid[height][256];
    for (int i = 0; i < height; i++) {
        char line[256];
        scanf("%s", line);
        int j = 0;
        while (line[j] != '\0') {
          char c = line[j];
          switch (c) {
            case '>':
              curd = 0;
              startx = j;
              starty = i;
              break;
            case '<':
              curd = 3;
              startx = j;
              starty = i;
              break;
            case '^':
              curd = 1;
              startx = j;
              starty = i;
              break;
            case 'v':
              curd = 2;
              startx = j;
              starty = i;
              break;
            case '#':
              counts[i][j] = -1;
              break;
            default:
              break;
          }
          ++j;
        }
        strcpy(grid[i], line);
    }

    char side[2];
    scanf("%s", side);

    px = startx;
    py = starty;
    int w = convertWall(side);

    do {
      if (trapped(py, px, grid)) {
        break;
      }
      curd = getNextDir(py,px,curd,w,grid);
      switch (curd) {
        case 0:
          ++px;
          break;
        case 1:
          --py;
          break;
        case 2:
          ++py;
          break;
        case 3:
          --px;
          break;
        default:
          break;
      }
      counts[py][px] += 1;
    } while ((px != startx) || (py != starty));

    // move pikaptcha
    for (int i = 0; i < height; i++) {

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        for (int j = 0; j < width; ++j) {
          char nxt = (counts[i][j] < 0) ? '#' : counts[i][j] + '0';
          printf("%c", nxt);
        }
        printf("\n");
        // printf("#####\n");
    }

    return 0;
}

// return to original position
// L or R hugging which wall

/* TIL: trickiness of switch

int a = 9;
switch (a) {
 case 1: printf("I am One\n");
         break;
 case 2: printf("I am Two\n");
         break;
 case 3: printf("I an Three\n");
         break;
 case 4: printf("I am Four\n");
         break;
 case 5: printf("I am Five\n");
         break;
 case 6: printf("I am Six\n");
         break;
 case 7: printf("I am Seven\n");
         break;
 case 8: printf("I am Eight\n");
 case 9: printf("I am Nine\n");
 case 0: printf("I am Zero\n");
 default: printf("I am default\n");
}
Explanation: The a variable value is 9,
this is compared against the case values and a
match is found. All the statements following case 9
 are executed until a break statement or end of switch
  are encountered. Since there are no break statements(break is optional), all the statements
  following case 9 are executed.
  (Which is a weird output, if we gave 9 as input,
   we only want to print I am Nine as output,
   so we have to write break immediately after
   printf(“I am Nine”) to stop the flow)

*/

// TODO: fix case where pikachu has nowhere to go on the first turn