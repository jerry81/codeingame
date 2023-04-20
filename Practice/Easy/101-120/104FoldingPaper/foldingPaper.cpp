/*

        Goal
A sheet of paper is folded several times. The goal is to determine how many
layers of paper are visible from one side of the obtained folding.

Folding motions are:
R for Right: take the right side and fold it on the left side.
L for Left: take the left side and fold it on the right side.
U for Up: take the high side and fold it on the low side.
D for Down: take the low side and fold it on the high side.
Input
Line 1: a fold string order: several letters R, L, U and D with no space
in-between Line 2: side: a single character R, L, U or D Output n: the number of
layers of paper visible from side Constraints 2 characters ≤ length of order ≤ 8
characters (Try to fold a sheet more than 6 times!) Example Input UL
D
Output
4

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const static int UP = 0;
const static int RIGHT = 1;
const static int DOWN = 2;
const static int LEFT = 3;
int main() {
  int counts[4] = {1, 1, 1, 1};  // URDL
  int curdir = -1;

  string order;
  getline(cin, order);
  // folding order
  string side;
  getline(cin, side);
  // which side we are viewing from

  for (char c : order) {
    switch (c) {
      case 'R': {
        if (curdir == RIGHT) {
          counts[RIGHT]++;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] = 1;
        } else if (curdir == LEFT) {
          counts[RIGHT] = 1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] += 1;
        } else if (curdir == DOWN) {
          counts[RIGHT] *= 2;
          counts[DOWN] += 1;
          counts[UP] = 1;
          counts[LEFT] *= 2;
        } else if (curdir == UP) {
          counts[RIGHT] *= 2;
          counts[DOWN] = 1;
          counts[UP] += 1;
          counts[LEFT] *= 2;
        } else {
          counts[RIGHT] = 2;
          counts[DOWN] = 2;
          counts[UP] = 2;
        }
        curdir = RIGHT;
        break;
      }
      case 'L': {
        if (curdir == RIGHT) {
          counts[RIGHT] = 1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] = 1;
        } else if (curdir == LEFT) {
          counts[LEFT]++;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[RIGHT] = 1;
        } else if (curdir == DOWN) {
          counts[RIGHT] = 1;
          counts[DOWN] += 1;
          counts[UP] = 1;
          counts[LEFT] *= 2;
        } else if (curdir == UP) {
          // cross-axis
          counts[LEFT]=1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[RIGHT] *= 2;
        } else {
          counts[LEFT] = 2;
          counts[DOWN] = 2;
          counts[UP] = 2;
        }
        curdir = LEFT;
        break;
      }
      case 'U': {

        if (curdir == RIGHT) {
          counts[RIGHT] += 1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] = 1;
        } else if (curdir == LEFT) {
          counts[RIGHT] = 1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] += 1;
        } else if (curdir == DOWN) {
          counts[RIGHT] *= 2;
          counts[DOWN] += 1;
          counts[UP] = 1;
          counts[LEFT] *= 2;
        } else if (curdir == UP) {
          counts[LEFT] *= 2;
          counts[DOWN] = 1;
          counts[UP]++;
          counts[RIGHT] *= 2;
        } else {
          cerr << "case 1 " << endl;
          counts[DOWN] = 2;
          counts[LEFT] = 2;
          counts[RIGHT] = 2;
        }
        curdir = UP;
        break;
      }
      case 'D': {
        if (curdir == RIGHT) {
          counts[RIGHT] += 1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] = 1;
        } else if (curdir == LEFT) {
          counts[RIGHT] = 1;
          counts[DOWN] *= 2;
          counts[UP] *= 2;
          counts[LEFT] += 1;
        } else if (curdir == DOWN) {
          counts[LEFT] *= 2;
          counts[DOWN] += 1;
          counts[UP] = 1;
          counts[RIGHT] *= 2;
        } else if (curdir == UP) {
          counts[LEFT] *= 2;
          counts[DOWN] = 1;
          counts[UP] += 1;
          counts[RIGHT] *= 2;
        } else {
          counts[RIGHT] = 2;
          counts[UP] = 2;
          counts[LEFT] = 2;
        }
        curdir = DOWN;
        break;
      }
      default:
        cerr << "unhandled " << endl;
    }
  }
  int resDir;
  switch (side[0]) {
    case 'U': {
      resDir = 0;
      break;
    }
    case 'R': {
      resDir = 1;
      break;
    }
    case 'D': {
      resDir = 2;
      break;
    }
    case 'L': {
      resDir = 3;
      break;
    }
    default: {}
  }

  cout << counts[resDir] << endl;
}

// so we have 4 counts to keep track of
// UL
// start U1 L1 R1 D1
// U -> 2 2 2 1
// L -> 4 4 1 2

// opposite becomes 1
// target / different axis - doubles
// target / same axis - adds 1
// different axis - double