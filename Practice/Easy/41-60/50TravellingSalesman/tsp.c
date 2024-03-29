/*
Goal
The travelling salesman problem (TSP) asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?"

In this puzzle not necessarily the shortest route is the answer but an approximation using a greedy algorithm (which in fact could be the shortest route as well).

This greedy algorithm starts at the first input given and always chooses the nearest point from the current point. This continues until no points are left and the last point is connected to the first point.

Use the euclidian distance, i.e. sqrt(deltaX^2 + deltaY^2), as the distance between two cities. If there are points with the same distance, always pick the one occurring first in the list.

In general, the greedy algorithm does not find the optimal solution, but nonetheless a greedy heuristic may yield locally optimal solutions that approximate a global optimal solution in a reasonable time.
Input
Line 1: An integer N for the number of points.
Next N lines: Two space separated integers x and y for the coordinates.
Output
Line 1: The rounded distance calculated using the greedy algorithm.
Constraints
5 ≤ N ≤ 14
0 ≤ x, y ≤ 100
Example
Input
5
9 12
24 15
12 30
4 3
13 27
Output
71
*/
#include <math.h>
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
  int N;
  scanf("%d", &N); // number of points
  double dists[N][N];
  int coords[N][2];
  for (int i = 0; i < N; i++)
  {
    int X;
    int Y;
    scanf("%d%d", &X, &Y);
    // x y coordinates
    coords[i][0] = X;
    coords[i][1] = Y;
  }
  for (int i = 0; i < N; ++i)
  {
    double x1 = (double)coords[i][0];
    double y1 = (double)coords[i][1];
    for (int j = i + 1; j < N; ++j)
    {
      double x2 = (double)coords[j][0];
      double y2 = (double)coords[j][1];
      double dx = (x2 - x1) * (x2 - x1);
      double dy = (y2 - y1) * (y2 - y1);

      double dist = sqrt(dx + dy);
      dists[i][j] = dist;
      dists[j][i] = dist;
    }
  }
  int minX = 0;
  int minY = -1;

  double minD = 100000.00;
  for (int first=0;first<N;++first){
    double cdist = dists[0][first];
    if (cdist <= 0.00000000001) {
      continue;
    }

    if (minD > cdist) {
      minD = cdist;
      minY = first;
    }
  }
  double total = 0.00;
  int visited = 1;
  while (visited < N)
  {
    total += minD;
    // remove minX and minY from the map
    for (int removed = 0; removed < N; ++removed)
    {
      dists[removed][minY] = 0.00;
    }
    if (minX != 0)
       dists[minY][minX] = 0.00; // prevent backtrack
    minX = minY;
    int nextMinY = -1;
    double nextDist = 1000000.00;
    for (int comp = 1; comp < N; ++comp)
    {
      double curDist = dists[minY][comp];
      if (curDist <= 0.00000000001)
        continue;

      if (curDist < nextDist)
      {
        nextDist = curDist;
        nextMinY = comp;
      }
    }
    if (nextMinY != -1) {
      minY = nextMinY;
    }
    minD = nextDist;
    ++visited;
  }
  total+=dists[minY][0];
  printf("%i", (int)round(total));

  // Write an answer using printf(). DON'T FORGET THE TRAILING \n
  // To debug: fprintf(stderr, "Debug messages...\n");

  return 0;
}

/*
5
9 12
24 15
12 30
4 3
13 27

ans: 71

distmap:
0: 9,12
1: 24,15
2: 12,30
3: 4,3
4: 13,27

0: { 1: 15.297 2:   3: 4: }
1: { 0: 20 }
2: { 0: 27 }
3: { 0: 5 }
4: { 0: 22 }

0: { 1: 20, 2: 17, 3: 5, 4: 22}
1: { 0: 20, 2:  }
2: { 0: 27, 1: }
3: { 0: 5, 1: }
4: { 0: 22, 1: }
etc...

ending up with
0: { 1,2,3,4 }
1: { 0,2,3,4 }
...
4: { 0,1,2,3 }

get min dist edge (there will be 2)
then walk back to original node

distance map
- array of arrays NxN

*/