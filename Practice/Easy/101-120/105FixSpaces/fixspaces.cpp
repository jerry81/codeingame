/*

	Goal
You are given two strings, the first contains the original sentence, with words in the right order but no spaces. The second has the words in random order but with spaces to differentiate them. Fix the original sentence by adding spaces where they should be.

Every test has at least one solution, but there are some cases where the original sentence can not unambiguously be deciphered. In those cases print Unsolvable.

NB: Tests 1-14 cover simple cases and should help you debug your program. Tests 15-16 check the performance.
Input
Line 1 : A string. The original sentence, with words in the right order but no spaces.
Line 2 : A string containing the words in random order but with spaces to differentiate them.
Output
The original sentence with the necessary spaces added to it or the string Unsolvable.
Constraints
The original string only contains uppercase letters.
The words string only contains uppercase letters and spaces.
Each word in words appears the same number of times in words and in original.
Each string is at most 1000 characters long.
The number of words is at most 200.
Example
Input
ABCDEFGHIJ
DEF J ABC GHI
Output
ABC DEF GHI J

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
    string original;
    getline(cin, original);
    string words;
    getline(cin, words);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "original sentence with spaces" << endl;
}