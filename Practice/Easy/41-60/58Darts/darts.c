/*
    Goal
A group of your friends want to have a dart throwing competition with a unique target. They've asked you, their tech savvy friend, to automate the scoring as they often squabble over scoring, and have trouble keeping track of who's turn it is to throw.

The target is a square. The square has a circle inscribed within whose diameter matches the width of the square. The circle, in turn, encompasses a diamond whose width from corner to corner matches the circle's diameter. The diamond can be thought of as a square rotated by 1/4 PI so that the corners of the square are on the x and y axes.

Darts landing within the square but not within the circle or diamond are worth 5 points. Darts landing within the circle but not within the diamond are worth 10 points. Darts landing within the diamond are worth 15 points.

In the event of a tie, competitors should be ordered as they were in the name list, so competitors appearing earlier in the name list are listed earlier in ties.

Note: Darts landing on the edge of a shape are considered within the shape.
Note: The center of the square, circle and diamond is at (0,0).
Input
Line 1: SIZE of square as integer.
Line 2: The number of competitors in name list, N.
Next N lines: name of a single competitor in name list.
Next line (N+3): Number of throws, T.
Next T lines: Name of competitor, integer x-coordinate and integer y-coordinate of throw, each separated by a space, name X Y.
Output
N lines: Competitor's name, a space, and that competitor's score, in descending order by score (and in order of appearance in the input list in case of a tie).
Constraints
10 ≤ SIZE ≤ 100
1 ≤ N ≤ 10
1 ≤ T ≤ 50
-300 ≤ X ≤ 300
-300 ≤ Y ≤ 300
Example
Input
20
2
Will
Jill
4
Will 0 0
Jill 0 0
Will 20 20
Jill 0 0
Output
Jill 30
Will 15
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

double calc_x_circle(double r, double y)
{
    // y*y + x*x = r*r
    double rs = r * r;
    double ys = y * y;
    return sqrt(rs - ys);
}

typedef struct Line
{
    double sx;
    double sy;
    double ex;
    double ey;
    double slope;
} Line;

double solve_x(Line l, double y)
{
    double intercept;
    intercept = l.sy - (l.slope * l.sx);
    return (y - intercept) / l.slope;
}

int main()
{
    int SIZE; // diameter of circle (length of sq), diamond corner to corner
    scanf("%d", &SIZE);
    int N; // competitors
    scanf("%d", &N);
    fgetc(stdin);
    int scores[N];
    char names[N][101];
    Line diamond[4];
    // LURD
    double w = SIZE / 2.0;
    // opportunities to refactor
    diamond[0].sy = 0.0; // L
    diamond[0].sx = -w;
    diamond[0].ey = w; // U
    diamond[0].ex = 0.0;
    diamond[0].slope = 1.0;
    diamond[1].sy = w; // U
    diamond[1].sx = 0.0;
    diamond[1].ey = 0.0; // R
    diamond[1].ex = w;
    diamond[1].slope = -1.0;
    diamond[2].ey = 0.0; // D
    diamond[2].ex = w;
    diamond[2].sy = -w; // R
    diamond[2].sx = 0.0;
    diamond[2].slope = 1.0;
    diamond[3].sy = 0.0; // L
    diamond[3].sx = -w;
    diamond[3].ey = -w; // D
    diamond[3].ex = 0.0;
    diamond[3].slope = -1.0;

    memset(scores, 0, sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        char name[101];
        scanf("%[^\n]", name);
        fgetc(stdin);
        strcpy(names[i], name);
    }
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        char throw_name[101]; // need a map because order is not preserved
        int throw_x;
        int throw_y;
        scanf("%s%d%d", throw_name, &throw_x, &throw_y);
        int throw_idx = 0;
        for (int t=1;t<N;++t) {
          if (strcmp(names[t],throw_name)==0) {
            throw_idx=t;
            break;
          }
        }
        // ray cast
        // ray will be a slope 0 ray
        // if diamond check
        int diamond_i = 0;
        double prev_x = -400;
        int x = throw_x;
        int y = throw_y;

        // diamond raycast
        for (int side = 0; side < 4; ++side)
        {
            Line l2 = diamond[side];
            double solved_x = solve_x(l2, y);
            bool x_in1 = (solved_x <= l2.sx) && (solved_x >= l2.ex);
            bool x_in2 = (solved_x >= l2.sx) && (solved_x <= l2.ex);
            bool x_in = (solved_x >= x) && (x_in1 || x_in2);
            bool y_in1 = (y <= l2.sy) && (y >= l2.ey);
            bool y_in2 = (y >= l2.sy) && (y <= l2.ey);
            bool y_in = y_in1 || y_in2;
            if (y_in && x_in && (prev_x != solved_x))
            {
                diamond_i++;
                prev_x = solved_x;
            }
        }

        if ((y == w || y == -w) && ((x != w) || (x != -w))) {
          diamond_i = 0;
        }

        if (diamond_i == 1)
        {
            scores[throw_idx] += 15;
            continue;
        }

        // circle raycast
        int circle_i = 0;
        if (w > (double)y)
        {
            double cx = calc_x_circle(w, (double)y);
            double cx_n = -cx;
            if (cx == x || cx_n == x)
            {
                circle_i = 1;
            }
            else
            {
                if (x < cx)
                    circle_i++;
                if (x < cx_n)
                    circle_i++;
            }

            if (circle_i == 1)
            {
                scores[throw_idx] += 10;
                continue;
            }
        }

        // sq test
        // just check bounding box
        bool y_in_sq = y <= w && y >= -w;
        bool x_in_sq = x <= w && x >= -w;

        if (y_in_sq && x_in_sq)
        {
            scores[throw_idx] += 5;
        }
    }

    int sorted_indexes[N];
    bool visited[N];
    memset(visited, false, sizeof(bool) * N);
    for (int i = 0; i < N; ++i) {
      // find max score and put index in
      int max = -1;
      int max_idx = -1;
      for (int j = 0; j < N; ++j) {
        if (visited[j]) continue;
        if (scores[j] > max) {
          max = scores[j];
          max_idx = j;
        }
      }
      sorted_indexes[i] = max_idx;
      visited[max_idx] = true;
    }

    for (int i = 0; i < N; ++i)
    {
        int nxt_idx = sorted_indexes[i];
        printf("%s %d\n", names[nxt_idx], scores[nxt_idx]);
    }

    return 0;
}

/* diamond is like previous problem - four sided polygon - at most we check all four sides against a ray cast to the right for a single intersection */
/* circle use ray cast, but watch out for the fact that a circle will have 2 points to check per given input just check to ensure only one of the points is intersected */
/* square is special case - easily find if point is within bounding box */

/* TODO: cannot rely on order of throws to be proper
2 choices, use hashmap
search name on each throw to find proper index
*/