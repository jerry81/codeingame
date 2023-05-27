#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> neighbors;
vector<int> resourceMap;
int _size;

int bfs(int start, vector<int> ignore) {
  vector<bool> visited(_size, false);
  queue<int> nn;
  visited[start] = true;
  nn.push(start);
  while (!nn.empty()) {
    int cur = nn.front();
    nn.pop();

    if (resourceMap[cur] > 0) {
      if (ignore.empty() ||
          find(ignore.begin(), ignore.end(), cur) == ignore.end()) {
        return cur;
      }
    }

    for (int n : neighbors[cur]) {
      if (!visited[n]) {
        nn.push(n);
        visited[n] = true;
      }
    }
  }
  return start;
}

string writeLine(int start, int end, int weight) {
  return "LINE " + to_string(start) + " " + to_string(end) + " " +
         to_string(weight) + ";";
}

int main() {
  int number_of_cells;  // amount of hexagonal cells in this map
  cin >> number_of_cells;
  cin.ignore();
  _size = number_of_cells;
  neighbors.resize(_size, vector<int>());
  resourceMap.resize(_size, 0);
  for (int i = 0; i < number_of_cells; i++) {
    int type;               // 0 for empty, 1 for eggs, 2 for crystal
    int initial_resources;  // the initial amount of eggs/crystals on this cell
    int neigh_0;  // the index of the neighbouring cell for each direction
    int neigh_1;
    int neigh_2;
    int neigh_3;
    int neigh_4;
    int neigh_5;
    cin >> type >> initial_resources >> neigh_0 >> neigh_1 >> neigh_2 >>
        neigh_3 >> neigh_4 >> neigh_5;
    cin.ignore();
    int neighbors_arr[] = {neigh_0, neigh_1, neigh_2,
                           neigh_3, neigh_4, neigh_5};
    for (int neigh : neighbors_arr) {
      if (neigh > -1) {
        neighbors[i].push_back(neigh);
      }
    }
  }

  int number_of_bases;
  int baseIdx = 0;
  cin >> number_of_bases;
  cin.ignore();
  for (int i = 0; i < number_of_bases; i++) {
    int my_base_index;
    cin >> my_base_index;
    cin.ignore();
    baseIdx = my_base_index;
  }
  for (int i = 0; i < number_of_bases; i++) {
    int opp_base_index;
    cin >> opp_base_index;
    cin.ignore();
  }

  // game loop
  while (1) {
    for (int i = 0; i < _size; i++) {
      int resources;  // the current amount of eggs/crystals on this cell
      int my_ants;    // the amount of your ants on this cell
      int opp_ants;   // the amount of opponent ants on this cell
      cin >> resources >> my_ants >> opp_ants;
      cin.ignore();
      resourceMap[i] = resources;
    }

    // bfs to get closest resource to base.
    vector<int> ignore;
    string output = "";
    for (int i = 0; i < 4; ++i) {
      int closest = bfs(baseIdx, ignore);
      ignore.push_back(closest);
      output += writeLine(closest, baseIdx, 1);
    }


    // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx>
    // <strength> | MESSAGE <text>

    cout << output << endl;
  }
}

/*

step 1: naive - put beacon on first available resource

step 2: build line to first beacon (base to resource)

step 3: calc nearest

step 4: try multitasking - two harvests at a time
*/