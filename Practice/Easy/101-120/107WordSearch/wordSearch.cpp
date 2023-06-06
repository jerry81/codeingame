/*

Goal
Word Search is a type of puzzle that asks the player to search for various words within a grid of letters.
They can be vertical, horizonal, backwards, diagonal, etc.
If you are unfamiliar with it, see banner image and/or https://en.wikipedia.org/wiki/Word_search

But as a computer geek, that doesn't interest you; you want to program a way to find those words instead.

Input will be a square grid of size lines (each line is size letters long), followed by all the words to find.

Output the same square grid but hide any letters that aren't included in those words.

~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

NOTE: If you enjoy this puzzle, see this similar one: https://www.codingame.com/training/medium/hidden-word
Input
Line 1: An integer size, denoting the number of lines of input
Next size lines: A string ROW of that square grid
Next line: A string clues of all the words to find, separated by spaces
Output
size lines: ROW with the unused letters hidden.
In other words, all unused characters should be replaced by a space character.
Trailing spaces should NOT be trimmed.
Constraints
• Each clue of clues has only letters (no spaces).
• clues are given in capitalized case (but look for the all-caps version within the grid).
Example
Input
10
IPLUCJMCNY
AAFIIVADZN
TFUUSWGHWE
UBARTAGDOG
YSAJIGIUGR
DTEMRFEOKA
HYTEBKZCHM
BOMAHARBAL
WOOQPUERNE
HEZUYIJHNS
Abraham Bart Homer Lisa Maggie Marge Patty Selma
Output
  L   M
   I  A
    S G  E
 BARTAG  G
Y     I  R
 T  R E  A
  TE     M
  MAHARBAL
 O  P    E
H        S

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
    int size;
    vector<string> rows;
    vector<string> backwards;
    cin >> size; cin.ignore();
    for (int i = 0; i < size; i++) {
        string row;
        getline(cin, row);
        rows.push_back(row);
        reverse(row.begin(), row.end());
        backwards.push_back(row);
    }

    string clues;
    getline(cin, clues);



    vector<string> vertical;
    vector<string> verticalR;
    for (int i = 0; i < size; ++i) {
      string cur = "";
      for (int j = 0; j < size; ++j) {
        cur+=rows[j][i];
      }
      vertical.push_back(cur);
      reverse(cur.begin(), cur.end());
      verticalR.push_back(cur);
    }



    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "grid with unused letters hidden" << endl;
}