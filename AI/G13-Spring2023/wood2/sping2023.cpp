#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> neighbors;

int main() {
  int number_of_cells;  // amount of hexagonal cells in this map
  cin >> number_of_cells;
  cin.ignore();
  neighbors.resize(number_of_cells, vector<int>());
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

  for (auto n: neighbors) {
    cerr << "neighs are " << endl;
    for (auto n1: n) {
      cerr << n1 << endl;
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

  vector<int> resourcesMap(number_of_cells, 0);

  // game loop
  while (1) {
    for (int i = 0; i < number_of_cells; i++) {
      int resources;  // the current amount of eggs/crystals on this cell
      int my_ants;    // the amount of your ants on this cell
      int opp_ants;   // the amount of opponent ants on this cell
      cin >> resources >> my_ants >> opp_ants;
      cin.ignore();
      if (resources>0) resourcesMap[i] = resources;
    }

    // bfs to get closest resource to base.

    // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx>
    // <strength> | MESSAGE <text>
    cout << "LINE " + to_string(maxIdx) + " " + to_string(baseIdx) + " 5;"
         << endl;
  }
}

/*

step 1: naive - put beacon on first available resource

step 2: build line to first beacon (base to resource)

step 3: calc nearest
*/