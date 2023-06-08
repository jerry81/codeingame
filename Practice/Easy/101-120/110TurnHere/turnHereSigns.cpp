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

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string input;
    getline(cin, input);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "The Turn Here Sign" << endl;
}