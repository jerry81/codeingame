/*

Goal
Secretary of Transportation Pete has asked you to program electronic signs to communicate to drivers that they need to turn left or turn right.

Pete wants lots of options for the signs, so the input is:
• direction -- which is either left or right
• howManyArrows
• heightOfArrows
• strokeThicknessOfArrows
• spacingBetweenArrows
• additionalIndentOfEachLine -- this will determine if the shape of the arrows is subtle or more pointy

However, Pete is also a minimalist, so all that input will be in a single string of data.

Note:
• Left turn signs will consist of < and spaces only
• Right turn signs will consist of > and spaces only
Input
Line 1: string allInput, that is composed of direction howManyArrows heightOfArrows strokeThicknessOfArrows spacingBetweenArrows additionalIndentOfEachLine
Output
heightOfArrows lines: the Turn Here sign
Constraints
The input string allInput is a single word followed by 5 integers.
All are separated by a single space.
All integers are > 0

heightOfArrows is an odd number, ≥ 5
Example
Input
right 3 9 8 6 2
Output
>>>>>>>>      >>>>>>>>      >>>>>>>>
  >>>>>>>>      >>>>>>>>      >>>>>>>>
    >>>>>>>>      >>>>>>>>      >>>>>>>>
      >>>>>>>>      >>>>>>>>      >>>>>>>>
        >>>>>>>>      >>>>>>>>      >>>>>>>>
      >>>>>>>>      >>>>>>>>      >>>>>>>>
    >>>>>>>>      >>>>>>>>      >>>>>>>>
  >>>>>>>>      >>>>>>>>      >>>>>>>>
>>>>>>>>      >>>>>>>>      >>>>>>>>

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


vector<string> split(string str) {
  // Returns first token
  vector<string> ret;
  char *token = strtok(str.data(), " ");

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, " ");
  }

  return ret;
}


int main()
{
    string input;
    getline(cin, input);

    vector<string> spl = split(input);

    string direction = spl[0];
    int numArrows = spl[1][0] - '0';
    int height = spl[2][0] - '0';
    int thickness = spl[3][0] - '0';
    int spacing = spl[4][0] - '0';
    int indent = spl[5][0] - '0';

    char atom = direction == "right" ? '>' : '<';
    string molecule = "";
    for (int i = 0; i < thickness; ++i) {
      molecule+=atom;
    }
    string compound = "";
    string spacingStr = "";
    for (int i = 0; i < spacing; ++i) {
      spacingStr+=' ';
    }
    for (int i = 0; i < numArrows-1; ++i) {
      compound += molecule;
      compound += spacingStr;
    }
    compound += molecule;
    int mid = height/2;
    string indentTemplate = "";
    for (int i = 0; i < indent; ++i) {
      indentTemplate+=' ';
    }
    string curindent = "";
    for (int i = 0; i < height; ++i) {
      cout << curindent + compound << endl;
      if (mid > i) {
        curindent+=indentTemplate;
      } else {
        curindent = curindent.substr(0, curindent.size()-indent);
      }
    }
}