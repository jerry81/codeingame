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

bool vert(double x2, double x1)
{
  return x2 == x1;
}

bool horiz(double y2, double y1)
{
  return y2 == y1;
}

double slope(double x1, double y1, double x2, double y2)
{
  double num = y2 - y1;
  double den = x2 - x1;
  return num / den;
}

typedef struct Line
{
  double sx;
  double sy;
  double ex;
  double ey;
  bool vert;
  bool horiz;
  double slope;
} Line;

double solve_x(Line l, double y)
{

  if (l.vert)
    return l.ex;

  double intercept;
  intercept = l.sy - (l.slope*l.sx);
  return (y - intercept) / l.slope;
}




int main()
{
  int N;
  scanf("%d", &N);
  Line lines[N];
  for (int i = 0; i < N; i++)
  {
    int x;
    int y;
    scanf("%d%d", &x, &y);

    double dx = (double)x;
    double dy = (double)y;
    lines[i].sx = dx;
    lines[i].sy = dy;
    if (i != 0)
    {
      lines[i - 1].ex = dx;
      lines[i - 1].ey = dy;
      lines[i - 1].vert = vert(dx, lines[i - 1].sx);
      lines[i - 1].horiz = horiz(dy, lines[i - 1].sy);
      lines[i - 1].slope = ((lines[i - 1].vert)) ? 0.0 : slope(lines[i - 1].sx, lines[i - 1].sy, dx, dy);
    }
    else
    {
      lines[N-1].sx=0.0;
      lines[N-1].sy=0.0;
      lines[N - 1].ex = dx;
      lines[N - 1].ey = dy;
    }
  }

  lines[N - 1].vert = vert(lines[N - 1].ex, lines[N - 1].sx);
  lines[N - 1].horiz = horiz(lines[N - 1].ey, lines[N - 1].sy);
  lines[N - 1].slope = ((lines[N - 1].vert)) ? 0.0 : slope(lines[N - 1].sx, lines[N - 1].sy, lines[N - 1].ex, lines[N - 1].ey);

  int M;
  scanf("%d", &M);
  for (int i = 0; i < M; i++)
  {
    int x;
    int y;
    scanf("%d%d", &x, &y);

    int intersections = 0;
    int prevx = 10001;
    for (int j = 0; j < N; ++j)
    {
      double solved_x = solve_x(lines[j], (double)y);
      if (lines[j].horiz)
      {
        if (lines[j].sy == y && x < solved_x)
        {
          intersections = 1;
          break;
        }
      }


      Line l2 = lines[j];
      bool x_in1 = (solved_x <= l2.sx) && (solved_x >= l2.ex);
      bool x_in2 = (solved_x >= l2.sx) && (solved_x <= l2.ex);
      bool x_in = (solved_x >= x) && (x_in1 || x_in2);
      bool y_in1 = (y <= l2.sy) && (y >= l2.ey);
      bool y_in2 = (y >= l2.sy) && (y <= l2.ey);
      bool y_in = y_in1 || y_in2;
      if (x_in && y_in && (prevx != solved_x)) {
          prevx = solved_x;
          intersections++;
      }
    }
    if (intersections == 1) {
        printf("hit\n");
    } else {
        printf("miss\n");
    }
  }

  return 0;
}
