/*

Goal
You are in a maze. You have to find the minimum number of moves to reach each cell from the starting point, and output those numbers in the initial maze.

The number of moves is represented using a character: 0-9 then A-Z (A=10, B=11, ... Z=35).

You may move from a cell to a neighbouring cell which is not a wall in any one of the four directions: left, right, up or down. The maze is periodic: if you go left you appear on the right if there is no wall, and vice versa, similarly with up/down.

There may be unreachable points.

The input maze is made of # for walls, . for free spaces and S for the starting position.
The output must be made of # for walls, . for unreachable points, and numbers 0-9, A-Z.
Input
First line: two space-separated integers w and h, the width and height of the maze.
h following lines: the maze.
Output
h lines: the maze with numbers for the reachable points.
Constraints
3 ≤ w, h ≤ 30
There are no more than 35 moves needed to reach a point.
Example
Input
10 5
##########
#S.......#
##.#####.#
##.#.....#
##########
Output
##########
#01234567#
##2#####8#
##3#DCBA9#
##########

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Point {
  int x;
  int y;
  string to_s() {
    return to_string(x)+","+to_string(y);
  }
};

vector<string> maze;

unordered_set<string> vis;
int bx;
int by;

char to_b36(int i) {
  if (i < 10) return (char)(i + '0');

  int remainder = i-10;

  return (char) ('A' + remainder);
}

int b36_to_i(char c) {
  int ret = (int)(c - '0');
  if (ret < 10) return ret;

  return ret - 7;
}

void bfs(Point start) {
}

Point find_start() {
  Point ret;
  for (int i = 0; i < by; ++i) {
    for (int j = 0; j < bx; ++j) {
      if (maze[i][j] == 'S') {
        ret.x = j;
        ret.y = i;
      }
    }
  }
  vis.insert(ret.to_s());
  maze[ret.y][ret.x] = to_b36(0);
  return ret;
}

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    bx = w;
    by = h;
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);
        maze.push_back(row);
    }
    Point start = find_start();

    for (int i = 0; i < h; i++) {


        cout << "answer" << endl;
    }
}

// bfs from the start point
// helper to convert 10-36 to A-Z