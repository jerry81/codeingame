/*

	Goal
This program problem find out the consecutive string from a to z in alphabetical order in a multi-line string m of n lines of length n.
You can move up, right, left or down. First, you find the a.
if there is a b either up, down, left or right from the position of a, you can move there. if there is a c either up, down, left or right from the position of b, you can move there. continues below to z.
Rewrites all nonconsecutive strings of letters a through z to -.
In other words, this problem only displays the consecutive string from a to z in a multi-line string m of n lines of length n.
Answer to output , as follows.

Example:


10
qadnhwbnyw
iiopcygydk
bahlfiojdc
cfijtdmkgf
dzhkliplzg
efgrmpqryx
loehnovstw
jrsacymeuv
fpnocpdkrs
jlmsvwvuih


The answer to this is...


----------
----------
ba--------
c-ij------
d-hkl---z-
efg-mpqryx
----no-stw
--------uv
----------
----------


As above, only the string alphabetically from a to z should be displayed, and the other parts should be -.
Input
Line 1: An integer n for the size of the string figure.
Next n Lines: multi-line string m.
Output
Output only strings alphabetically from a to z should be displayed in multi-line string m, and the other parts should be -.
Constraints
10<=n<=30
m consists only of lowercase alphabetical characters.
There may be more than one a.
Example
Input
10
vkbjbzmbgb
abcccpzouv
fedopwlmcl
glmnqrszyw
hkrhiutymj
ijqcmvwxoc
pcvlpqzphl
hsgvoklcxy
urdjusmbmz
rchbcausnp
Output
----------
abc-------
fedop-----
glmnqrsz--
hk---uty--
ij---vwx--
----------
----------
----------
----------

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> strs;
int bounds;

char next_c(char c) {
  return (char)(c+1);
}

struct Point {
  int x;
  int y;
};

Point get_next_p(int starty, int startx, char next) {
  Point ret;
  ret.x = -1;
  vector<Point> points_to_test;
  int leftx = startx - 1;
  int rightx = startx + 1;
  int downy = starty + 1;
  int upy = starty - 1;
  if (leftx >= 0) {
    Point left;
    left.x = leftx;
    left.y = starty;
    points_to_test.push_back(left);
  }
  if (rightx < bounds) {
    Point right;
    right.x = rightx;
    right.y = starty;
    points_to_test.push_back(right);
  }
  if (downy < bounds) {
    Point down;
    down.x = startx;
    down.y = downy;
    points_to_test.push_back(down);
  }
  if (upy >= 0) {
    Point up;
    up.x = startx;
    up.y = upy;
    points_to_test.push_back(up);
  }
  // char tests
  for (Point p: points_to_test) {
    cerr << "checking possible points " << strs.at(p.y)[p.x] << " vs " << next << endl;
    if (strs.at(p.y)[p.x] == next) {
      ret = p;
      break;
    }
  }

  return ret;
}

vector<Point> find_path(int starty, int startx) {
  vector<Point> ret;

  char nc = 'b';

  while (nc != '{') {
    Point p = get_next_p(starty, startx, nc);
    if (p.x < 0) {
      cerr << "p x is " << p.x << endl;
      ret.clear();
      break;
    }
    ret.push_back(p);
    cerr << "path growing " << p.x << ", " << p.y << endl;
    starty = p.y;
    startx = p.x;
    nc = next_c(nc);
  }

  return ret;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    bounds = n;
    for (int i = 0; i < n; i++) {
        string m;
        cin >> m; cin.ignore();
        strs.push_back(m);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (strs.at(i)[j] == 'a') {
          vector<Point> points = find_path(i,j);
          cerr << "points length " << points.size() << endl;
          if (!points.empty()) {
            cout << "found path" << endl;
            break;
          }
        }
      }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << "no path found" << endl;
}

// loop all 'a'
// - try the chain for each
// helper int to char