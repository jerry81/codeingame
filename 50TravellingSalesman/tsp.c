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
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        scanf("%d%d", &X, &Y);
        // x y coordinates
        coords[i][0] = X;
        coords[i][1] = Y;
    }
    double minD = 1000000;
    int minY = -1;
    int minX = -1;
    for (int i = 0; i < N; ++i) {
      int x1 = coords[i][0];
      int y1 = coords[i][1];
      for (int j = i+1; j < N; ++j) {
        int x2 = coords[j][0];
        int y2 = coords[j][1];
        fprintf(stderr, "x2 %i y2 %i x1 %i y1 %i\n", x2, y2, x1, y1);
        long dx = (long)((x2-x1)*(x2-x1));
        long dy = (long)((y2-y1)*(y2-y1));

        double dist = sqrt((double)(dx+dy));
        dists[i][j] = dist;
        dists[j][i] = dist;
        if (dist < minD) {
          minD = dist;
          minX = i;
          minY = j;
        }
      }
      fprintf(stderr, "mind %lf, minX %i, minY %i\n", minD, minX, minY);
      int total = 0;
      int visited = 1;
      while (visited < N) {
        total+=minD;
        // remove minX and minY from the map
        for (int removed = 0; removed < N; ++removed) {
          dists[removed][minX] = 0.00;
          dists[removed][minY] = 0.00;
        }
        int nextMinY = -1;
        minX = minY;
        double nextDist = 1000000;
        for (int comp = 0; comp < N; ++comp) {
          double curDist = dists[minY][comp];
          if (curDist <= 0.00) continue;


          if (curDist < nextDist) {
            nextDist = curDist;
            nextMinY = comp;
          }
        }
        ++visited;
      }
      printf("%i", total);
    }


    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("distance\n");

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

0: { 1: 20, 2: 17, 3: 5, 4: 22}
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