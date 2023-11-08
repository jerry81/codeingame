#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

enum TriState { NONE, OPP, ME };
struct IGame {
  vector<vector<bool>> _opp;
  vector<vector<bool>> _mine;

  TriState state = NONE;

  IGame() {
    _opp.resize(9, vector<bool>(3, false));
    _mine.resize(9, vector<bool>(3, false));
  }

  bool win(bool opp, int r, int c) {
    auto v = opp ? _opp : _mine;

    // Check horizontal, vertical, and diagonal wins

    // Horizontal win
    if (v[r][0] && v[r][1] && v[r][2]) {
      return true;
    }

    // Vertical win
    if (v[0][c] && v[1][c] && v[2][c]) {
      return true;
    }

    // Diagonal wins
    if ((r == c) && v[0][0] && v[1][1] && v[2][2]) {
      return true;  // Diagonal from top-left to bottom-right
    }

    if ((r + c == 2) && v[0][2] && v[1][1] && v[2][0]) {
      return true;  // Diagonal from top-right to bottom-left
    }

    return false;
  }

  void move(bool opp, int r, int c) {
    if (r < 0 || c < 0) return;
    auto v = opp ? _opp : _mine;
    v[r][c] = true;
  };
};

struct OGame {
};

int main() {
  // game loop
  Game *g = new Game();

  while (1) {
    int opponent_row;
    int opponent_col;
    cin >> opponent_row >> opponent_col;
    cin.ignore();
    g->move(true, opponent_row, opponent_col);
    int valid_action_count;
    cin >> valid_action_count;
    cin.ignore();
    vector<pair<int, int>> possmoves;
    for (int i = 0; i < valid_action_count; i++) {
      int row;
      int col;
      cin >> row >> col;
      cin.ignore();
      possmoves.push_back({row, col});
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, valid_action_count - 1);
    // temp
    int r = dist(gen);
    pair<int, int> randomMove = possmoves[r];
    cout << randomMove.first << " " << randomMove.second << endl;
  }
}