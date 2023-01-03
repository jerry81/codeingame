/*

	The Goal
Bobnet is responding to your intrusion and has activated additional defenses:
Most of the links have been reinforced: your virus no longer has the possibility to destroy a link between two ordinary nodes, it can now only sever links leading to gateways. If it attempts to cut a link between two ordinary nodes it will be detected and deleted.
Nodes may now be connected to up to two gateways!
There are six new tests to pass in this final confrontation.

Do not hesitate to copy/paste your code from level 1 to level 2.

Recap:

Your virus has caused a backdoor to open on the Bobnet network enabling you to send new instructions in real time.

You decide to take action by stopping Bobnet from communicating on its own internal network.

Bobnet's network is divided into several smaller networks, in each sub-network is a Bobnet agent tasked with transferring information by moving from node to node along links and accessing gateways leading to other sub-networks.

Your mission is to reprogram the virus so it will sever links in such a way that the Bobnet Agent is unable to access another sub-network thus preventing information concerning the presence of our virus to reach Bobnet's central hub.
 	Rules
For each test you are given:
A map of the network.
The position of the exit gateways.
The starting position of the Bobnet agent.

Each game turn:
First off, you sever one of the given links in the network.
Then the Bobnet agent moves from one Node to another accessible Node.

Bobnet agent

Gateway

Victory Conditions
The Bobnet agent cannot reach an exit gateway

Lose Conditions
The Bobnet agent has reached a gateway
 	Example
4 4 1
0 1
0 2
1 3
2 3
3
Initialization input

Text representation of the network used in this example. There are 4 nodes, 4 links and 1 gateway. The next 4 lines describe the links. The last integer is the index of the exit node.

Turn 1
The Bobnet agent starts at node 0 (SI = 0). Our virus cut the link between the nodes 1 and 3.

Turn 2
The Bobnet agent moves to node 2 (SI = 2). Our virus cut the link between the nodes 2 and 3.

Turn 3
The Bobnet agent has been cut off from the exit, you have won !
 	Note
The tests provided are similar to the validation tests used to compute the final score but remain different.
 	Game Input
The program must first read the initialization data from standard input. Then, within an infinite loop, read the data from the standard input related to the current state of the Bobnet agent and provide to the standard output the next instruction.
Initialization input
Line 1: 3 integers N L E
- N, the total number of nodes in the level, including the gateways.
- L, the number of links in the level.
- E, the number of exit gateways in the level.

Next L lines: 2 integers per line (N1, N2), indicating a link between the nodes indexed N1 and N2 in the network.

Next E lines: 1 integer EI representing the index of a gateway node.

Input for one game turn
Line 1: 1 integer SI, which is the index of the node on which the Bobnet agent is positioned this turn.
Output for one game turn
A single line comprised of two integers C1 and C2 separated by a space. C1 and C2 are the indices of the nodes you wish to sever the link between.
Constraints
2 ≤ N ≤ 500
1 ≤ L ≤ 1000
1 ≤ E ≤ 20
0 ≤ N1, N2 < N
0 ≤ SI < N
0 ≤ C1, C2 < N
Response time per turn ≤ 150ms

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
  int index;
  unordered_map<int, bool> links;
  int exit_count;
  bool isExit;
  Node(int i = -1, int ex = 0, int d = 0, bool e=false) : index(i), exit_count(ex), isExit(e) {};
  void addLink(int i) {
    if (links.find(i) == links.end()) {
      links[i] = true;
    }
  }
  void make_exit() {
    isExit = true;
  }
};

unordered_map<int, Node> nodes;
vector<int> exits;

bool dfs(int target, unordered_map<int, bool> visited, int cur, vector<int> &path) {
  if (cur == target) {
    path.push_back(cur);
    return true;
  }

  for (auto a: nodes[cur].links) {
    visited[a.first] = true;
    if ()
  }
  return false;
}

int bfs(int target, unordered_map<int, bool> visited, int cur) {
  vector<int> path;
  if (cur == target) return 0;

  queue<int> neighbors;
  bool found = false;

  neighbors.push(cur);
  int dist = 0;
  while (!found) {
    queue<int> next_neighbors;
    while (!neighbors.empty()) {
      int item = neighbors.front();
      if (item == target) return dist;
      visited[item] = true;
      neighbors.pop();
      for (auto i:nodes[item].links) {
        if (visited.find(i.first) == visited.end()) {
          next_neighbors.push(i.first);
        }
      }
    }
    dist+=1;
    neighbors = next_neighbors;
  }

}

void sever_link(int a, int b) {
            nodes[a].links.erase(b);
            nodes[b].links.erase(a);
            if (nodes[a].isExit) --nodes[b].exit_count;
            if (nodes[b].isExit) --nodes[a].exit_count;
}

int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        if (nodes.find(n1) == nodes.end()) {
          nodes[n1] = Node(n1, false);
        }
        nodes[n1].addLink(n2);
        if (nodes.find(n2) == nodes.end()) {
          nodes[n2] = Node(n2, false);
        }
        nodes[n2].addLink(n1);
        cerr << "n1 " << n1 << " n2 " << n2 << endl;
    }

    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        nodes[ei].make_exit();
        for (auto a: nodes[ei].links) {
          nodes[a.first].exit_count+=1;
        }
        exits.push_back(ei);
    }
    for (int e: exits) {
      cerr << "exit " << e << endl;
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();
        int lowest_len = 1000;
        int most_gw = 0;
        int closest_a;
        int closest_b;
        for (int ex : exits) {
          Node n = nodes[ex];
          if (n.links.find(si) != n.links.end()) {
            closest_a = si;
            closest_b = ex;
            break;
          } else {
            for (auto a : n.links) {
              unordered_map<int, bool> visited;
              visited[ex] = true;
              int dist = bfs(si, visited, a.first);

              cerr << "dist to " << a.first << " is " << dist << endl;
              cerr << "exit count is " << nodes[a.first].exit_count << endl;
              if (nodes[a.first].exit_count >= most_gw)  {
                if (lowest_len >= dist) {
                  lowest_len = dist;
                  closest_a = ex;
                  closest_b = a.first;
                  most_gw = nodes[a.first].exit_count;
                }
              }
            }
          }
        }
        sever_link(closest_a, closest_b);
        // Example: 3 4 are the indices of the nodes you wish to sever the link between
        cout << closest_a << " " << closest_b << endl;
    }
}

/*

try - consider # of connected exits in distance calc
- if connected, doesn't count

*/