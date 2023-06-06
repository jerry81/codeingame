/*

The game mode is REVERSE: You do not have access to the statement. You have to guess what to do by observing the following set of tests:
01 Test 1
Input
Expected output
1234567890
(123) 456-7890
02 Test 2
Input
Expected output
1111111111
(111) 111-1111
03 Test 3
Input
Expected output
1211111111
(121) 111-1111
04 Test 4
Input
Expected output
9999999999
(999) 999-9999

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
    string s;
    getline(cin, s);

    string area = s.substr(0,3);
    string prefix = s.substr(3,3);
    string suffix = s.substr(6,4);


    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "(" << area << ") " << prefix << "-"<< suffix << endl;
}