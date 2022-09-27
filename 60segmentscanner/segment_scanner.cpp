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

    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "number" << endl;
}