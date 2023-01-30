/*

This is a league based puzzle.

For this puzzle, multiple versions of the same game are available. Once you have
proven your skills on this first version, you will access a higher league and
extra rules will be unlocked. The Goal Reach a height of 3 levels before your
opponent. Rules The game is played on a square grid of a given size. Both
players start with one unit placed randomly on the grid.

Both players take it in turns to perform an action with their unit. To win the
game, players must get their unit to climb up cells and reach a height of 3
levels.

The grid
Cells can be floors or holes. A floor is represented by an integer, a hole is
represented by a dot (.). Holes are considered as outside the playable area.
Each cell in the playable area has a height going from 0 to 3. A height of 4 is
outside the playable area.

The units
Each unit occupies a cell in the playable area of the grid and has the power to
MOVE and then BUILD. A unit may move to any neighboring cell, including
diagonals. The unit may only move on the same level, step up one level or step
down any number of levels. After every movement, the unit must be able to build
onto an adjacent cell of its new position. This causes the cell in question to
gain 1 unit of height. If the height reaches level 4, the cell is considered
removed from play. If your unit moves onto a level 3 cell, you win the game.
Actions

Every turn, your unit must perform a valid pair of actions:
MOVE&BUILD: The unit moves in a given direction on the grid, then places an
extra level on a neighboring cell.

Source code:

The source code of the game is available on our Github at this address:
https://github.com/CodinGame/WondevWoman/

Victory Conditions
Your unit reaches the third level.

Lose Conditions
You perform an invalid action or do not respond in time.
        Game Input
Initialization input
Line 1: an integer size for the size of the square grid.
Line 2: an integer unitsPerPlayer for the number of units each player controls.
Always 1 for this league. Input for one game turn First size lines: size
characters representing one row of the grid. A dot (.) for an unplayable cell or
an integer height for the cell's current level. Next unitsPerPlayer lines:
unitX, unitY the coordinates of one of your units. Next unitsPerPlayer lines:
otherX, otherY the coordinates of one of your opponent's units. If the unit is
not visible to you, the values will be -1 -1. Next line: legalActions, an
integer for the number of valid actions you may play this turn. Next
legalActionslines: atype, index, dir1, dir2: the parameters of a valid command
you may output this turn. For instance, in the action MOVE&BUILD 0 N SW, atype
is MOVE&BUILD, index designates the unit at index 0, which may move north and
build to the south-west. Output for one game turn One line: MOVE&BUILD followed
by index for the unit you wish to perform the action (Always 0 for this league),
dir1 for the direction in which the unit will move, dir2 for the direction of
the cell the unit will raise the level of.

You may append text to your action, it will be displayed in the viewer.
The possible directions are: N, NE, E, SE, S, SW, W, NW.

Constraints
5 ≤ size ≤ 7
unitsPerPlayer = 1
0 ≤ legalActions ≤ 64
Response time per turn ≤ 50ms
Response time for the first turn ≤ 1000ms

What is in store for me in the higher leagues?

The extra rules available in higher leagues are:
The game continues after 1 point is scored.
You will control two units AND have the ability to PUSH the opponent's units.
You'll only be able to see enemy units adjacent to one of yours.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Grid {
  vector<string> grid;
  int size;

 public:
  void addRow(string row) { grid.push_back(row); }

  void reset() { grid.clear(); }

  void setSize(int size) { size = size; }

  int getSize() { return size; }

  char at(Point p) { return grid[p.y][p.x]; }

  Grid(){};
};

struct Point {
  int x;
  int y;
  Point(int x = -1, int y = -1) : x(x), y(y){};
};

struct Unit {
  Point p;
  Unit(Point p) : p(p){};
  Unit(){};
};

struct Action {
  string type;
  int unit_id;
  string dir1;
  string dir2;
  string stringify() {
    return type + " " + std::to_string(unit_id) + " " + dir1 + " " + dir2;
  }
  Action(string type = "MOVE&BUILD", int unit_id = 0, string d = "N",
         string d2 = "N")
      : type(type), unit_id(unit_id), dir1(d), dir2(d2){};
};

class Game {
  vector<Action> legal_actions;
  Grid g;
  Unit me;
  Unit him;

 public:
  void reset() { legal_actions.clear(); }

  void addLegalAction(Action a) { legal_actions.push_back(a); }

  void setGrid(Grid gr) { g = gr; }

  void setMe(Unit m) { me = m; }

  void setHim(Unit h) { him = h; }

  Game(Grid g, Unit me, Unit him) {
    g = g;
    me = me;
    him = him;
  }

  Game() {}

  char neighborFromMe(string dir) {
    int mex = me.p.x;
    int mey = me.p.y;
    int u = mey - 1;
    int d = mey + 1;
    int l = mex - 1;
    int r = mex + 1;
    if (dir == "N") {
      return g.at(Point(mex, u));
    } else if (dir == "NE") {
      return g.at(Point(r, u));
    } else if (dir == "E") {
      return g.at(Point(r, mey));
    } else if (dir == "SE") {
      return g.at(Point(r, d));
    } else if (dir == "S") {
      return g.at(Point(mex, d));
    } else if (dir == "SW") {
      return g.at(Point(l, d));
    } else if (dir == "W") {
      return g.at(Point(l, mey));
    } else {  // NW
      return g.at(Point(l, u));
    }
  }



  Action getBestLegalMove() {
    Action bestAction;

    for (Action a : legal_actions) {
      if (a.type == "MOVE&BUILD") {
        char c = neighborFromMe(a.dir1);
        if (c == '3') return a; // win.
      } else {
        cerr<<"unhandled case in bestLegalMove"<<endl;
      }

    }
    return bestAction;
  }
};

int main() {
  int size;
  cin >> size;
  cin.ignore();
  int units_per_player;
  cin >> units_per_player;
  cin.ignore();
  Grid g;
  Game gm;
  g.setSize(size);
  // game loop
  while (1) {
    g.reset();

    for (int i = 0; i < size; i++) {
      string row;
      cin >> row;
      cin.ignore();
      g.addRow(row);
    }
    gm.setGrid(g);

    for (int i = 0; i < units_per_player; i++) {
      int unit_x;
      int unit_y;
      cin >> unit_x >> unit_y;
      cin.ignore();
      Unit me = Unit(Point(unit_x, unit_y));
      gm.setMe(me);
    }
    for (int i = 0; i < units_per_player; i++) {
      int other_x;
      int other_y;
      cin >> other_x >> other_y;
      cin.ignore();
      Unit him = Unit(Point(other_x, other_y));
      gm.setHim(him);
    }
    int legal_actions;

    gm.reset();
    cin >> legal_actions;
    cin.ignore();
    for (int i = 0; i < legal_actions; i++) {
      string atype;
      int index;
      string dir_1;
      string dir_2;
      cin >> atype >> index >> dir_1 >> dir_2;
      cin.ignore();
      gm.addLegalAction(Action(atype, index, dir_1, dir_2));
    }
    cout << gm.getBestLegalMove().stringify() << endl;
  }
}
