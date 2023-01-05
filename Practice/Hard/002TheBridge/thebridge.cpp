/*

The program:

There are 4 lanes on the bridge road and 1 to 4 bikes to control. There can only
be one moto per lane and they are always vertically aligned.

Each game turn, you can send a single instruction to every bike. Since  the
bikes operate on the same frequency, they will all synchronize on the commands
you send them.

The possible commands are:
SPEED to speed up by 1.
SLOW to slow down by 1.
JUMP to jump.
WAIT to go straight on.
UP to send all motorbikes one lane up.
DOWN to send all motorbikes one lane down.

The starting speeds of the bikes are synced, and can be 0. After every game
turn, the bikes will move a number of squares equal to their current speed
across the X axis.

The UP and DOWN instructions will make the bikes move across the Y axis in
addition to the movement across the X axis (Y = 0 corresponds to the highest
lane). If a motorbike is prevented from moving up or down by the bridge's guard
rails, none of the bikes will move on the Y axis that turn.

When a motorbike goes in a straight line and does not jump, if there is a hole
between the current position and the next position (after the move), then the
motorbike is lost forever. For example, if X=2 and S=3, the next position of the
bike will have X=5: if there is a hole in X=3, X=4 or X=5, the bike will be
destroyed.

Going up or down will put you at risk of falling in any hole situated in the
black zone (consider the holes on the current and next lane):


The mission is a success if the minimum amount of required bikes gets to the far
side of the bridge. You fail if too many motorbikes fall into holes. You fail if
the motorbikes do not cross the entire bridge after 50 turns. The program must
first read the initialization data from standard input. Then, within an infinite
loop, read the data from the standard input related to the bike's current state
and provide to the standard output the next instruction.

The tests provided are similar to the validation tests used to compute the final
score but remain different. INITIALIZATION INPUT: Line 1 : M the amount of
motorbikes to control. Line 2 : V the minimum amount of motorbikes that must
survive. Lines 3 through 6: the road ahead. Each line represents one lane of the
road. A dot character . represents a safe space, a zero 0 represents a hole in
the road. INPUT FOR ONE GAME TURN: Line 1 : S the motorbikes' speed. Next M
lines: X Y A two integers and a boolean seperated by spaces. X, Y the
coordinates of the motorbike on the road and A to indicate whether the motorbike
is activated "1" or detroyed "0". OUTPUT FOR ONE GAME TURN: A single line
containing one of 6 keywords: SPEED SLOW JUMP WAIT UP DOWN. CONSTRAINTS: The
initial positions of the motorbikes are always X= 0. 0 ≤ S < 50 1 ≤ M ≤ 4 1 ≤ V
≤ M 0 ≤ X < 500 0 ≤ Y < 4 Response time for one game turn ≤ 150ms EXAMPLE: There
are 2 AI motorbikes to begin with, you only need one to cross the bridge.

Initialization input (outside the loop)	No output expected
2	(M)
1	(V)
...0......
...00.....
...0..0...
...0......	Road
Input for turn 1	Output for turn 1
1	(S)
0 1 1	(X Y A) bike 1
0 2 1	(X Y A) bike 2	SPEED
Accelerate to have enough momentum to jump the gap

Input for turn 2	Output for turn 2
2	(S)
2 1 1	(X Y A) bike 1
2 2 1	(X Y A) bike 2	JUMP
The next space for both bikes is a hole, jump now

Input for turn 3	Output for turn 3
2	(S)
4 1 0	(X Y A) bike 1
4 2 1	(X Y A) bike 2	DOWN
One motorbike has been sacrificed. The remaining bike steers down to avoid
oncoming hole

Input for turn 3	Output for turn 4
2	(S)
4 1 0	(X Y A) bike 1
6 3 1	(X Y A) bike 2	WAIT
The bike is out of trouble

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Map {
  vector<string> grid;
  vector<string> backup;
  int bikes;
  vector<int> bikeRows;
  int curx;

  int getNextHole(int row) {
    string r = grid[row];
    for (int cur = curx; cur < grid[row].size(); ++cur) {
      if (r[cur] == '0') {
        return cur;
      }
    }
    return -1;
  }

 public:
  Map(int b) { bikes = b; }
  void AddLine(string line) {
    grid.push_back(line);
    backup = grid;
  }
  void Print() {
    cerr << "printing map... " << endl;
    for (string s : grid) {
      cerr << s << endl;
    }
  }

  void Reset() {
    grid = backup;
    bikeRows.clear();
  }

  void AddBike(int y, int x, int id) {
    grid[y][x] = id + 'a';
    bikeRows.push_back(y);
    curx = x;
  }

  vector<int> DangerRow(int speed) {
    vector<int> ret;
    for (auto a : bikeRows) {
      int nextHole = getNextHole(a);
      if (nextHole <= (speed + curx)) {
        ret.push_back(a);
      }
    }
    return ret;
  }
};

int main() {
  int m;  // the amount of motorbikes to control
  cin >> m;
  cin.ignore();
  Map* map = new Map(m);
  int v;  // the minimum amount of motorbikes that must survive
  cin >> v;
  cin.ignore();
  string l0;  // L0 to L3 are lanes of the road. A dot character . represents a
              // safe space, a zero 0 represents a hole in the road.
  cin >> l0;
  cin.ignore();
  string l1;
  cin >> l1;
  cin.ignore();
  string l2;
  cin >> l2;
  cin.ignore();
  string l3;
  cin >> l3;
  cin.ignore();
  map->AddLine(l0);
  map->AddLine(l1);
  map->AddLine(l2);
  map->AddLine(l3);
  map->Print();

  // game loop
  while (1) {
    vector<int> danger;
    map->Reset();
    int s;  // the motorbikes' speed
    cin >> s;
    cin.ignore();
    for (int i = 0; i < m; i++) {
      int x;  // x coordinate of the motorbike
      int y;  // y coordinate of the motorbike
      int a;  // indicates whether the motorbike is activated "1" or detroyed
              // "0"
      cin >> x >> y >> a;
      cin.ignore();
      if (a) {
        map->AddBike(y, x, i);
        map->Print();
      }
      danger = map->DangerRow(s);
      for (auto a : danger) {
        cerr << "danger " << a << endl;
      }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // A single line containing one of 6 keywords: SPEED, SLOW, JUMP, WAIT, UP,
    // DOWN.
    if (danger.size() > 0) {
      cout << "JUMP" << endl;
    } else {
      cout << "SPEED" << endl;
    }
  }
}

/* step 1:
  representation
  a.  map

*/