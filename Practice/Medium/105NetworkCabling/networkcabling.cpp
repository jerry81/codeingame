/*

        The Goal
An internet operator plans to connect a business park to the optical fiber
network. The area to be covered is large and the operator is asking you to write
a program that will calculate the minimum length of optical fiber cable required
to connect all buildings. Rules For the implementation of the works, the
operator has technical constraints whereby it is forced to proceed in the
following manner: A main cable will cross through the park from the West to the
East (from the position x of the most westerly building to the position x of the
most easterly building).

For each building, a dedicated cable will connect from the building to the main
cable by a minimal path (North or South), as shown in the following example:

        In this example, the green lines represent the cables.
The minimum length will therefore depend on the position of the main cable.

        Game Input
Input
Line 1: The number N of buildings that need to be connected to the optical fiber
network

On the N following lines: The coordinates x and y of the buildings

Output
The minimum length L of cable required to connect all of the buildings. In other
words, the length of the main cable plus the length of the cables dedicated to
all the buildings.

Note: the buildings with the same position x should not in any case share the
same dedicated cable. Constraints 0 < N ≤ 100000 0 ≤ L ≤ 263 -230 ≤ x ≤ 230 -230
≤ y ≤ 230 Example 1

Input
3
0 0
1 1
2 2
Output
4
Example 2

Input
3
1 2
0 0
2 2
Output
4

*/

#include <limits.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
};

bool compare_homes(Point p1, Point p2) { return p1.y < p2.y; }

int main() {
  int n;

  cin >> n;
  cin.ignore();
  vector<Point> homes;
  float total_y = 0.0f;
  int min_x = INT_MAX;
  int max_x = INT_MIN;
  for (int i = 0; i < n; i++) {
    int x;
    int y;
    cin >> x >> y;
    cin.ignore();
    Point p;
    p.x = x;
    p.y = y;
    homes.push_back(p);
    total_y += y;
    if (x < min_x) min_x = x;
    if (x > max_x) max_x = x;
  }
  if (homes.size() == 1) {
    cout << "0" << endl;
    return 0;
  }
  sort(homes.begin(), homes.end(), compare_homes);

  float avg = n / (float)2.0f;
  if (n % 2 == 0) {
    long avg_as_int = homes.at((int)avg).y;
    long sum = 0;
    for (Point p : homes) {
      sum += abs(avg_as_int - p.y);
    }
    sum += max_x;
    sum -= min_x;
    cout << sum << endl;
  } else {
    long avg_as_int = homes.at(ceil(avg)).y;
    long avg_as_int2 = homes.at(floor(avg)).y;
    long sum = 0;
    long sum2 = 0;
    for (Point p : homes) {
      sum += abs(avg_as_int - p.y);
      sum2 += abs(avg_as_int2 - p.y);
    }
    sum += max_x;
    sum -= min_x;
    sum2 += max_x;
    sum2 -= min_x;
    cout << min(sum, sum2) << endl;
  }
}