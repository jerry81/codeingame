/*
Goal
You are given a binary tree, where each node in the tree has two or zero children. If a node X has two children, they are called L Left & R Right children respectively. X is a Parent of L and R.

All trees have one root node, which is the only node without parent. All the other nodes have exactly one parent.

All tree nodes have assigned a unique number called index.
Given a tree and an index V, print the path from the root to the tree node with index V

A tree path starts at the root node, and it goes down by choosing the left or the right children until it arrives to the target value. Print the Left & Right elements from the path in a single line.

For instance, if we have the following tree.

     1
    / \
   /   \
  2     \
 / \     3
4   5   / \
       9   \
            8
           / \
          6   7

For this sample tree, Node 1 is the root, the only one without parents.
if V = 5, the Tree Path is Left Right
if V = 7, the Tree Path is Right Right Right
if V = 6, the Tree Path is Right Right Left
Input
Line 1: Integer N, the number of nodes in the tree.
Line 2: Integer V, the index of the target node.
Line 3: Integer M, the number of nodes with two children.
Followed by M lines containing three numbers P L R each:
P is the node index
L is the left children of P
R is the right children of P
Output
A sequence of Left and Right commands in a single line, representing the tree path from the root node, to the target node V.

If the target node V is the root, print Root.
Constraints
All N node indexes are unique and go from 1 to N.
All tree nodes belong to a single tree.

0 < N < 128
1 ≤ V, P, L, R ≤ N
Example
Input
3
2
1
1 2 3
Output
Left
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
struct TreeNode {
  int idx;
  TreeNode *parent;
  bool is_right; // 0 left 1 right
};

unordered_map<int,TreeNode*> tree_map;


int main()
{
    int n;
    cin >> n; cin.ignore();
    int v;
    cin >> v; cin.ignore();
    int m;
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        int p;
        int l;
        int r;
        cin >> p >> l >> r; cin.ignore();
        TreeNode *left = new TreeNode;
        TreeNode *right = new TreeNode;
        TreeNode *n = new TreeNode;
        if (tree_map.find(p) != tree_map.end()) {
          n = tree_map[p];
        } else {
          tree_map[p] = n;
        }

        n->idx = p;

        if (tree_map.find(l) != tree_map.end()) {
          left = tree_map[l];
        } else {
          tree_map[l] = left;
        }

        left->idx = l;
        left->parent=n;
        left->is_right=false;

        if (tree_map.find(r) != tree_map.end()) {
          right = tree_map[r];
        } else {
          tree_map[r]=right;
        }

        right->idx=r;
        right->parent=n;
        right->is_right=true;
    }

    TreeNode *next_node = tree_map[v];
    if (next_node->parent == nullptr) {
      cout << "Root" << endl;
      return 0;
    }
    bool started = false;
    while (next_node->parent != nullptr) {
      if (!started) {
        started = true;
      } else {
        cout << " ";
      }
      cout << (next_node->is_right ? "Right":"Left");
      next_node = next_node->parent;
    }
}

/*
  build the tree
    check if map has the item

*/