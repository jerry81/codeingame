/*
	Goal
Background/terms:
• A biscuit is round (a circle)
• Measurements are in inches (not necessarily full inches)
• When a Baker has a flattened-out square of dough ("DoughSquare"), he will cut-out biscuits (in grid-style orderly columns and rows) until no more biscuits can be cut-out

The difference:
There are two types of Bakers: "Wasteful" and "Frugal":
• A Wasteful Baker will stop there, and throw away the remaining dough ☹️
• A Frugal Baker will take the remaining dough and re-form it into another (smaller) DoughSquare, and repeat the cutting process. He will continue to do this until no full-biscuit can be cut-out.

NOTE: At the end, there might be enough dough left to manually shape into a circle of the required diameter, but the Baker is not allowed to do this. In order to make a biscuit, the DoughSquare itself must be big enough so that the Baker can place the biscuit cutter fully on it.

The question:
Given the length of a side of the starting DoughSquare, and the diameter of the biscuit cutter, how many more biscuits can a Frugal Baker cut-out than a Wasteful Baker?
Input
Line 1: Two floats side and diameter separated by a space
Output
Line 1: How many more biscuits a Frugal Baker makes than a Wasteful Baker
Constraints
0 < diameter < side < 100
Example
Input
3 1
Output
2
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int get_wasteful(float side, float diameter) {
  int ret = 0;
  ret = pow((int)(side/diameter), 2);
  return ret;
}

float get_remaining_area(float side, float diameter) {
  float ret = 0.0f;
  int num_circles = get_wasteful(side, diameter);
  float area = pow(side,2);
  float radius = diameter/2.0f;
  float circle_area = M_PI * pow(radius,2);
  float total_circle_area = num_circles * circle_area;
  ret = area - total_circle_area;
  return ret;
}

int get_frugal(float side, float diameter) {
    int ret = 0;
    int num_circles = get_wasteful(side, diameter);
    float rem;
    while (num_circles > 0) {
      ret += num_circles;
      rem = get_remaining_area(side, diameter);
      side = sqrt(rem);
      num_circles = get_wasteful(side, diameter); // TODO DRY
    }
    return ret;
}

int main()
{
    float side;
    float diameter;
    cin >> side >> diameter; cin.ignore();
    int wasteful = get_wasteful(side, diameter);
    int frugal = get_frugal(side,diameter);
    cout << frugal - wasteful << endl;
}

/*
 notes
 circles and squares
 first calc wasteful
*/