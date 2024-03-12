#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <climits>

using namespace std;


enum TriState { NONE, OPPONENT, MINE, DRAW };

pair<pair<int, int>, pair<int, int>> pinPointMove(int r, int c) { // { bigboard loc, littleboard loc}
  return {{r / 3, c / 3}, {r % 3, c % 3}};
};

const map<pair<int,int>, set<pair<int,int>>> ALL_MOVES = {
        {{0, 0},
            {
                {0, 0},
                {0, 1},
                {0, 2},
                {1, 0},
                {1, 1},
                {1, 2},
                {2, 0},
                {2, 1},
                {2, 2}
            }
        },
        {{0, 1},
            {
                {0, 3},
                {0, 4},
                {0, 5},
                {1, 3},
                {1, 4},
                {1, 5},
                {2, 3},
                {2, 4},
                {2, 5}
            }
        },
        {{0, 2},
            {
                {0, 6},
                {0, 7},
                {0, 8},
                {1, 6},
                {1, 7},
                {1, 8},
                {2, 6},
                {2, 7},
                {2, 8}
            }
        },
        {{1, 0},
            {
                {3, 0},
                {3, 1},
                {3, 2},
                {4, 0},
                {4, 1},
                {4, 2},
                {5, 0},
                {5, 1},
                {5, 2}
            }
        },
        {{1, 1},
            {
                {3, 3},
                {3, 4},
                {3, 5},
                {4, 3},
                {4, 4},
                {4, 5},
                {5, 3},
                {5, 4},
                {5, 5}
            }
        },
        {{1, 2},
            {
                {3, 6},
                {3, 7},
                {3, 8},
                {4, 6},
                {4, 7},
                {4, 8},
                {5, 6},
                {5, 7},
                {5, 8}
            }
        },
        {{2, 0},
            {
                {6, 0},
                {6, 1},
                {6, 2},
                {7, 0},
                {7, 1},
                {7, 2},
                {8, 0},
                {8, 1},
                {8, 2}
            }
        },
        {{2, 1},
            {
                {6, 3},
                {6, 4},
                {6, 5},
                {7, 3},
                {7, 4},
                {7, 5},
                {8, 3},
                {8, 4},
                {8, 5}
            }
        },
        {{2, 2},
            {
                {6, 6},
                {6, 7},
                {6, 8},
                {7, 6},
                {7, 7},
                {7, 8},
                {8, 6},
                {8, 7},
                {8, 8}
            }
        }
    };

struct IGame { // represents a mini board
  vector<vector<bool>> _iopp; // 2d grid
  vector<vector<bool>> _imine;
  int filled_count = 0;
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

  TriState move(bool opp, int r, int c) {
    if (r < 0 || c < 0) return NONE;


    if (opp) {
      _iopp[r][c] = true;
    } else {
      _imine[r][c] = true;
    }


    if (win(opp, r, c)) return opp ? OPPONENT : MINE;

    filled_count+=1;

    if (filled_count>=9) return DRAW;

    return NONE;
  };

  void print() {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (_iopp[i][j]) cerr << "r: " << i << " c: " << j << endl;
      }
    }
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
  bool _o_to_move = false;
  map<pair<int,int>, set<pair<int,int>>> _nextMoves =
      ALL_MOVES;
  pair<int,int> last_move = {-1,-1};  // neg value means open board

  OGame() {
    board.resize(3, vector<IGame>(3, IGame()));
    _opp.resize(3, vector<bool>(3, false));
    _mine.resize(3, vector<bool>(3, false));
  }

  OGame(OGame* toClone) {
    board = toClone->board; // the igames need to be cloned too
    _opp = toClone->_opp;
    _mine = toClone->_mine;
    _nextMoves = toClone->_nextMoves;
    last_move = toClone->last_move;
  }

  map<pair<int,int>, set<pair<int,int>>>
  getFilteredMoves() { // "filter" means filter down to a single small boad
    map<pair<int,int>, set<pair<int,int>>> res;
    if (last_move.first==-1) return _nextMoves;

    if (_nextMoves.find(last_move) == _nextMoves.end()) {
      return _nextMoves;
    }

    res[last_move] = _nextMoves[last_move];
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

  TriState randomMove(bool opp, mt19937& gen) {
     map<pair<int,int>, set<pair<int,int>>> fm = getFilteredMoves();

     if (fm.empty()) return DRAW;

    uniform_int_distribution<> dis(0, fm.size() - 1);
    int randomIndex = dis(gen);

    // Iterate to the random position in the map
    auto it = fm.begin();
    std::advance(it, randomIndex);
    const auto& randomSet = it->second;
    // cout << "key a,b is " << p.first.first << "," << p.first.second << endl;
    std::uniform_int_distribution<> dis_set(0, randomSet.size() - 1);
    int randomIndexSet = dis_set(gen);

    // Iterate to the random position in the set
    auto setIt = randomSet.begin();
    std::advance(setIt, randomIndexSet);
    // if (!started) {
    //   string s = opp ? "opp" : "i";
    //   cerr << s << " makes move " << setIt->first << "," << setIt->second << endl;
    // }
    return move(opp, setIt->first, setIt->second);
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
    _nextMoves[outer].erase({r,c});
    // translate onto smaller board
    TriState res = board[bR][bC].move(opp, lR, lC);
    last_move = inner;
    if (res == OPPONENT) {
      bigMove(true, bR, bC);
      _nextMoves.erase(outer);
      if (win(true, bR, bC)) return OPPONENT;  // game would be over already

    } else if (res == MINE) {
      bigMove(false, bR, bC);
      _nextMoves.erase(outer);
      if (win(false, bR, bC)) return MINE;

    } else if (res == DRAW) {
      _nextMoves.erase(outer);
    }
    // is it not moving for draws?
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

  bool inner_win(bool opp, int r, int c) {
     auto [outer, inner] = pinPointMove(r, c);
     auto [bR, bC] = outer;
     auto [lR, lC] = inner;
     return board[bR][bC].win(opp, lR, lC);
  }

  int countMoves() {
    int ret = 0;
    for (auto [_, a] : _nextMoves) {
      ret += a.size();
    }
    return ret;
  }

  void print() {
    cerr << "printing game state "
         << "\n";
    cerr << "to move is " << _o_to_move << "\n";
    cerr << "last move is " << last_move.first << "," << last_move.second << "\n";
    cerr << "possible moves left are " << countMoves() << "\n";
  }
};

TriState simulate(OGame* start, mt19937& gen, bool opp) { // always start from my move
  TriState res = NONE;
  while (res == NONE) {
    res = start->randomMove(opp, gen);
    opp = !opp;
  }
  return res;
}

int main() {
  // game loop
  OGame* og = new OGame();
  random_device rd;
  mt19937 gen(rd());
  int CUR_THRESH = 150;
  bool firstturn = true;
  int turns = 0;
  while (1) {
    CUR_THRESH+=2;
    int opponent_row;
    int opponent_col;
    cin >> opponent_row >> opponent_col;
    cin.ignore();
    TriState res = og->move(true, opponent_row, opponent_col);
    int valid_action_count;
    cin >> valid_action_count;
    cin.ignore();
    int mr = -1;
    int mc;
    vector<pair<int,int>> moves;
    pair<int,int> blocker = {-1,-1};
    for (int i = 0; i < valid_action_count; i++) {
      int row;
      int col;
      cin >> row >> col;
      cin.ignore();
      moves.push_back({row,col});
      if (og->inner_win(false, row, col)) {
        mr = row;
        mc = col;
      }

      if (og->inner_win(true,row,col)) {
        blocker = {row,col};
      }

    }

    int available_moves = moves.size();
    vector<int> moves_stats(available_moves, 0);

    // greedy win a small boad or block a small board
   if  (mr < 0) {
     if (blocker.first >= 0) {
       mr = blocker.first;
       mc = blocker.second;
     } else {
     for (int i = 0; i < CUR_THRESH; ++i) {
        OGame* cloned = new OGame(og);
        int  cur_move_idx = i % available_moves;
        pair<int,int> cur_move = moves[cur_move_idx];
        cloned->move(false, cur_move.first, cur_move.second);
        TriState ts =  simulate(cloned, gen, true);
        if (ts == 1) {
          moves_stats[cur_move_idx] -=1;
        } else if (ts == 2) {
          moves_stats[cur_move_idx] +=1;
        }


       // cerr << "result was " << ts << endl;
        delete cloned;
    }


    int mx = INT_MIN;
    int mx_i = -1;
    for (int i = 0; i < available_moves; ++i) {
      if (moves_stats[i] > mx) {
        mx_i = i;
        mx = moves_stats[i];
      }
    }
      // cerr << "full stats are as follows " << endl;
      // for (int i: moves_stats) {
      //   cerr << i << endl;
      // }
      // cerr << "simulations run for each " << endl;
      // for (int i: total_moves_stats) {
      //   cerr << i << endl;
      // }

    //   vector<OGame*> clonedGames;
    //   map<pair<int,int>, set<pair<int,int>>> filtered = cloned->getFilteredMoves();
    //   for (auto [_,st]:filtered) {
    //     for (auto [r,c]: st) {
    //       OGame* child = new OGame(cloned);
    //       child->move(false, r,c); // x makes a move in the cloned game
    //       clonedGames.push_back(child);
    //     }
    //   }
    //   int children_count = clonedGames.size();
    //   cerr << "there are " << children_count << " children" << endl;
    //   vector<int> scores(children_count, 0);
    //   for (int i = 0; i < 100; ++i) {
    //     // round robin
    //     int curIdx = i%children_count;

    //     TriState ts = simulate(clonedGames[i], gen);
    //     if (ts == OPPONENT) {
    //       scores[i] -=1;
    //     } else if (ts == MINE) {
    //       scores[i] +=1;
    //     }
    //   }
    //   cerr << "after 150 simulations, the following respective scores have been tallied" << endl;
    //   for (int i: scores) {
    //     cerr << i << endl;
    //   }
    // }


    mr= moves[mx_i].first;
    mc = moves[mx_i].second;
   // cloned->move(false, testr,testc);
   }
     }
    // test clone

    og->move(false, mr,mc);

    cout << mr << " " << mc << endl;
  }
}
