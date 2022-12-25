/*

	The Goal
Upon discovering a new Maya site, hundreds of mathematics, physics and astronomy books have been uncovered.

The end of the world might arrive sooner than we thought, but we need you to be sure that it doesn't!

Thus, in order to computerize the mayan scientific calculations, you're asked to develop a program capable of performing basic arithmetical operations between two mayan numbers.
 	Rules
The mayan numerical system contains 20 numerals going from 0 to 19. Here's an ASCII example of their representation:
0	1	2	3	4	5	6	7	8	9
.oo.
o..o
.oo.
....	o...
....
....
....	oo..
....
....
....	ooo.
....
....
....	oooo
....
....
....	....
----
....
....	o...
----
....
....	oo..
----
....
....	ooo.
----
....
....	oooo
----
....
....
10	11	12	13	14	15	16	17	18	19
....
----
----
....	o...
----
----
....	oo..
----
----
....	ooo.
----
----
....	oooo
----
----
....	....
----
----
----	o...
----
----
----	oo..
----
----
----	ooo.
----
----
----	oooo
----
----
----A mayan number is divided into vertical sections. Each section contains a numeral (from 0 to 19) representing a power of 20. The lowest section corresponds to 200, the one above to 201 and so on.

Thereby, the example below is : (12 x 20 x 20) + (0 x 20) + 5 = 4805



To spice the problem up, the mayans used several dialects, and the graphical representation of the numerals could vary from one dialect to another.

The representation of the mayan numerals will be given as the input of your program in the form of ASCII characters. You will have to display the result of the operation between the two given mayan numbers. The possible operations are *, /, +, -
 	Game Input
Input
Line 1: the width L and height H of a mayan numeral.

H next lines: the ASCII representation of the 20 mayan numerals. Each line is (20 x L) characters long.

Next line: the amount of lines S1 of the first number.

S1 next lines: the first number, each line having L characters.

Next line: the amount of lines S2 of the second number.

S2 next lines: the second number, each line having L characters.

Last line: the operation to carry out: *, /, +, or -

Output
The result of the operation in mayan numeration, H lines per section, each line having L characters.
Constraints
0 < L, H < 100
0 < S1, S2 < 1000
The remainder of a division is always 0.
The mayan numbers given as input will not exceed 263.
Example
Input
4 4
.oo.o...oo..ooo.oooo....o...oo..ooo.oooo____o...oo..ooo.oooo____o...oo..ooo.oooo
o..o................____________________________________________________________
.oo.........................................____________________________________
................................................................________________
4
o...
....
....
....
4
o...
....
....
....
+
Output
oo..
....
....
....

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
    int l;
    int h;
    cin >> l >> h; cin.ignore();
    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
    }
    int s1;
    cin >> s1; cin.ignore();
    for (int i = 0; i < s1; i++) {
        string num_1line;
        cin >> num_1line; cin.ignore();
    }
    int s2;
    cin >> s2; cin.ignore();
    for (int i = 0; i < s2; i++) {
        string num_2line;
        cin >> num_2line; cin.ignore();
    }
    string operation;
    cin >> operation; cin.ignore();

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "result" << endl;
}