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

double calc_x_circle(r, y) {
  // y*y + x*x = r*r
  double rs = r*r;
  double ys = y*y;
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
  intercept = l.sy - (l.slope*l.sx);
  return (y - intercept) / l.slope;
}

int main()
{
    fprintf(stderr, "calc circle test, expect 4: actual %lf\n", calc_x_circle(5,3));
    int SIZE; // diameter of circle (length of sq), diamond corner to corner
    scanf("%d", &SIZE);
    int N; // competitors
    scanf("%d", &N); fgetc(stdin);
    int scores[N];
    char names[N][101];
    Line diamond[4];
    // LURD
    double w = SIZE/2.0;
    fprintf(stderr, "width is %lf\n", w);

    // build diamond
    memset (scores, 0, sizeof (int) * N);

    for (int i = 0; i < N; i++) {
        char name[101];
        scanf("%[^\n]", name); fgetc(stdin);
        strcpy(names[i],name);
    }
        for (int i = 0; i < N; ++i) {
      fprintf(stderr, "score is %d\n", scores[i]);
      fprintf(stderr, "name is %s\n", names[i]);
    }
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char throw_name[101];
        int throw_x;
        int throw_y;
        scanf("%s%d%d", throw_name, &throw_x, &throw_y);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("answer\n");

    return 0;
}

/* diamond is like previous problem - four sided polygon - at most we check all four sides against a ray cast to the right for a single intersection */
/* circle use ray cast, but watch out for the fact that a circle will have 2 points to check per given input just check to ensure only one of the points is intersected */
/* square is special case - easily find if point is within bounding box */
