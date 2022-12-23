/*

	The Goal
The saying "Dwarfs standing on the shoulders of giants" refers to the importance of being able to build upon the work of our predecessors.

When we read texts, we often only get a small glance of this dependence: this person influenced that person. Thereafter, we learn that the second person, in turn influenced a third and so on. In this exercise we’re interested in the chain of influence and more precisely in finding the longest possible chain.​
 	Rules
We choose to represent each person by a distinct integer. If person #1 has influenced persons #2 and #3 and person #3 has influenced #4 then there is a succession of thoughts between #1, #3 and #4. In this case, it’s the longest succession and the expected result will be 3, since it involves 3 people.



If we were to complete this example when we learn that person #2 also influenced persons #4 and #5, then the longest succession will still have a length of 3, but there will now be several of them.



If we now add that person #10 influenced person #11, the result remains 3. However, as soon as we learn that #10 also influenced #1 and #3, then the result becomes 4, since there is now a succession involving 4 people, which is #10, #1, #2, #5.


Note: It takes time for a thought to influence others. So, we will suppose that it is not possible to have a mutual influence between people, i.e. If A influences B (even indirectly through other people), then B will not influence A (even indirectly). Also, you can not influence yourself.

 	Game Input
Input
Line 1: The number N of relationships of influence.

N following lines: a relationship of influence between two people in the form of X (whitespace) Y, which indicates that X influences Y. The relationships of influence are listed in any order.

Output
The number of people involved in the longest succession of influences.
Constraints
0 < N < 10000
0 < X, Y < 10000
Examples
Input
3
1 2
1 3
3 4
Output
3

Input
8
1 2
1 3
3 4
2 4
2 5
10 11
10 1
10 3
Output
4

Input
4
2 3
8 9
1 2
6 3
Output
3

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
  vector<int> parents;
  int max_rel;
  int id;

  Node(int i = -1, int mr = 0) :
    id(i), max_rel(mr) {}
};

unordered_map<int, Node*> node_lookup;

int walk_parents_r(Node* n) {
  int cur_rel = n->max_rel;
  if (n->parents.empty() == 0) return max(cur_rel+1, n->max_rel);

  int _max = 0;
  for (int id: n->parents) {
    node_lookup[id]->max_rel = max(n->max_rel, cur_rel + 1);
    int _max_r = walk_parents_r(node_lookup[id]);
    if (_max_r > _max) {
      _max = _max_r;
    }
  }
  return _max;
}

int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();

    int max_rel_g = 0;
    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();
        Node* xn;
        Node* yn;

        if (node_lookup.find(y) == node_lookup.end()) {
          yn = new Node(y,0);
          node_lookup[y] = yn;
        } else {
          yn = node_lookup[y];
        }

        if (node_lookup.find(x) == node_lookup.end()) {
          xn = new Node(x,1);
          node_lookup[x] = xn;
        } else {
          xn = node_lookup[x];
        }

        xn->max_rel = max(xn->max_rel, yn->max_rel + 1);



        yn->parents.push_back(xn->id);
        int _max_rel = walk_parents_r(xn);
        // walk parents
        if (_max_rel > max_rel_g) max_rel_g = _max_rel;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // The number of people involved in the longest succession of influences
    cout << max_rel_g << endl;
}