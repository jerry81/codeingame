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
        cerr << "color is " << cur_color << endl;
        int score_1;
        cin >> score_1; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row; // One line of the map ('.' = empty, '0' = skull block, '1' to '5' = colored block)
            cin >> row; cin.ignore();
            board[i] = row;
        }
        for (string s: board) {
            cerr << s << endl;
        }
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

        // rainbow colors 1 and 2 on first 3 rows

        switch (cur_color) {
          case 1: {
            if (board[11][0] == '.') {
              cout << 0 << endl;
              break;
            }
            if (board[11][1] == '2') {
              if (board[9][1] == '1') {
                cout << 2 << endl;
                break;
              }
            }
            cout << 1 << endl;
            break;
          } case 2: {
            if (board[11][0] == '1' && board[9][0] == '.') {
              cout << 0 << endl;
              break;
            }
            if (board[11][0] == '1') {
              if (board[9][0] == '0') {
                cout << 0 << endl;
                break;
              }

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