/*
Find the row that has the most of a given character. Then in that row find which
character appears the most.

Characters are case sensitive.

If there is a tie for the row, pick the row which appears first.

If there is a tie for the most common character in the row, return the character
with the lowest ascii ordinal value. Input c character to find n number of rows
Output
Most common character in row. Number of times that character appears. These
terms are separated by a space, not a newline. Constraints 1 < n <= 10 0 < row
length < 256 Example Input
a
3
ac
aabbbcc
ad
Output
b 3
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string search_character;
  getline(cin, search_character);

  int row_count;
  cin >> row_count;
  cin.ignore();
  unordered_map<string, int> freq;
  string maxrow = "";
  int maxrowcount = 0;
  for (int i = 0; i < row_count; i++) {
    string row;
    getline(cin, row);
    for (char c : row) {
      if (to_string(c) == search_character) freq[to_string(c)]++;
      if (freq[to_string(c)] > maxrowcount) {
        maxrowcount = freq[to_string(c)];
        maxrow = row;
      }
    }
  }
  unordered_map<string, int> freq;
  string maxChar = "";
  int maxCharCount = 0;
  for (char c : maxrow) {
    freq[to_string(c)]++;
    if (freq[to_string(c)] > maxCharCount) {
      maxCharCount = freq[to_string(c)];
      maxChar = to_string(c);
    }

    if (freq[to_string(c)] == maxCharCount && c < maxChar[0]) {
      maxCharCount = freq[to_string(c)];
      maxChar = to_string(c);
    }
  }

  // Write an answer using cout. DON'T FORGET THE "<< endl"
  // To debug: cerr << "Debug messages..." << endl;

  cout << "char charcount" << endl;
}
