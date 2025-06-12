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

pair<vector<string>, int> process(vector<string> board) {
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