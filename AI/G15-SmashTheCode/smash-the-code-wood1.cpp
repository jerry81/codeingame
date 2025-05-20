#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <queue>

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

int flood_fill(vector<string> &board, int col, char color) {
  // place peice
  vector<string> board_after = board;
  queue<pair<int,int>> q;
  for (int i = 11; i >=0; --i) {
    if (board[i][col] == '.') {
      if (i >= 10) {
        return 0;
      } else {
        board_after[i][col] = color;
        q.push({i,col});
        board_after[i-1][col] = color;
        q.push({i-1,col});
        break;
      }
    }
  }

  int connected = 0;
  while (!q.empty()) {
    pair<int,int> cur = q.front();
    q.pop();

    int row = cur.first;
    int col = cur.second;

    // Skip if out of bounds or not the same color
    if (row < 0 || row >= 12 || col < 0 || col >= 6 || board_after[row][col] != color) {
      continue;
    }

    // Mark as visited and increment count
    board_after[row][col] = 'V';
    connected++;

    // Check all 4 directions
    q.push({row+1, col}); // down
    q.push({row-1, col}); // up
    q.push({row, col+1}); // right
    q.push({row, col-1}); // left
  }

  return connected;
}

int get_height(vector<string> &board, int col) {
  for (int i = 0; i < 12; ++i) {
    if (board[i][col] != '.') {
      return 12-i;
    }
  }
  return 0;
}

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

        // for (int i = 0; i < 12; ++i) {
        //   cerr << endl;
        //   string row = board[i];
        //   for (char c:row) {
        //     cerr <<c;
        //   }
        // }

        for (int i = 0; i < 6; ++i) {
          cerr << "col " << i << "'s height is " << get_height(board, i) << endl;
        }


        // rainbow colors 1 and 2 on first 3 rows
        switch (cur_color) {
         case 1: {
            if (!board_colors[1].empty() && board_colors[1][0] == 2) {
              cout << "1 1" << endl;
              break;
            }
            cout << "0 1" << endl;
            break;
          } case 2: {
            if (board_colors[1].size() > 1) {
              cout << "2 1" << endl;
              break;
            }

            cout << "1 1" << endl;
            break;
          } case 3: {
             cout << "2 0" << endl;
              break;
          } case 4: {
             cout << "3 0" << endl;
              break;
          } default: {
             cout << "4 0" << endl;
              break;
          }
        }
    }
}