/*

The Goal
By joining the iDroid smartphone development team, you have been given the responsibility of developing the contact manager. Obviously, what you were not told is that there are strong technical constraints for iDroid: the system doesn’t have much memory and the processor is as fast as a Cyrix from the 90s...

In the specifications, there are two points in particular that catch your attention:

1. Intelligent Assistance for entering numbers
The numbers corresponding to the first digits entered will be displayed to the user almost instantly.



2. Number storage optimization
First digits which are common to the numbers should not be duplicated in the memory.

Fortunately, the specifications also have this little chart to guide you in the implementation:


Fig 1. Structure of data to stock phone numbers on iDroid

Your task is to write a program that displays the number of items (which are numbers) required to store a list of telephone numbers with the structure presented above.
 	Game Input
Input
Line 1: The number N of telephone numbers.

N following lines: Each line contains a phone number, with a maximum length L. Telephone numbers consist of only the digits 0 to 9 included, without any spaces.

Output
The number of elements (referencing a number) stored in the structure.
Constraints
0 ≤ N ≤ 10000
2 ≤ L ≤ 20
Examples
Input
1
0467123456
Output
10
Input
2
0123456789
1123456789
Output
20
Input
2
0123456789
0123
Output
10
Input
5
0412578440
0412199803
0468892011
112
15
Output
28

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Node {
  unordered_map<int, Node*> children;
};

Node root;

int main()
{
    int n;
    Node *ntest = new Node();
    cerr << "expect 0, no seg: "<<ntest->children.size()<<endl;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        for (char c: telephone) {
          int as_i = c - '0';
          if (root.empty()) {
            Node n;
            roots[i] = n;
          }

          if (roots.find(as_i) == roots.end()) {
            // not found
          }

          // found
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // The number of elements (referencing a number) stored in the structure.
    cout << "number" << endl;
}