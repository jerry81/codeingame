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

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> grid;
struct Island {
  int idx;
  int coast_count;
};

bool sort_islands(Island a, Island b) {
  if (a.coast_count != b.coast_count) return a.coast_count > b.coast_count;

  return a.idx >= b.idx;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string row;
        getline(cin, row);
        grid.push_back(row);
    }

    for (string row: grid) {
      cerr << "row is " << row << endl;
    }
    cout << "answer" << endl;
}

// island coast is counted by just countihng adjacent waters
// so this beocmes a bfs problem where you can just traverse the entire islands' land squares, counting
// must sort in the end by both count and index