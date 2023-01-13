/*


Welcome to the Wood1 league!

You are now able to build mines (BUILD MINE) to generate more income. They can
be built only on mine spots.

Starter AIs are available in the Starter Kit. They can help you get started with
coding your own bot. Check out the community events this week and have fun
coding! The Goal Build armies to defeat your opponent by destroying their
headquarters. Rules The map

The map is a grid of size 12x12, where the top-left corner is the cell (0,0).
The map is randomly generated at the start of each game.

Both players start with headquarters (HQ) from opposite edges of the map ((0,0)
and (11,11)).

A map cell can be either:

void (#): not a playable cell.
neutral (.): doesn't belong to any player.
captured (O or X): belongs to a player.
inactive (o or x): belongs to a player but inactive.
Territory ownership

Throughout the game, each player will capture cells to enlarge their territory.
A player territory is composed of all the cells owned by the player that are
active.

A cell is said to be active if and only if the cell is connected to the
headquarters. That is, there exists a path of owned cells from the headquarters
to this cell.

territory-ownership
The red territory is composed of 6 cells. The 3 red-dark cells are now inactive
because the blue player interrupted part of this territory. By capturing, for
example, the cell marked by an X, the red player can make these cells active
again.


Income

At the beginning of each turn, a player gains or loses gold based on their
income. A player has +1 income for each active cell owned.

Every turn, army units cost some income (upkeep).

Level 1 units reduce income by 1 per unit.
Level 2 units reduce income by 4 per unit.
Level 3 units reduce income by 20 per unit.
Players has +4 income for each mine they control.

If a player has negative income and cannot pay their upkeep using their gold,
all of the player's units die and the player's gold is reset to 0.


Buildings

Players can BUILD buildings to improve their economy or military power. A player
can only build on owned active cells that are unoccupied.

In this league, players can only build one building: the MINE.

MINE: mines produce gold each turn and can only be built on mine spots. Mines
cost 15 to build. A mine's income is always +4. If a building is on an inactive
cell, it is not destroyed; it is just inactive.


Armies

Army units can move to capture cells and to destroy opponent's buildings and
units.

Army units of different levels (1, 2 or 3) can be trained using the command
TRAIN level x y. The target cell (x,y) must be in the player's territory or its
direct neighbourhood (adjacent cells).

Army units can only destroy units of inferior level, except level 3 units which
can destroy any unit.

Every unit can destroy every building.

Each unit can only move one cell per turn by using the command MOVE id x y.

It's not possible to train or move on a cell with a friendly building or unit on
it.

An army unit cannot move on the same turn it's trained.

When using MOVE id x y, if the distance between the unit and the target
coordinates (x,y) is greater than 1, the unit moves towards the target.

To train a unit or move it on an enemy unit or building, the attacking unit must
be able to destroy the defending unit or building. If so, the attacking unit
always survives. Else, the action is invalid; nothing happens.

If a unit is on an inactive cell at the beginning of a turn, the unit is
instantly destroyed.

Level	1	2	3
Recruitment cost	10	20	30
Upkeep	1	4	20
Can kill units level	-	1	1, 2, 3
Can destroy	Mines
HQ	Mines
HQ	Mines
HQ
Order of actions

All actions are processed sequentially. Invalid actions are ignored.

action-sequence-diagram
Victory Conditions
Destroy the enemy headquarters.
After 100 turns, you have more military power than your opponent. The military
power is computed by the sum of the cost of all of your units + your amount of
gold. Lose Conditions You fail to provide a valid command in time. You provide a
unrecognized command. Game Input Initialization input Line 1: one integer
numberMineSpots: the number of mine spots on the map.

Next numberMineSpots lines: two integers
x and y: coordinates of the mine spot.
Game turn input
Line 1: an integer gold, the player's amount of gold.

Line 2: an integer income, the player's income.

Line 3: an integer opponentGold, the opponent's amount of gold.

Line 4: an integer opponentIncome: the opponent's income.

Next 12 lines: 12 characters, on for each cell:

#: void
.: neutral
O: owned and active cell
o: owned and inactive
X: active opponent cell
x: inactive opponent cell
Next line: buildingCount: the amount of buildings on the map.

Next buildingCount lines: four integers

owner
0: Owned
1: Enemy
buildingType: the type of building
0: HQ
1: Mine
x and y: the building's coordinates.
Next line:unitCount: the amount of units on the map.

Next unitCount lines: five integers

owner
0: Owned
1: Enemy
unitId: this unit's unique id
level: 1, 2 or 3.
x and y: the unit's coordinates.
Output
A single line being a combination of these commands separated by ;
MOVE id x y
TRAIN level x y where level is either 1, 2 or 3
BUILD building-type x y where the building-type can only be MINE.
WAIT to do nothing.
You can add a message to display in the viewer by appending the command MSG my
message.

Example: "MOVE 1 2 3; TRAIN 3 3 3; BUILD MINE 0 1; MSG Team Fire"
Constraints
Allotted response time to output is ≤ 50ms.
Allotted response time to output on the first turn is ≤ 1000ms.

What is in store in the higher leagues?

The extra rules available in higher leagues are:
In Bronze, you can build towers.

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  Point(int x = -1, int y = -1) : x(x), y(y){};
  void print() {
    cerr << "printing point" << endl;
    cerr << "y: " << y << " x: " << x << endl;
  }
};

class GameMap {
  vector<string> grid;
  vector<Point> mines;
  vector<Point> friendlySquares;

 public:
  void resetGrid() { grid.clear(); }

  void updateGrid(string line) { grid.push_back(line); }

  void resetMines() { mines.clear(); }

  void addMine(Point p) { mines.push_back(p); }

  vector<Point> getMines() { return mines; }

  void print() {
    cerr << "Printing map: " << endl;
    for (string s : grid) {
      cerr << s << endl;
    }

    cerr << "Printing mines" << endl;
    for (Point p : mines) {
      cerr << "mine" << endl;
      p.print();
    }
  }

  void populateFriendlySquares() {
    friendlySquares.clear();
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        char c = grid[i][j];
        if (c == 'O' || c == 'o') {
          Point p = Point(j, i);
          friendlySquares.push_back(p);
        }
      }
    }
  }

  char at(Point p) { return grid[p.y][p.x]; }

  vector<Point> getFriendlySquares() { return friendlySquares; }
};

struct Unit {
  int id;
  int x;
  int y;
  int owner;
  int level;
  Unit(int i = -1, int x = -1, int y = -1, int owner = -1, int level = -1)
      : id(i), x(x), y(y), owner(owner), level(level){};
  void print() {
    cerr << "unit" << endl;
    cerr << "id " << id << " x: " << x << " y: " << y << " owner: " << owner
         << " level: " << level << endl;
  };
};

struct Move {
  int id;
  int x;
  int y;
  Move(int id = -1, int x = -1, int y = -1) : id(id), x(x), y(y){};
  void print() {
    cerr << "printing Move" << endl;
    cerr << "move id: " << id << " x: " << x << " y: " << y << endl;
  }
};

struct Building {
  int type;
  int owner;
  int x;
  int y;
  void print() {
    cerr << "building" << endl;
    cerr << "type: " << type << " owner: " << owner << " x: " << x
         << " y: " << y << endl;
  };
  Building(int t = -1, int owner = -1, int x = -1, int y = -1)
      : type(t), owner(owner), x(x), y(y){};
};

class Game {
  unordered_map<int, Unit> f1units;
  unordered_map<int, Unit> f2units;
  unordered_map<int, Unit> f3units;
  unordered_map<int, Unit> e1units;
  unordered_map<int, Unit> e2units;
  unordered_map<int, Unit> e3units;
  vector<Building> friendlyMines;
  vector<Building> enemyMines;
  Building friendlyHQ;
  Building enemyHQ;
  GameMap map;
  int myMoney;
  int myIncome;

 public:
  void setMap(GameMap gm) { map = gm; }

  void setMyMoney(int money) { myMoney = money; }

  void setMyIncome(int money) { myIncome = money; }

  int friendlyL1Count() { return f1units.size(); }

  int friendlyL2Count() { return f2units.size(); }

  int friendlyL3Count() { return f3units.size(); }

  int enemyL1Count() { return e1units.size(); }

  int enemyL2Count() { return e2units.size(); }

  int enemyL3Count() { return e3units.size(); }

  void addUnit(int id, int y, int x, int owner, int level) {
    Unit u = Unit(id, x, y, owner, level);
    if (owner == 0) {
      if (level == 1) {
        f1units[id] = u;
      } else if (level == 2) {
        f2units[id] = u;
      } else {
        f3units[id] = u;
      }
    } else {
      if (level == 1) {
        e1units[id] = u;
      } else if (level == 2) {
        e2units[id] = u;
      } else {
        e3units[id] = u;
      }
    }
  }

  void addBuilding(int type, int owner, int x, int y) {
    Building b = Building(type, owner, x, y);
    if (type == 0) {
      if (owner == 0) {
        friendlyHQ = b;
      } else {
        enemyHQ = b;
      }
    } else {
      if (owner == 0) {
        friendlyMines.push_back(b);
      } else {
        enemyMines.push_back(b);
      }
    }
  }

  void print() {
    cerr << "Printing game status" << endl;
    cerr << "Friendly Units L1" << endl;
    for (auto pair : f1units) {
      pair.second.print();
    }
    cerr << "Friendly Units L2" << endl;
    for (auto pair : f2units) {
      pair.second.print();
    }
    cerr << "Friendly Units L3" << endl;
    for (auto pair : f3units) {
      pair.second.print();
    }
    cerr << "Enemy Units L1" << endl;
    for (auto pair : e1units) {
      pair.second.print();
    }
    cerr << "Enemy Units L2" << endl;
    for (auto pair : e2units) {
      pair.second.print();
    }
    cerr << "Enemy Units L3" << endl;
    for (auto pair : e3units) {
      pair.second.print();
    }
    cerr << "F HQ" << endl;
    friendlyHQ.print();
    cerr << "F mines" << endl;
    for (auto b : friendlyMines) {
      b.print();
    }
    cerr << "E Mines" << endl;
    for (auto b : enemyMines) {
      b.print();
    }
    cerr << "Map " << endl;
    map.print();
    cerr << "My gold " << myMoney << endl;
    cerr << "My income " << myIncome << endl;
  }

  int getTrainableCount() { return (int)(myMoney / 10); }

  bool occupied(Point p) {
    for (auto u : f1units) {
      if (u.second.x == p.x && u.second.y == p.y) return true;
    }

    for (auto u : f2units) {
      if (u.second.x == p.x && u.second.y == p.y) return true;
    }

    for (auto u : f3units) {
      if (u.second.x == p.x && u.second.y == p.y) return true;
    }

    if (friendlyHQ.x == p.x && friendlyHQ.y == p.y) return true;

    return false;
  }

  unordered_map<int, unordered_map<int, bool>> getNeighbors(Point p) {
    unordered_map<int, unordered_map<int, bool>> res;
    int py = p.y;
    int px = p.x;
    int uy = py - 1;
    int dy = py + 1;
    int lx = px - 1;
    int rx = px + 1;
    if (uy >= 0) {
      if (res.find(uy) == res.end()) {
        unordered_map<int, bool> um;
        res[uy] = um;
      }
      res[uy][px] = true;
    }

    if (dy <= 11) {
      if (res.find(uy) == res.end()) {
        unordered_map<int, bool> um;
        res[dy] = um;
      }
      res[dy][px] = true;
    }

    if (lx >= 0) {
      if (res.find(py) == res.end()) {
        unordered_map<int, bool> um;
        res[py] = um;
      }
      res[py][lx] = true;
    }

    if (rx >= 0) {
      if (res.find(py) == res.end()) {
        unordered_map<int, bool> um;
        res[py] = um;
      }
      res[py][rx] = true;
    }

    return res;
  }

  bool isValidTrainingGround(Point p) {
    char c = map.at(p);
    return c == 'O' || c == 'o' || c == '.';
  }

  bool isValidMove(Point p) {
    char c = map.at(p);
    return c == '.' || c == 'X' || c == 'x';
  }

  vector<Point> getTrainableSquares() {
    vector<Point> ret;
    vector<Point> friendlySqs = map.getFriendlySquares();
    unordered_map<int, unordered_map<int, bool>> ptsMap;
    for (Point p : friendlySqs) {
      ptsMap.merge(getNeighbors(p));
    }

    for (auto y : ptsMap) {
      for (auto x : y.second) {
        Point p = Point(x.first, y.first);
        if (isValidTrainingGround(p) && !occupied(p)) {
          ret.push_back(p);
        }
      }
    }
    return ret;
  }

  void analyzeMap() { map.populateFriendlySquares(); }

  vector<Point> getOccupiedMines() {
    vector<Point> ret;
    vector<Point> mines = map.getMines();
    for (auto u : f1units) {
      Unit un = u.second;
      for (Point mine : mines) {
        if (mine.x == un.x && mine.y == un.y) {
          ret.push_back(mine);
        }
      }
    }
    for (auto u : f2units) {
      Unit un = u.second;
      for (Point mine : mines) {
        if (mine.x == un.x && mine.y == un.y) {
          ret.push_back(mine);
        }
      }
    }
    for (auto u : f3units) {
      Unit un = u.second;
      for (Point mine : mines) {
        if (mine.x == un.x && mine.y == un.y) {
          ret.push_back(mine);
        }
      }
    }
    return ret;
  }

  vector<Move> getMoves() {
    vector<Move> ret;
    for (auto u : f1units) {
      Move m = Move(u.second.id);

      // get neighbors
      Point p = Point(u.second.x, u.second.y);
      p.print();
      auto neighbors = getNeighbors(p);
      for (auto y : neighbors) {
        bool should_break = false;
        for (auto x : y.second) {
          Point p = Point(x.first, y.first);
          if (isValidMove(p)) {
            p.print();
            m.x = x.first;
            m.y = y.first;
            ret.push_back(m);
            should_break = true;
            break;
          }
        }
        if (should_break) break;
      }
    }
    return ret;
  }
};

string makeCommand(vector<Point> trainable, vector<Move> moves,
                   vector<Point> mines) {
  string ret = "";
  for (Point p : trainable) {
    string segment =
        "TRAIN 1 " + std::to_string(p.x) + " " + std::to_string(p.y) + ";";
    ret += segment;
  }

  for (Move m : moves) {
    string segment = "MOVE " + std::to_string(m.id) + " " +
                     std::to_string(m.x) + " " + std::to_string(m.y) + ";";
    ret += segment;
  }

  for (Point m : mines) {
    string segment =
        "BUILD MINE " + std::to_string(m.x) + " " + std::to_string(m.y) + ";";
    ret += segment;
  }

  if (ret.empty()) {
    ret = "WAIT";
  }

  return ret;
}

int main() {
  GameMap gm;
  Game g;
  int number_mine_spots;
  cin >> number_mine_spots;
  cin.ignore();
  for (int i = 0; i < number_mine_spots; i++) {
    int x;
    int y;
    cin >> x >> y;
    Point p = Point(x, y);
    gm.addMine(p);
    cin.ignore();
  }

  // game loop

  while (1) {
    int gold;
    cin >> gold;
    cin.ignore();
    g.setMyMoney(gold);
    int income;
    cin >> income;
    cin.ignore();
    g.setMyIncome(income);
    int opponent_gold;
    cin >> opponent_gold;
    cin.ignore();
    int opponent_income;
    cin >> opponent_income;
    cin.ignore();
    gm.resetGrid();
    for (int i = 0; i < 12; i++) {
      string line;
      cin >> line;
      cin.ignore();
      gm.updateGrid(line);
      g.setMap(gm);
    }
    g.analyzeMap();
    int building_count;
    cin >> building_count;
    cin.ignore();
    for (int i = 0; i < building_count; i++) {
      int owner;
      int building_type;
      int x;
      int y;
      cin >> owner >> building_type >> x >> y;
      cin.ignore();
      g.addBuilding(building_type, owner, x, y);
    }
    int unit_count;
    cin >> unit_count;
    cin.ignore();
    for (int i = 0; i < unit_count; i++) {
      int owner;
      int unit_id;
      int level;
      int x;
      int y;
      cin >> owner >> unit_id >> level >> x >> y;
      cin.ignore();
      g.addUnit(unit_id, y, x, owner, level);
    }
    g.print();
    int trainable = g.getTrainableCount();
    vector<Point> trainableSqs = g.getTrainableSquares();
    vector<Move> moves = g.getMoves();
    vector<Point> mines = g.getOccupiedMines();
    string command = makeCommand(trainableSqs, moves, mines);
    cout << command << endl;  // MOVE TRAIN WAIT
  }
}

/*
  step 1:  train!
    - get trainables

  step 2: move!
    - for each unit
    - get the unit's neighbors
      - favor unvisited nodes
      - favor enemy nodes

  step 3:  build mines


*/