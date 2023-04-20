/*

 	Goal
A sheet of paper is folded several times. The goal is to determine how many layers of paper are visible from one side of the obtained folding.

Folding motions are:
R for Right: take the right side and fold it on the left side.
L for Left: take the left side and fold it on the right side.
U for Up: take the high side and fold it on the low side.
D for Down: take the low side and fold it on the high side.
Input
Line 1: a fold string order: several letters R, L, U and D with no space in-between
Line 2: side: a single character R, L, U or D
Output
n: the number of layers of paper visible from side
Constraints
2 characters ≤ length of order ≤ 8 characters
(Try to fold a sheet more than 6 times!)
Example
Input
UL
D
Output
4

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int counts[4] = {1,1,1,1}; // URDL
    int curdir = -1;
    string order;
    getline(cin, order);
    // folding order
    string side;
    getline(cin, side);
    // which side we are viewing from

    for (char c: order) {
      switch (c) {
        case 'R':
          cerr << "r " << endl;
          break;
        case 'L':
          cerr << "l " << endl;
          break;
        case 'U':
          cerr << "u " << endl;
          break;
        case 'D':
          cerr << "d " << endl;
          break;
        default:
          cerr << "unhandled " << endl;
      }
    }


    cout << "1" << endl;
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