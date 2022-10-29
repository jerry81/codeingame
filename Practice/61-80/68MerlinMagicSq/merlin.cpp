/*

Goal
Background and Symbols:
Merlin was a hand-held electronic gaming-device from 1978. It played multiple games with the kids back then, including "Magic Square"

We will refer to each location (aka button) within Merlin's Magic Square using this numbering system (which is the same as the instructions from the original game):
1 2 3
4 5 6
7 8 9
(This is also shown in the banner image)

asterisk * = lit
tilde ~ = unlit (not lit)

Situation:
You and your friend Lizzo are given a starting "Merlin's Magic Square", which consists of:
3 rows of 3 characters (characters are separated by a space), such as....
~ * ~
~ ~ ~
~ * ~
And y'all want to solve it by changing it into The Solved State, which is:
* * *
* ~ *
* * *

Your Task:
Lizzo presses some buttons, such as 884 (meaning: first she presses 8, then 8, then 4).
You only need to press one more button to solve it; what button is that?


The Rules of Merlin's Magic Square:
• When you press a corner button (1, 3, 7 or 9), it reverses the 4 buttons in the 2x2 corner square it's in
• When you press a side button (2, 4, 6 or 8), it reverses the 3 buttons in that border row
• When you press the middle button (5), it reverses the 5 buttons in the middle "+" shape
• ("Reverse" means that if it's lit, it becomes unlit; if it's unlit, it becomes lit.)
• The Solved State is when all buttons are lit except for the middle one (5) ; this is shown above in blue


See someone play it, or play it yourself, to better understand:
• 1-minute long example of a person playing this: https://youtu.be/M2pSiuIKn6k?t=462
• Play it yourself in this simulator I made: https://openprocessing.org/sketch/1643473
Input
Lines 1 to 3: The starting Merlin's Magic Square, in 3 rows
Line 4: The numbers of the buttons that Lizzo presses
Output
The number of the final button you should press to solve it
Constraints
Lizzo presses at least one button
Example
Input
~ * ~
~ ~ ~
~ * ~
884
Output
6

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

string g1;
string g2;
string g3;

void update(int i) {
    switch (i) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 8:
          break;
        default:
          return;
    }
}

int main()
{
    string row_1;
    getline(cin, row_1);
    g1 = row_1;
    string row_2;
    getline(cin, row_2);
    g2 = row_2;
    string row_3;
    getline(cin, row_3);
    g3 = row_3;
    string all_buttons_pressed;
    getline(cin, all_buttons_pressed);
    for (char c:all_buttons_pressed) {
        int as_i = c - '0';
        cerr << "as_i is " << as_i << endl;
        update(as_i);
    }
    cerr << g1 << endl << g2 << endl g3 << endl;
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer (a single digit)" << endl;
}