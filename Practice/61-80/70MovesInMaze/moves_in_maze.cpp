/*

Goal
You are in a maze. You have to find the minimum number of moves to reach each
cell from the starting point, and output those numbers in the initial maze.

The number of moves is represented using a character: 0-9 then A-Z (A=10, B=11,
... Z=35).

You may move from a cell to a neighbouring cell which is not a wall in any one
of the four directions: left, right, up or down. The maze is periodic: if you go
left you appear on the right if there is no wall, and vice versa, similarly with
up/down.

There may be unreachable points.

The input maze is made of # for walls, . for free spaces and S for the starting
position. The output must be made of # for walls, . for unreachable points, and
numbers 0-9, A-Z. Input First line: two space-separated integers w and h, the
width and height of the maze. h following lines: the maze. Output h lines: the
maze with numbers for the reachable points. Constraints 3 ≤ w, h ≤ 30 There are
no more than 35 moves needed to reach a point. Example Input 10 5
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
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Point {
  int x;
  int y;
  string to_s() { return to_string(x) + "," + to_string(y); }
};

vector<string> maze;

unordered_set<string> vis;

int bx;
int by;

char to_b36(int i) {
  if (i < 10) return (char)(i + '0');

  int remainder = i - 10;

  return (char)('A' + remainder);
}

int b36_to_i(char c) {
  int ret = (int)(c - '0');
  if (ret < 10) return ret;

  return ret - 7;
}

void bfs(queue<Point> q, int dist) {
  if (q.empty()) return;

  queue<Point> next;

  while (!q.empty()) {
    Point start = q.front();
    q.pop();

    maze[start.y][start.x] = to_b36(dist);
    int x = start.x;
    int y = start.y;
    int uy = (y == 0) ? (by - 1) : y - 1;
    int lx = (x == 0) ? (bx - 1) : x - 1;
    int rx = (x == (bx - 1)) ? 0 : x + 1;
    int dy = (y == (by - 1)) ? 0 : y + 1;
    // bfs on each neighbor
    bool is_empty = (maze[uy][x] == '.');
    if (is_empty) {
      Point u;
      u.x = x;
      u.y = uy;
      if (vis.find(u.to_s()) != vis.end()) {
        next.push(u);
      }
    }
    is_empty = (maze[dy][x] == '.');
    if (is_empty) {
      Point u;
      u.x = x;
      u.y = dy;
      if (vis.find(u.to_s()) == vis.end()) {
        next.push(u);
      }
    }
    is_empty = (maze[y][rx] == '.');
    if (is_empty) {
      Point u;
      u.x = rx;
      u.y = y;
      if (vis.find(u.to_s()) == vis.end()) {
        next.push(u);
      }
    }
    is_empty = (maze[y][lx] == '.');
    if (is_empty) {
      Point u;
      u.x = lx;
      u.y = y;
      if (vis.find(u.to_s()) == vis.end()) {
        next.push(u);
      }
    }
  }
  bfs(next, dist + 1);
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
  return ret;
}

int main() {
  int w;
  int h;
  cin >> w >> h;
  cin.ignore();
  bx = w;
  by = h;
  for (int i = 0; i < h; i++) {
    string row;
    getline(cin, row);
    maze.push_back(row);
  }
  Point start = find_start();
  queue<Point> q;
  q.push(start);
  vis.insert(start.to_s());
  bfs(q, 0);
  for (int i = 0; i < h; i++) {
    cout << maze[i] << endl;
  }
}

// bfs from the start point
// helper to convert 10-36 to A-Z