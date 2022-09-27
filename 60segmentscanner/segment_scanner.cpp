/*
Goal
Given an ASCII art representation of 7-segment display you need to convert it to a number.

Note: number should be converted as is, including leading zeroes.
Input
3 lines: 7-segment display image consisting only of vertical lines, underscores and spaces.
Length of every line is divisible by 3 (so trailing spaces are preserved).
Output
One line: The number. Leading zeros should be preserved.
Constraints
3 ≤ digit count ≤ 300
Example
Input
 _     _  _     _  _  _  _  _
| |  | _| _||_||_ |_   ||_||_|
|_|  ||_  _|  | _||_|  ||_| _|
Output
0123456789
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string line_1;
    getline(cin, line_1);
    string line_2;
    getline(cin, line_2);
    string line_3;
    getline(cin, line_3);
    cerr << "len is " << line_1.length() << endl;
    int len = line_1.length() / 3;
    for (int i = 0; i < len; ++i) {
      int startx = i * 3;
      int x2 = startx + 1;
      int x3 = startx + 2;
      if (line_2[startx] == '|') {
        if (line_3[startx] == '|') {
          if (line_2[x3] != '|') {
            // this is a 6
            cerr << "six detected at " << startx << endl;
          } else {
            if (line_2[x2] == '_') {
              cerr << " eight detected at " << startx << endl;
            } else {
              cerr << " zero detected " << startx << endl;
            }
          }
        } else {
          // 4,5,9
          if (line_2[x3] != '|') {
            cerr << "5 detected at " << startx << endl;
          } else {
            if (line_1[x2] == '_') {
              cerr << "9 discovered at " << startx << endl;
            } else {
              cerr << "4 discovered at " << startx << endl;
            }
          }
        }
      } else {
        // 1, 2, 3, 7
        if (line_3[x3] == '|') {
          // 1, 3, 7

        } else {
          // 2
          cerr << "2 discovered at " << startx << endl;
        }
      }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "number" << endl;
}