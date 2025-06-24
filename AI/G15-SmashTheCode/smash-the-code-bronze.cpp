#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>
#include <set>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// Function to generate a random number between min and max (inclusive)
// int getRandomNumber(int min, int max) {
//     // Create a random device
//     random_device rd;
//     // Create a Mersenne Twister random number generator
//     mt19937 gen(rd());
//     // Create a uniform distribution
//     uniform_int_distribution<> distrib(min, max);
//     // Generate and return the random number
//     return distrib(gen);
// }

// vector<string> test_at(int column, int colora, int colorb, vector<string>& curr) {
//     vector<string> ret = curr;  // Copy the current board
//     bool placed = false;

//     // Find the first non-empty position from bottom
//     for (int i = 11; i >= 0; --i) {
//         if (curr[i][column] == '.') {
//             // If we can place both blocks
//             if (i >= 1) {
//                 ret[i] = curr[i];
//                 ret[i][column] = colora + '0';  // Convert int to char
//                 ret[i-1] = curr[i-1];
//                 ret[i-1][column] = colorb + '0';  // Convert int to char
//                 placed = true;
//             }
//             break;
//         }
//     }

//     // If we couldn't place the blocks, mark as invalid
//     if (!placed) {
//         ret[0] = "x";
//     }

//     return ret;
// }

vector<int> get_colors(vector<string> &board, int col) {
  vector<int> res;
  char prev_color = '.';  // Initialize with empty space
  for (int i = 0; i < 12; ++i) {
    if (board[i][col] != prev_color && board[i][col] != '.' && board[i][col] != '0') {
      res.push_back(board[i][col] - '0');  // Convert char to int
      prev_color = board[i][col];
    }
  }
  return res;
}

vector<string> floodfill(vector<string> board, char col, char rot, char colorA, char colorB) {
  pair<vector<string>,int> result = process(place_peice(board, col, rot, colorA, colorB));
}

vector<string> place_peice(vector<string> board, char col, char rot, char colorA, char colorB) {
  vector<string> result = board;
  int column = col - '0';  // Convert char to int

  // Find the first empty position from bottom
  int empty_row = -1;
  for (int i = 11; i >= 0; --i) {
    if (board[i][column] == '.') {
      empty_row = i;
      break;
    }
  }

  // If no empty position found, return original board
  if (empty_row == -1) {
    return result;
  }

  // Place blocks based on rotation
  switch (rot) {
    case '0': {  // Vertical placement, colorA on top
      if (empty_row >= 1) {
        result[empty_row] = board[empty_row];
        result[empty_row][column] = colorB;
        result[empty_row-1] = board[empty_row-1];
        result[empty_row-1][column] = colorA;
      }
      break;
    }
    case '1': {  // Horizontal placement, colorA on left
      if (column < 5) {
        result[empty_row] = board[empty_row];
        result[empty_row][column] = colorA;
        result[empty_row][column+1] = colorB;
      }
      break;
    }
    case '2': {  // Vertical placement, colorB on top
      if (empty_row >= 1) {
        result[empty_row] = board[empty_row];
        result[empty_row][column] = colorA;
        result[empty_row-1] = board[empty_row-1];
        result[empty_row-1][column] = colorB;
      }
      break;
    }
    case '3': {  // Horizontal placement, colorA on right
      if (column > 0) {
        result[empty_row] = board[empty_row];
        result[empty_row][column] = colorB;
        result[empty_row][column-1] = colorA;
      }
      break;
    }
  }
  return result;
}

pair<vector<string>, int> eliminate(vector<string> board) {
    int rows = 12, cols = 6;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<bool>> to_remove(rows, vector<bool>(cols, false));
    vector<int> group_sizes;
    set<int> colors_cleared;
    int total_blocks_cleared = 0;
    int GB = 0; // Group Bonus
    int CB = 0; // Color Bonus
    int CP = 0; // Chain Power (handled in process, so 0 here)
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            char color = board[r][c];
            if (color >= '1' && color <= '5' && !visited[r][c]) {
                // BFS to find group
                vector<pair<int, int>> group;
                queue<pair<int, int>> q;
                q.push({r, c});
                visited[r][c] = true;
                while (!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    group.push_back({cr, cc});
                    for (int d = 0; d < 4; ++d) {
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] && board[nr][nc] == color) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                if (group.size() >= 4) {
                    // Mark for removal
                    for (auto [gr, gc] : group) {
                        to_remove[gr][gc] = true;
                    }
                    group_sizes.push_back(group.size());
                    colors_cleared.insert(color - '0');
                    total_blocks_cleared += group.size();
                }
            }
        }
    }

    // Remove marked blocks
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (to_remove[r][c]) {
                board[r][c] = '.';
            }
        }
    }

    // Calculate Group Bonus (GB)
    for (int sz : group_sizes) {
        if (sz == 4) GB += 0;
        else if (sz == 5) GB += 1;
        else if (sz == 6) GB += 2;
        else if (sz == 7) GB += 3;
        else if (sz == 8) GB += 4;
        else if (sz == 9) GB += 5;
        else if (sz == 10) GB += 6;
        else if (sz >= 11) GB += 8;
    }

    // Color Bonus (CB)
    if (colors_cleared.size() == 1) CB = 0;
    else if (colors_cleared.size() == 2) CB = 2;
    else if (colors_cleared.size() == 3) CB = 4;
    else if (colors_cleared.size() == 4) CB = 8;
    else if (colors_cleared.size() == 5) CB = 16;

    int bonus = CP + CB + GB;
    if (bonus < 1) bonus = 1;
    if (bonus > 999) bonus = 999;
    int score = (10 * total_blocks_cleared) * bonus;

    return {board, score};
}

vector<string> fall(vector<string> board) {
    int rows = 12, cols = 6;
    for (int c = 0; c < cols; ++c) { // each column
        int write_row = rows - 1; // start at top row
        for (int r = rows - 1; r >= 0; --r) { // drop the block one row at a time
            if (board[r][c] != '.') { // colored block found
                board[write_row][c] = board[r][c]; // drop the block
                if (write_row != r) {
                    board[r][c] = '.';
                }
                --write_row;
            }
        }
        // Fill the rest with '.' if any
        for (int r = write_row; r >= 0; --r) {
            board[r][c] = '.';
        }
    }
    return board;
}

pair<vector<string>, int> process(vector<string> board) {
  int total_score = 0;
  int prev_score = -1;
  vector<string> ret_board = board;
  while (total_score != prev_score) {
    prev_score = total_score;
    auto [v, i] = eliminate(ret_board);
    total_score += i;
    ret_board = fall(v);
  }
  return {ret_board, total_score};
}

int main()
{
    vector<string> board(12);  // Initialize with 12 empty strings

    // game loop
    while (1) {
        int cur_color = 0;
        for (int i = 0; i < 8; i++) {
            int color_a; // color of the first block
            int color_b; // color of the attached block
            cin >> color_a >> color_b; cin.ignore();
            if (i == 0) {
              cur_color = color_a;
            }

        }
        int score_1;
        cin >> score_1; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row; // One line of the map ('.' = empty, '0' = skull block, '1' to '5' = colored block)
            cin >> row; cin.ignore();
            board[i] = row;
        }
        // for (string s: board) {
        //     cerr << s << endl;
        // }
        // for (int c = 0; c < 6; ++c) {
        //     cerr << "testing col " << c << endl;
        //     vector<string> preview = test_at(c, ca, cb, board);
        //     for (const string& s : preview) {
        //         cerr << s << endl;
        //     }
        // }

        int score_2;
        cin >> score_2; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row;
            cin >> row; cin.ignore();
        }

        vector<vector<int>> board_colors;
        for (int i = 0; i < 6; ++i) {
            vector<int> v = get_colors(board, i);
            board_colors.push_back(v);
        }

        // for (int i = 0; i < 6; ++i) {
        //   cerr << "printing column colors:" << i << endl;
        //   vector<int> v = board_colors[i];
        //   for (int color : v) {
        //       cerr << "color: " << color << endl;
        //   }
        // }


        // rainbow colors 1 and 2 on first 3 rows
        switch (cur_color) {
          case 1: {
            if (!board_colors[1].empty() && board_colors[1][0] == 2) {
              cout << 1 << endl;
              break;
            }
            cout << 0 << endl;
            break;
          } case 2: {
            if (board_colors[1].size() > 1) {
              cout << 2 << endl;
              break;
            }

            cout << 1 << endl;
            break;
          } case 3: {
             cout << 3 << endl;
              break;
          } case 4: {
             cout << 4 << endl;
              break;
          } default: {
             cout << 5 << endl;
              break;
          }
        }
    }
}