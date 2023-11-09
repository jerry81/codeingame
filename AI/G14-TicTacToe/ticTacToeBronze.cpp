#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

const std::chrono::milliseconds firstTurnLimit(
    1000);                                       // 1000ms for the first turn
const std::chrono::milliseconds turnLimit(100);  // 100ms for subsequent turns

enum TriState { NONE, OPPONENT, MINE };
struct IGame {
  vector<vector<bool>> _iopp;
  vector<vector<bool>> _imine;

  TriState state = NONE;

  IGame() {
    _iopp.resize(3, vector<bool>(3, false));
    _imine.resize(3, vector<bool>(3, false));
  }

  bool win(bool opp, int r, int c) {
    auto v = opp ? _iopp : _imine;

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

  vector<pair<int, int>> getWinningMoves(bool opp,
                                         vector<pair<int, int>> possibleMoves) {
    vector<pair<int, int>> res;
    for (auto move : possibleMoves) {
      if (win(opp, move.first, move.second)) {
        res.push_back(move);
        break;
      }
    }
    return res;
  }

  TriState move(bool opp, int r, int c) {
    if (r < 0 || c < 0) return NONE;

    if (opp) {
      _iopp[r][c] = true;
    } else {
      _imine[r][c] = true;
    }
    if (win(opp, r, c)) return opp ? OPPONENT : MINE;

    cerr << "pr after move" << endl;
    print();
    return NONE;
  };

  void print() {
    cerr << "opponent squares " << endl;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (_iopp[i][j]) cerr << "r: " << i << " c: " << j << endl;
      }
    }
    cerr << "my squares " << endl;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (_imine[i][j]) cerr << "r: " << i << " c: " << j << endl;
      }
    }
  }
};

struct OGame {
  vector<vector<IGame>> board;
  vector<vector<bool>> _opp;
  vector<vector<bool>> _mine;

  OGame() {
    board.resize(3, vector<IGame>(3, IGame()));
    _opp.resize(3, vector<bool>(3, false));
    _mine.resize(3, vector<bool>(3, false));
  }

  void bigMove(bool opp, int r, int c) {
    if (r < 0 || c < 0) return;

    if (opp) {
      _opp[r][c] = true;
    } else {
      _mine[r][c] = true;
    }
  }

  vector<pair<int, int>> getWinningMoves(bool opp,
                                         vector<pair<int, int>> possibleMoves) {
    vector<pair<int, int>> res;

    for (auto move : possibleMoves) {
      auto a = pinPointMove(move.first, move.second);
      bool innerwin = board[a[0].first][a[0].second].win(opp, a[1].first, a[1].second);
      if (innerwin) {
        res.push_back(move);
        break;
      }
    }
    return res;
  }

  vector<pair<int, int>> pinPointMove(int r, int c) {
    return {{r / 3, c / 3}, {r % 3, c % 3}};
  }

  TriState move(bool opp, int r, int c) {
    if (r < 0 || c < 0) return NONE;

    auto ppm = pinPointMove(r, c);
    int bR = ppm[0].first;
    int bC = ppm[0].second;
    int lR = ppm[1].first;
    int lC = ppm[1].second;
    // translate onto smaller board
    TriState res = board[bR][bC].move(opp, lR, lC);
    if (res == OPPONENT) {
      bigMove(true, bR, bC);
      if (win(true, bR, bC)) {
        _opp[bR][bC] = true;
        return OPPONENT;
      }
    } else if (res == MINE) {
      bigMove(false, bR, bC);
      if (win(false, bR, bC)) {
        _mine[bR][bC] = true;
        return MINE;
      }
    }
    return NONE;
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
};

int main() {
  // game loop
  OGame *og = new OGame();

  while (1) {
    int opponent_row;
    int opponent_col;
    cin >> opponent_row >> opponent_col;
    cin.ignore();
    og->move(true, opponent_row, opponent_col);
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
    pair<int, int> move;
    auto winners = og->getWinningMoves(false, possmoves);
    auto blockers = og->getWinningMoves(true, possmoves);
    if (!winners.empty()) {
      cerr << "winner" << endl;
      move = winners.back();
      cerr << "winners size is " << winners.size() << endl;
    } else if (!blockers.empty()) {
      cerr << "block" << endl;
      cerr << "block size is " << blockers.size() << endl;
      move = blockers.back();
    } else {
      cerr << "rand" << endl;
      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<int> dist(0, valid_action_count - 1);
      // temp
      int r = dist(gen);
      move = possmoves[r];
    }

    og->move(false, move.first, move.second);

    cout << move.first << " " << move.second << endl;
  }
}