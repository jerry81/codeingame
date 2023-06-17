/*

The Goal
Due to the new heat cloak shielding the bombs, the device can no longer provide
the direction of the bombs! It can only indicate whether you are getting closer
or further away from the bombs. Rules After each jump, the upgraded device will
now provide you with the following information code: COLDER You are further away
from the bombs than you were before jumping WARMER You are closer to the bombs
than you were before jumping SAME You are at the same distance from the bombs as
you were before jumping UNKNOWN The device cannot provide you with any
information: only happens before the first jump The Euclidean distance is used
for the measurements of the distance to the bombs:


As for the previous question your mission is to program the device so that it
indicates the location of the next window you should jump to in order to reach
the bombs' room as soon as possible.

Buildings are represented as a rectangular array of windows, the window in the
top left corner of the building is at index (0,0). Note For some tests, the
bombs' location may change from one execution to the other: the goal is to help
you find the best algorithm in all cases.

The tests provided are similar to the validation tests used to compute the final
score but remain different. Game Input The program must first read the
initialization data from standard input. Then, within an infinite loop, read the
device data from the standard input and provide to the standard output the next
movement instruction. Initialization input Line 1 : 2 integers W H. The (W, H)
couple represents the width and height of the building as a number of windows.

Line 2 : 1 integer N, which represents the number of jumps you can make before
the bombs go off.

Line 3 : 2 integers X0 Y0, representing your starting position.

Input for one game turn
A single line providing the device code: COLDER WARMER SAME or UNKNOWN
Output for one game turn
A single line with 2 integers X Y separated by a space character. (X, Y)
represents the location of the next window you should jump to. X represents the
index along the horizontal axis, Y represents the index along the vertical axis.
(0,0) is located in the top-left corner of the building. Constraints 1 ≤ W ≤
10000 5 ≤ H ≤ 10000 2 ≤ N ≤ 100 0 ≤ X, X0 < W 0 ≤ Y, Y0 < H Response time per
turn ≤ 150ms Example Initialization input 10 10     Building has 100 windows
(10x10) 6         You have 6 jumps to find the bombs 2 5       You start at
position (2,5) No output expected Input for turn 1 UNKNOWN You have not jumped
yet

Output for turn 1
7 2
You jump to window (7,2)
Input for turn 2
WARMER
You get nearer the bombs

Output for turn 2
7 6
You jump to window (7,6)
Input for turn 3
SAME
You are at the same distance from the bombs

Output for turn 3
7 4
You jump to window (7,4)

You found the hostages. You can defuse the bombs in time. You win!

*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

pair<double, double> tgt(vector<vector<bool>>& poss, double cury, double curx) {
  double tgtx = 0;
  double tgty = 0;
  double totalX = 0;
  double totalY = 0;
  double wcount = 0;
  for (double y = 0; y < poss.size(); ++y) {
    vector<bool> row = poss[y];
    for (double x = 0; x < row.size(); ++x) {
      if (row[x]) {
        wcount++;
        totalX += x;
        totalY += y;
      }
    }
  }
  double avgx = totalX / wcount;
  double avgy = totalY / wcount;
  tgtx = (avgx * 2) - curx;
  tgty = (avgy * 2) - cury;
  return {tgty, tgtx};
}

double dist(double y1, double x1, double y2, double x2) {
  double dy = y2 - y1;
  double dx = x2 - x1;
  dy *= dy;
  dx *= dx;
  return sqrt(dy + dx);
}

int getPossibilityCount(vector<vector<bool>>& poss) {
  int total = 0;
  for (auto a : poss) {
    for (auto b : a) {
      if (b) total++;
    }
  }
  return total;
}

void printRemainingPoss(vector<vector<bool>>& poss) {
  for (int a = 0; a < poss.size(); ++a) {
    auto row = poss[a];
    for (int b = 0; b < row.size(); ++b) {
      if (row[b]) cerr << "possibility at " << a << ", " << b << endl;
    }
  }
}

void updatePoss(vector<vector<bool>>& poss, double py, double px, double cy,
                double cx, int state /* 0 W 1 C 2 S*/) {
                    poss[cy][cx] = false;
  for (double y = 0; y < poss.size(); ++y) {
    vector<bool> row = poss[y];
    for (double x = 0; x < row.size(); ++x) {
      if (!row[x]) continue;

      double distToP = dist(py, px, y, x);
      double distToC = dist(cy, cx, y, x);

      if (state == 0 && distToC > distToP) {
        poss[y][x] = false;
      } else if (state == 1 && distToP > distToC) {
        poss[y][x] = false;
      } else if (state == 2 && distToP != distToC) {
        poss[y][x] = false;
      }
    }
  }
}

pair<int, int> getClosestPoss(vector<vector<bool>> possibilities, double ny,
                              double nx) {
  pair<int,int> closest;
  double closestDist = INT_MAX;
  for (int y = 0; y < possibilities.size(); ++y) {
    vector<bool> row = possibilities[y];
    for (int x = 0; x < row.size(); ++x) {
      if (row[x]) {
        double curD = dist(ny,nx, y,x);
        if (curD < closestDist) {
          closestDist = curD;
          closest = {y,x};
        }
      }
    }
  }
  return closest;
}

int main() {
  map<string, int> STATES = {{"WARMER", 0}, {"COLDER", 1}, {"SAME", 2}};
  int w;  // width of the building.
  int h;  // height of the building.
  cin >> w >> h;
  cin.ignore();
  vector<vector<bool>> possibilities(h, vector<bool>(w, true));
  int n;  // maximum number of turns before game over.
  cin >> n;
  cin.ignore();
  int x0;
  int y0;
  cin >> x0 >> y0;
  cin.ignore();
  double cury = y0;
  double curx = x0;
  double prevy = y0;
  double prevx = x0;
  // game loop
  while (1) {
    string bomb_dir;  // Current distance to the bomb compared to previous
                      // distance (COLDER, WARMER, SAME or UNKNOWN)
    cin >> bomb_dir;
    cin.ignore();
    if (bomb_dir != "UNKNOWN") {
      updatePoss(possibilities, prevy, prevx, cury, curx, STATES[bomb_dir]);
    } else {
      // ny nx can be calculated as 2*mid - cur
      prevy = cury;
      cury = h-cury-1;
      prevx = curx;
      curx = w-curx-1;

      cout << curx << " " << cury << endl;

      continue;
    }
    auto [ny, nx] = tgt(possibilities, cury, curx);
    prevy = cury;
    prevx = curx;
    auto [nyi, nxi] = getClosestPoss(possibilities, ny, nx);
    cury = nyi;
    curx = nxi;
    cout << nxi << " " << nyi << endl;
  }
}
