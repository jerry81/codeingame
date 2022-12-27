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
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<string, int> lookup;
unordered_map<int, string> revlookup;
vector<int> convert_base_20(int decimal) {
  vector<int> res;
  while (decimal > 0) {
    res.push_back(decimal%20);
    decimal = decimal / 20;
  }
  if (res.empty()) {
    res.push_back(0);
  }
  return res;
}

void print_mayan(int base20, int l, int h) {
  string hashed = revlookup[base20];
  for (int i = 0; i < h; ++i) {
    cout << hashed.substr(i*l, l) << endl;
  }
}

int main()
{
    int l;
    int h;
    cin >> l >> h; cin.ignore();
    vector<string> fullinput;


    for (int i = 0; i < h; i++) {
        string numeral;
        cin >> numeral; cin.ignore();
        fullinput.push_back(numeral);
    }
    cerr << "len is " << fullinput[0].size() << endl;
    for (int i = 0; i < 20; ++i) {
      string hash = "";
      for (int j = 0; j < h; ++j) {
        hash+=fullinput[j].substr(i*l, l);
      }
      lookup[hash] = i;
      revlookup[i] = hash;
    }
    int s1;
    cin >> s1; cin.ignore();
    int units1 = s1/l;
    cerr << "units 1 are " << units1 << endl;
    vector<string> num1full;
    for (int i = 0; i < s1; i++) {
        string num_1line;
        cin >> num_1line; cin.ignore();
        num1full.push_back(num_1line);
    }
    vector<int> num1;
    for (int i = 0; i < units1; ++i) {
      string hash = "";
      for (int j = 0; j < h; ++j) {
        hash+=num1full[i*h+j];
      }
      num1.push_back(lookup[hash]);
    }

    int as_decimal_1 = 0;
    for (int i = 0; i < num1.size(); ++i) {
      int idx = num1.size() - 1 - i;
      as_decimal_1+=num1[idx]*pow(20, i);
    }
    int s2;
    vector<string> num2full;
    cin >> s2; cin.ignore();
    int units2 = s2/l;
    for (int i = 0; i < s2; i++) {
        string num_2line;
        cin >> num_2line; cin.ignore();
        num2full.push_back(num_2line);
    }

    vector<int> num2;
    for (int i = 0; i < units2; ++i) {
      string hash = "";
      for (int j = 0; j < h; ++j) {
        hash+=num2full[i*h+j];
      }
      num2.push_back(lookup[hash]);
    }

    int as_decimal_2 = 0;
    for (int i = 0; i < num2.size(); ++i) {
      int idx = num2.size() - 1 - i;
      as_decimal_2+=num2[idx]*pow(20, i);
    }
    int result = 0;
    string operation;
    cin >> operation; cin.ignore();
    if (operation == "+") {
      result = as_decimal_1 + as_decimal_2;
    } else if (operation == "-") {
      result = as_decimal_1 - as_decimal_2;
    } else if (operation == "*") {
      result = as_decimal_1 * as_decimal_2;
    } else {
      result = as_decimal_1 / as_decimal_2;
    }
    cerr << "result is " << result << endl;
    vector<int> res = convert_base_20(result);
    for (int i : res ) {
      cerr << "res item " << i << endl;
    }
    reverse(res.begin(), res.end());

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int i: res) {
        print_mayan(i,l,h);
    }

}