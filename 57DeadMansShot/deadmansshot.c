/*
Goal
Captain Jack Sparrow and his pirate friends have been drinking one night. After plenty of rum, they got into an argument about who is the best shot. Captain Jack takes up some paint and paints a target on a nearby wall. The pirates take out their guns and start shooting.

Your task is to help the drunk pirates find out which shots hit the target.

Captain Jack Sparrow drew the target by drawing N lines. The lines form a convex shape defined by N corners. A convex shape has all internal angles less than 180 degrees. For example, all internal angles in a square are 90 degrees.

A shot within the convex shape or on one of the lines is considered a hit.
Input
Line 1: An integer N for the number of corners.
Next N lines: Two space-separated integers x and y for the coordinates of a corner. The corners are listed in a counterclockwise manner. The target is formed by connecting the corners together with lines and connecting the last corner with the first one.
Line N+1: An integer M for the number of shots.
Next M lines: Two space-separated integers x and y for the coordinates of each shot.
Output
M lines with either "hit" or "miss" depending on whether the shot hit the target or not.
Constraints
3 ≤ N ≤ 10
1 ≤ M ≤ 10
-10000 < x,y < 10000
Example
Input
4
-100 -100
100 -100
100 100
-100 100
5
0 0
99 99
101 101
80 -101
0 -100
Output
hit
hit
miss
miss
hit
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool vert(double x2, double x1) {
  return x2 == x1;
}

bool horiz(double y2, double y1) {
  return y2 == y1;
}

double slope(double x1, double y1, double x2, double y2) {
  double num = y2 - y1;
  double den = x2 - x1;
  return num/den;
}

struct Line {
  double sx;
  double sy;
  double ex;
  double ey;
  bool vert;
  bool horiz;
  double slope;
};

double solve_x(struct Line l, double y) {
  if (l.vert) return l.ex;

  return  (y - l.sy) / l.slope;
  // y = mx + b;
  // x = (y - b) / m
}


void printLine(struct Line l) {
  fprintf(stderr, "sx %lf, sy %lf, ex %lf, ey %lf vert %d, slope %lf\n", l.sx, l.sy, l.ex, l.ey, l.vert, l.slope);
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    struct Line lines[N];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        int y;
        scanf("%d%d", &x, &y);
        struct Line l;
        double dx = (double)x;
        double dy = (double)y;
        lines[i].sx = dx;
        lines[i].sy = dy;
        if (i != 0) {
          lines[i-1].ex = dx;
          lines[i-1].ey = dy;
          lines[i-1].vert = vert(dx, lines[i-1].sx);
          lines[i-1].horiz = horiz(dy, lines[i-1].sy);
          lines[i-1].slope = ((lines[i-1].vert)) ? 0.0 : slope(lines[i-1].sx, lines[i-1].sy,dx,dy);
        } else {
          lines[N-1].ex = (double)x;
          lines[N-1].ey = (double)y;
        }
    }
    lines[N-1].vert = vert(lines[N-1].ex, lines[N-1].sx);
    lines[N-1].horiz = horiz(lines[N-1].ey, lines[N-1].sy);
    lines[N-1].slope = ((lines[N-1].vert)) ? 0.0 : slope(lines[N-1].sx, lines[N-1].sy,lines[N-1].ex,lines[N-1].ey);
    // final item calculations
    // test
    fprintf(stderr, "test lines\n");
    for (int i = 0; i < N; ++i) {
      printLine(lines[i]);
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        int y;
        scanf("%d%d", &x, &y);

        // for each point check the intersection with each line
        int intersections = 0;
        for (int i = 0; i < N; ++i) {
          struct Line l = lines[i];
          if (l.horiz) {
            if (l.sy == y) {
              ++intersections;
            }
          } else {
            double solved_x = solve_x(l, (double)y);
            if (solved_x>l.ex && solved_x>l.sx) {
                continue;
            }

            // if y is between the start and end y then there is intersection
            if (y>=l.ey && y<=l.sy) {
              ++intersections;
            }
            else if (y<l.ey && y>l.sy) {
              ++intersections;
            }
          }


        }
        fprintf(stderr, "intersections is %d\n", intersections);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("hit_or_miss\n");

    return 0;
}

/*
  Ray casting!
  from the point, go in any direction (i.e. slope 0)
  count # of intersections with all lines of polygon
  if 1 then hit else miss
*/

/*
-100 -100
100 -100
100 100
-100 100
99 99

lines, -100 -100 to 100 -100
dx 200 dy 0 slope 0, intercept
y = sx + b
s = 0
y = 0x + b
y = b
b = -100

100 -100 to 100 100
dx = 0
dy = 200

100 100 to -100 100
ray 99 99

every vector has slope and starting point
from this you can calculate x or y given y or x

the slope could be infinite
struct vec {
  bool inf,
  double slope,
  double sx,
  double sy,
  double ex,
  double ey
}

a point will be given x,y
extrapolate the point with slope 0 (y remains fixed)
to the right
so we just check the y

if inf, just check that
*/


/*
      4





5       3

0       2





   1
*/