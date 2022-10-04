/*
Goal
For several years now, in elementary schools, we have seen the emergence of a new educational model, playful programming. The students must program a small robot using assembly blocks. This allows them to get familiar with programming from an early age while exercising their logic and perception of space.

You are a student at one such school. The purpose of the exercise is simple: your teacher has crafted a circuit for your robot, told you how many moves n the robot may make, and you must find out the final position of the robot at end of execution.

To do this you need to know some principles of robot operation.
– When the robot encounters an obstacle (represented by #) it turns right (on same operation) until there's no obstacle ahead anymore. Otherwise on an empty area (represented by .) it moves straight ahead.
– The robot initially moves upwards.
– The robot stops after n moves.
– The top left corner represents the coordinates (0,0)
– The robot's environment is represented as follows, where O is the robot's initial position:
...#........
...........#
............
............
..#O........
..........#.
Input
¤ Width w and height h of the map.
¤ Number n of operations to be performed by the robot
¤ The map where the robot moves with . representing a free space, # an obstacle and O the starting position.
Output
¤ The final position x y (separated by a space) of the robot at end of execution, where x is the horizontal position and y is the vertical position.
Constraints
¤ 0 < w <= 20
¤ 0 < h <= 10
¤ The obstacles are placed in such a way that the robot will never leave the map
¤ The robot will never be blocked between obstacles
¤ n < 2^53
Example
Input
12 6
987
...#........
...........#
............
............
..#O........
..........#.
Output
7 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Point {
  int x;
  int y;
};
int g_w,g_h;
int cur_d = 0;
int lookup[10][20];
Point left(Point c, string grid[]);
Point right(Point c, string grid[]);
Point up(Point c, string grid[]);
Point down(Point c, string grid[]);

Point left(Point c, string grid[]) {
  cur_d = 3;
  int x = c.x;
  if (x <= 0) return up(c, grid);

  if (grid[c.y][x-1] == '#') return up(c,grid);

  Point next;
  next.y = c.y;
  next.x = x-1;
  return next;
}

Point down(Point c, string grid[]) {
  cur_d = 2;
  int y = c.y;
  if (y >= (g_w - 1)) return left(c, grid);

  if (grid[y+1][c.x] == '#') return left(c,grid);

  Point next;
  next.y = y+1;
  next.x = c.x;
  return next;
}

Point right(Point c, string grid[]) {
  cur_d = 1;
  int x = c.x;
  if (x >= g_w-1) return down(c, grid);

  if (grid[c.y][x+1] == '#') return down(c,grid);

  Point next;
  next.y = c.y;
  next.x = x+1;
  return next;
}

Point up(Point c, string grid[]) {
  cur_d = 0;
  int y = c.y;
  if (y <= 0) return right(c, grid);

  if (grid[y-1][c.x] == '#') return right(c,grid);

  Point next;
  next.y = y-1;
  next.x = c.x;
  return next;
}

Point move(Point c, string grid[]) {
  switch (cur_d) {
    case 0: return up(c,grid);
    case 1: return right(c,grid);
    case 2: return down(c,grid);
    default: return left(c,grid);
  }
}

int main()
{
    int w;
    int h;

    cin >> w >> h; cin.ignore();
    g_w = w;
    g_h = h;
    // init grid
    string grid[h];
    Point start; // 0 u 1 r 2 d 3 l
    long long n;
    cin >> n; cin.ignore();
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        grid[i] = line;
        for (int j = 0; j < w; j++) {
          lookup[i][j] = -1;
          if (line[j] == 'O') {
            start.x = j;
            start.y = i;
            lookup[i][j] = 0;
          }
        }
    }

    int period = -1;
    int remainder = -1;
    for (int i = 0; i < n; ++i) {
      if (i > 50) break;
      start = move(start,grid);
      cerr << "start is now " << start.y << " " << start.x << endl;
      cerr << "lookup is " << lookup[start.y][start.x] << endl;

      if (lookup[start.y][start.x] >= 0) {
        cerr << "loop detected at " << start.y << " " << start.x << endl;
        cerr << " on turn " << i << endl;
        if (period == -1) {
          period = i;
          remainder = n % period;
          break;
        }
      } else {
        lookup[start.y][start.x] = i;
      }
    }

    if (period > -1) {
      cerr << "period detected " << period << "remainder " << remainder << endl;
      for (int i = 0; i < remainder+1; ++i) {
        start = move(start,grid);
      }
    }


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << start.x << " " << start.y << endl;
}