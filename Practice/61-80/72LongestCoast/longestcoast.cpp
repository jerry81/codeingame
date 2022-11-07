/*

	Goal
Given a n*n grid, output the index of the island with the longest coast, followed by the amount of water it holds. (Island indexes are 1-indexed)

An island is made of one or more # characters, we'll call that an island block. While water is represented by ~.

We start from the first row and go through the columns left to right till the last row, when encountering a block that you haven't visited yet, that means it is the start of a new island, therefore that is now the ith island, it may connect other blocks in four directions: up, down, left and right, meaning only horizontal and vertical directions. these blocks may also connect other blocks, this goes on until there are no other connected blocks, and once there is no connection anymore, we look for a new island using the same process.

If multiple islands have the same amount of water, output the one with a smaller index.

Example:

With n = 5:

~~~~#
~~~##
~~~~~
~##~~
~~~~~

We see that the 2nd island is the one with the longest coast, because the first block is surrounded by 3 water blocks and so is the second block. once summed up we get 6, which is greater than the first island having only 4. so in this case, we output 2 6 (island 2, 6 water blocks).
Input
Line 1: An integer n representing the size of the grid
Next n lines: A row of the grid of length n
Output
The index of the island with the longest coast followed by the amount of water it holds separated by a space.
Constraints
3 ≤ n ≤ 50
Example
Input
3
~~#
~~#
~~#
Output
1 3

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> grid;
unordered_set<string> lookup;

int bounds;
string get_hash(int x, int y) {
  return to_string(x) + "," + to_string(y);
}

bool visited(string h) {
  return (lookup.find(h) != lookup.end());
}
struct Island {
  int idx;
  int coast_count;
};

vector<Island> islands;

struct Point {
  int x;
  int y;
};

bool sort_islands(Island a, Island b) {
  if (a.coast_count != b.coast_count) return a.coast_count > b.coast_count;

  return a.idx >= b.idx;
}

// global for index
int g_i = 1;

void bfs(int y, int x) {
  // bfs again!
  // while queue is not empty
  // pop from queue = point
  // process point and add neighbors to queue
  // dont doublecount water
  Island island;
  island.idx = g_i;
  int coasts = 0;
  unordered_set<string> inner_lookup;
  queue<Point> neighbors;
  Point p;
  p.x = x;
  p.y = y;
  neighbors.push(p);
  while (!neighbors.empty()) {
    queue<Point> next_neighbors;
    while (!neighbors.empty()) {
      Point p = neighbors.front();
      neighbors.pop();
      int nx = p.x;
      int ny = p.y;
      lookup.insert(get_hash(nx,ny));
      int lx = nx - 1;
      int rx = nx + 1;
      int uy = ny - 1;
      int dy = ny + 1;

      if (lx >= 0) {
        Point nxt;
        nxt.x = lx;
        nxt.y = ny;
        char neighbor_char = grid[ny][lx];
        string h = get_hash(lx, ny);
        if (neighbor_char == '#' && !visited(h)) {
          lookup.insert(h);
          next_neighbors.push(nxt);
        } else if (neighbor_char == '~') {
          // coast
          if (inner_lookup.find(h) == inner_lookup.end()) {
            ++coasts;
            inner_lookup.insert(h);
          }
        }
      }

      if (rx < bounds) {
        Point nxt;
        nxt.x = rx;
        nxt.y = ny;
        char neighbor_char = grid[ny][rx];
        string h = get_hash(rx, ny);
        if (neighbor_char == '#' && !visited(h)) {
             lookup.insert(h);
          next_neighbors.push(nxt);
        } else if (neighbor_char == '~') {
          // coast
          if (inner_lookup.find(h) == inner_lookup.end()) {
            ++coasts;
            inner_lookup.insert(h);

          }
        }
      }

      if (uy >= 0) {
        Point nxt;
        nxt.x = nx;
        nxt.y = uy;
        char neighbor_char = grid[uy][nx];
        string h = get_hash(nx, uy);
        if (neighbor_char == '#' && !visited(h)) {
             lookup.insert(h);
          next_neighbors.push(nxt);
        } else if (neighbor_char == '~') {
          // coast
          if (inner_lookup.find(h) == inner_lookup.end()) {
            ++coasts;
            inner_lookup.insert(h);

          }
        }
      }

      if (dy < bounds) {
        Point nxt;
        nxt.x = nx;
        nxt.y = dy;
        char neighbor_char = grid[dy][nx];
        string h = get_hash(nx, dy);
        if (neighbor_char == '#' && !visited(h)) {
             lookup.insert(h);
          next_neighbors.push(nxt);
        } else if (neighbor_char == '~') {
          // coast
          if (inner_lookup.find(h) == inner_lookup.end()) {
            ++coasts;
            inner_lookup.insert(h);

          }
        }
      }
    }
    neighbors = next_neighbors;
  }
  island.coast_count = coasts;
  islands.push_back(island);
  ++g_i;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    bounds = n;
    for (int i = 0; i < n; i++) {
        string row;
        getline(cin, row);
        grid.push_back(row);
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c = grid[i][j];
        if (c == '#' && !visited(get_hash(j,i))) {
          bfs(i,j);
        }
      }
    }
    sort(islands.begin(), islands.end(), sort_islands);
    for (Island i: islands) {
      cerr << "island idx " << i.idx << endl;
      cerr << "island count " << i.coast_count << endl;
    }
    cout << islands[0].idx << " " << islands[0].coast_count << endl;
}

// island coast is counted by just countihng adjacent waters
// so this beocmes a bfs problem where you can just traverse the entire islands' land squares, counting
// must sort in the end by both count and index