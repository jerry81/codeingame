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
  unordered_map<char, Node*> children;
};

Node* root = new Node();

void populate_tree_r(Node* cur, string remaining) {
  if (remaining.size() == 0) return;

  char c = remaining[0];
  bool new_node = cur->children.find(c) == cur->children.end();
  if (cur->children.empty() || new_node) {
     cur->children[c]=new Node();
  }

  string next_string = remaining.substr(1,string::npos);
  populate_tree_r(cur->children[c],next_string);
}

void tally_r(int& agg, Node* cur) {
  agg+=cur->children.size();
  for (pair<char, Node*> p: cur->children) {
    tally_r(agg, p.second);
  }
}

int main()
{
    int n;
    Node *ntest = new Node();
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        populate_tree_r(root, telephone);
    }
    int sum = 0;
    tally_r(sum,root);

    // The number of elements (referencing a number) stored in the structure.
    cout << sum << endl;
}