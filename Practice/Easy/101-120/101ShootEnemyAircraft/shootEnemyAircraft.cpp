/*

	Goal
There are enemy aircraft (> or <) in the sky (made of .). Each turn they move one cell forward. You are in charge of shooting them with a surface-to-air missile (^). You can only shoot vertically. Each turn your missiles move one cell up.

Note: When you shoot, the missile appears at the same altitude as the launcher. Each turn, the missile moves one cell up.

You have to print, each turn, if you WAIT or if you SHOOT. You have to shoot all the enemy aircraft, and your stock is just enough, so don't SHOOT if you can't hit an aircraft. After shooting every missile, do not print the last WAITs.
Input
Line 1: the number n of lines
n following lines : the description of the situation.
Output
As many lines as necessary, made of WAIT or SHOOT, one instruction per line.
Constraints
2 <= n <= 10
The sky is made of n-1 lines, the last line is the ground.
A sky line is made of . if no aircraft, > or < for each aircraft.
The ground line is made of _, and ^ for the surface-to-air missile launcher.
There is only one missile launcher, and it's always on the ground.
The lengths of the lines are always the same, and <= 40.
Example
Input
6
....................
.>..................
...................<
....................
....................
_________^__________
Output
WAIT
WAIT
WAIT
SHOOT
WAIT
WAIT
SHOOT

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
    int n;
    cin >> n; cin.ignore();

    vector<int> right;
    int len = 0;
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line; cin.ignore();
        len = line.length();
        for (int j = 0; j < line.length(); ++j) {
        }
    }



    cout << "WAIT" << endl;
    cout << "SHOOT" << endl;
}