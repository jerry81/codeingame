#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Game {
  vector<vector<bool>> _opp;
  vector<vector<bool>> _mine;
  Game() {
    _opp.resize(3, vector<bool>(3, false));
    _mine.resize(3, vector<bool>(3, false));
  }

  void move(bool opp, int r, int c) {
    auto v = opp ? _opp : _mine;
    v[r][c] = true;
  }
};

int main() {
  // game loop
  while (1) {
    int opponent_row;
    int opponent_col;
    cin >> opponent_row >> opponent_col;
    cin.ignore();
    int valid_action_count;
    cin >> valid_action_count;
    cin.ignore();
    for (int i = 0; i < valid_action_count; i++) {
      int row;
      int col;
      cin >> row >> col;
      cin.ignore();
    }

    cout << "0 0" << endl;
  }
}