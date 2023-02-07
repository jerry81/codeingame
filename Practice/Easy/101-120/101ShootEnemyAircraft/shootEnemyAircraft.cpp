/*

        Goal
There are enemy aircraft (> or <) in the sky (made of .). Each turn they move
one cell forward. You are in charge of shooting them with a surface-to-air
missile (^). You can only shoot vertically. Each turn your missiles move one
cell up.

Note: When you shoot, the missile appears at the same altitude as the launcher.
Each turn, the missile moves one cell up.

You have to print, each turn, if you WAIT or if you SHOOT. You have to shoot all
the enemy aircraft, and your stock is just enough, so don't SHOOT if you can't
hit an aircraft. After shooting every missile, do not print the last WAITs.
Input
Line 1: the number n of lines
n following lines : the description of the situation.
Output
As many lines as necessary, made of WAIT or SHOOT, one instruction per line.
Constraints
2 <= n <= 10
The sky is made of n-1 lines, the last line is the ground.
A sky line is made of . if no aircraft, > or < for each aircraft.
The ground line is made of _, and ^ for the surface-to-air missile launcher.
There is only one missile launcher, and it's always on the ground.
The lengths of the lines are always the same, and <= 40.
Example
Input
6
....................
.>..................
...................<
....................
....................
_________^__________
Output
WAIT
WAIT
WAIT
SHOOT
WAIT
WAIT
SHOOT

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Point {
  int x = -1;
  int y = -1;
};

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<Point> right;
  vector<Point> left;
  Point me;
  int len = 0;
  int largestDist = 0;
  int highestShot = 0;
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    cin.ignore();
    len = line.length();
    for (int j = 0; j < line.length(); ++j) {
      char c = line[j];

      if (c == '>') {
        Point p;
        p.y = i;
        p.x = j;
        right.push_back(p);
        int dist = len - p.x;
        if (dist > largestDist) largestDist = dist;
      }

      if (c == '<') {
        Point p;
        p.y = i;
        p.x = j;
        left.push_back(p);
        cerr << "left flying at " << i << " " << j << endl;
        int dist = p.x;
        if (dist > largestDist) largestDist = dist;
      }

      if (c == '^') {
        me.y = i;
        me.x = j;
        cerr << "me  at " << i << " " << j << endl;
      }
    }
  }

  unordered_map<int, bool> shots;

  for (Point p : left) {
    int dy = me.y - p.y;
    int dx = p.x - me.x;
    int delay = dx - dy;
    if (delay > highestShot) highestShot = delay;
    shots[delay] = true;

  }

  for (Point p : right) {
    int dy = me.y - p.y;
    int dx = me.x - p.x;
    int delay = dx - dy;
    if (delay > highestShot) highestShot = delay;
    shots[delay] = true;
  }

  for (int i = 1; i <= highestShot; ++i) {
    string output = shots[i] ? "SHOOT" : "WAIT";
    cout << output << endl;
  }
}