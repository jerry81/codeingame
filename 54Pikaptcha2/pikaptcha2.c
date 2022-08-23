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

int getNextDir(int cury, int curx, int curd) {

}

int main()
{
    int width;
    int height;
    int startx = 0;
    int starty = 0;
    int curd = 0;
    WIDTH = width;
    HEIGHT = height;
    int counts[height][width]; // use -1 for #
    scanf("%d%d", &width, &height);
    char grid[height][256];
    for (int i = 0; i < height; i++) {
        char line[256];
        scanf("%s", line);
        int j = 0;
        while (line[j] != '\0') {
          char c = line[j];
          fprintf(stderr, "c is %c\n", c);
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
            default:
              break;
          }
          ++j;
        }
        strcpy(grid[i], line);
    }
    for (int i = 0; i < height; i++) {
      fprintf(stderr, "grid line is %s\n", grid[i]);
    }
    char side[2];
    scanf("%s", side);

    fprintf(stderr, "side is %s\n", side);
    fprintf(stderr, "starting at %d %d with direction %d\n", starty,startx,curd);
    int px = 0;
    int py = 0; // for some reason, doing this late leads to timeout
    switch (curd) {
      case 0:
        if ((px+1) < width) {
          px+=1;
        } else {
          if (side == "L") {
            // R to U
            if ((py - 1) > 0) {
              py -= 1;
            } else {
              // must turn again (getting too nested)
            }
            curd = 1;
          } else {
            // R to D
            if ((py + 1) < width) {
              py += 1;
            } else {
            }
            curd = 2;
          }
        }
        break;
      case 1:
      case 2:
      default:
        break;
    }
    fprintf(stderr, "width and height are %d, %d\n", WIDTH, HEIGHT);
    for (int i = 0; i < height; i++) {

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        printf("#####\n");
    }

    return 0;
}

// return to original position
// L or R hugging which wall
