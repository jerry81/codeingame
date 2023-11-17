#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const std::chrono::milliseconds firstTurnLimit(
    1000);                                       // 1000ms for the first turn
const std::chrono::milliseconds turnLimit(100);  // 100ms for subsequent turns

enum TriState { NONE, OPPONENT, MINE };

string move_hash(pair<int, int> move) {
  auto [r, c] = move;
  return to_string(r) + "," + to_string(c);
};

pair<int, int> decode_move(string s) { return {s[0] - '0', s[2] - '0'}; };

pair<pair<int, int>, pair<int, int>> pinPointMove(int r, int c) {
  return {{r / 3, c / 3}, {r % 3, c % 3}};
};

const std::unordered_map<std::string,
                         std::unordered_map<std::string, std::pair<int, int>>>
    ALL_MOVES = {{"0,0",
                  {{"0,0", {0, 0}},
                   {"0,1", {0, 1}},
                   {"0,2", {0, 2}},
                   {"1,0", {1, 0}},
                   {"1,1", {1, 1}},
                   {"1,2", {1, 2}},
                   {"2,0", {2, 0}},
                   {"2,1", {2, 1}},
                   {"2,2", {2, 2}}}},
                 {"0,1",
                  {{"0,3", {0, 3}},
                   {"0,4", {0, 4}},
                   {"0,5", {0, 5}},
                   {"1,3", {1, 3}},
                   {"1,4", {1, 4}},
                   {"1,5", {1, 5}},
                   {"2,3", {2, 3}},
                   {"2,4", {2, 4}},
                   {"2,5", {2, 5}}}},
                 {"0,2",
                  {{"0,6", {0, 6}},
                   {"0,7", {0, 7}},
                   {"0,8", {0, 8}},
                   {"1,6", {1, 6}},
                   {"1,7", {1, 7}},
                   {"1,8", {1, 8}},
                   {"2,6", {2, 6}},
                   {"2,7", {2, 7}},
                   {"2,8", {2, 8}}}},
                 {"1,0",
                  {{"3,0", {3, 0}},
                   {"3,1", {3, 1}},
                   {"3,2", {3, 2}},
                   {"4,0", {4, 0}},
                   {"4,1", {4, 1}},
                   {"4,2", {4, 2}},
                   {"5,0", {5, 0}},
                   {"5,1", {5, 1}},
                   {"5,2", {5, 2}}}},
                 {"1,1",
                  {{"3,3", {3, 3}},
                   {"3,4", {3, 4}},
                   {"3,5", {3, 5}},
                   {"4,3", {4, 3}},
                   {"4,4", {4, 4}},
                   {"4,5", {4, 5}},
                   {"5,3", {5, 3}},
                   {"5,4", {5, 4}},
                   {"5,5", {5, 5}}}},
                 {"1,2",
                  {{"3,6", {3, 6}},
                   {"3,7", {3, 7}},
                   {"3,8", {3, 8}},
                   {"4,6", {4, 6}},
                   {"4,7", {4, 7}},
                   {"4,8", {4, 8}},
                   {"5,6", {5, 6}},
                   {"5,7", {5, 7}},
                   {"5,8", {5, 8}}}},
                 {"2,0",
                  {{"6,0", {6, 0}},
                   {"6,1", {6, 1}},
                   {"6,2", {6, 2}},
                   {"7,0", {7, 0}},
                   {"7,1", {7, 1}},
                   {"7,2", {7, 2}},
                   {"8,0", {8, 0}},
                   {"8,1", {8, 1}},
                   {"8,2", {8, 2}}}},
                 {"2,1",
                  {{"6,3", {6, 3}},
                   {"6,4", {6, 4}},
                   {"6,5", {6, 5}},
                   {"7,3", {7, 3}},
                   {"7,4", {7, 4}},
                   {"7,5", {7, 5}},
                   {"8,3", {8, 3}},
                   {"8,4", {8, 4}},
                   {"8,5", {8, 5}}}},
                 {"2,2",
                  {{"6,6", {6, 6}},
                   {"6,7", {6, 7}},
                   {"6,8", {6, 8}},
                   {"7,6", {7, 6}},
                   {"7,7", {7, 7}},
                   {"7,8", {7, 8}},
                   {"8,6", {8, 6}},
                   {"8,7", {8, 7}},
                   {"8,8", {8, 8}}}}};

struct IGame {
  vector<vector<bool>> _iopp;
  vector<vector<bool>> _imine;

  TriState state = NONE;

  IGame() {
    _iopp.resize(3, vector<bool>(3, false));
    _imine.resize(3, vector<bool>(3, false));
  }

  bool win(bool opp, int r, int c) {
    auto tmp = opp ? _iopp : _imine;
    auto v = tmp;
    v[r][c] = true;

    // Check horizontal, vertical, and diagonal wins

    // bug found!  the test is assuming the move was made first.
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

    return NONE;
  };

  void print() {
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

struct RankedMove {
  int rank = 0;
  pair<int, int> move;
};

bool compareRankedMoves(const RankedMove& a, const RankedMove& b) {
  return a.rank >
         b.rank;  // ">" for descending order, use "<" for ascending order
}

struct OGame {
  vector<vector<IGame>> board;
  vector<vector<bool>> _opp;
  vector<vector<bool>> _mine;
  bool _o_to_move = false;
  unordered_map<string, unordered_map<string, pair<int, int>>> _nextMoves =
      ALL_MOVES;
  string boardKey = "";  // empty means open board

  OGame() {
    board.resize(3, vector<IGame>(3, IGame()));
    _opp.resize(3, vector<bool>(3, false));
    _mine.resize(3, vector<bool>(3, false));
  }

  unordered_map<string, unordered_map<string, pair<int, int>>>
  getFilteredMoves() {
    unordered_map<string, unordered_map<string, pair<int, int>>> res;
    if (boardKey.empty()) return _nextMoves;

    if (_nextMoves.find(boardKey) == _nextMoves.end()) return _nextMoves;

    res[boardKey] = _nextMoves[boardKey];
    return res;
  }

  void bigMove(bool opp, int r, int c) {
    if (r < 0 || c < 0) return;

    if (opp) {
      _opp[r][c] = true;
    } else {
      _mine[r][c] = true;
    }
  }

  unordered_map<string, unordered_map<string, pair<int, int>>> getWinningMoves(
      bool opp) {
    unordered_map<string, unordered_map<string, pair<int, int>>> res;

    for (auto [okey, cat] : getFilteredMoves()) {
      auto [ro, co] = decode_move(okey);
      for (auto [k, v] : cat) {
        auto [r, c] = v;
        r %= 3;
        c %= 3;
        bool innerwin = board[ro][co].win(opp, r, c);
        if (innerwin) {
          res[okey][k] = v;
          break;
        }
      }
    }
    return res;
  }

  TriState move(bool opp, int r, int c) {
    if (r < 0 || c < 0) {
      _o_to_move = !opp;
      return NONE;
    }
    _o_to_move = !opp;

    auto [outer, inner] = pinPointMove(r, c);
    auto [bR, bC] = outer;
    auto [lR, lC] = inner;
    string ohash = move_hash(outer);
    string ihash = move_hash({r, c});
    _nextMoves[ohash].erase(ihash);
    // translate onto smaller board
    TriState res = board[bR][bC].move(opp, lR, lC);
    boardKey = move_hash(inner);
    if (res == OPPONENT) {
      bigMove(true, bR, bC);
      _nextMoves.erase(ohash);

      _nextMoves.erase(ohash);
      if (win(true, bR, bC)) _opp[bR][bC] = true;  // game would be over already

      return OPPONENT;
    } else if (res == MINE) {
      bigMove(false, bR, bC);
      _nextMoves.erase(ohash);
      if (win(false, bR, bC)) _mine[bR][bC] = true;

      return MINE;
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

  int countMoves() {
    int ret = 0;
    for (auto [_, a] : _nextMoves) {
      ret += a.size();
    }
    return ret;
  }

  bool centerMove(int r, int c) { return r % 3 == 1 && c % 3 == 1; }

  bool cornerMove(int r, int c) {
    int mr = r % 3;
    int mc = c % 3;
    return !(mr == 1 || mc == 1);
  }

  vector<RankedMove> getRankedMoves(int turns) {
    vector<RankedMove> sortedMoves;
    for (auto [_, v] : getFilteredMoves()) {
      for (auto [_, v2] : v) {
        RankedMove rm;
        auto [r, c] = v2;
        rm.move = v2;
        if (centerMove(r, c)) {
          rm.rank = 2;
        } else if (cornerMove(r, c)) {
          rm.rank = 1;
        }
        sortedMoves.push_back(rm);
      }
    }
    return sortedMoves;
  }

  void print() {
    cerr << "printing game state "
         << "\n";
    cerr << "to move is " << _o_to_move << "\n";
    cerr << "boardKey is " << boardKey << "\n";
    cerr << "possible moves left are " << countMoves() << "\n";
  }
};

int main() {
  // game loop
  OGame* og = new OGame();

  while (1) {
    int opponent_row;
    int opponent_col;
    cin >> opponent_row >> opponent_col;
    cin.ignore();
    TriState res = og->move(true, opponent_row, opponent_col);
    int valid_action_count;
    cin >> valid_action_count;
    cin.ignore();
    for (int i = 0; i < valid_action_count; i++) {
      int row;
      int col;
      cin >> row >> col;
      cin.ignore();
    }

    vector<RankedMove> rankedMoves = og->getRankedMoves(1);
    // auto winners = og->getWinningMoves(false);
    // auto blockers = og->getWinningMoves(true);
    // if (!winners.empty()) {
    //   move = winners.begin()->second.begin()->second;
    // } else if (!blockers.empty()) {
    //   move = blockers.begin()->second.begin()->second;
    // } else {
    //   vector<RankedMove> sortedMoves;
    //   // TODO: unrandomize - sort by best move
    //   // random_device rd;
    //   // mt19937 gen(rd());
    //   // uniform_int_distribution<int> dist(0, valid_action_count - 1);
    //   // int r = dist(gen);
    //   for (auto [_, v] : og->getFilteredMoves()) {
    //     for (auto [_, v2] : v) {
    //       RankedMove rm;
    //       auto [r, c] = v2;
    //       rm.move = v2;
    //       if (og->centerMove(r, c)) {
    //         rm.rank = 2;
    //       } else if (og->cornerMove(r, c)) {
    //         rm.rank = 1;
    //       }
    //       sortedMoves.push_back(rm);
    //     }
    //   }
    sort(rankedMoves.begin(), rankedMoves.end(), compareRankedMoves);
    auto move = rankedMoves[0].move;

    auto [mr, mc] = move;

    TriState ogmove = og->move(false, mr, mc);

    cout << mr << " " << mc << endl;
  }
}