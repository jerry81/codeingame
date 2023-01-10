/*


This is a league based challenge.

Wood leagues should be considered as a tutorial which lets players discover the different rules of the game.
In Bronze league, all rules will be unlocked and the real challenge will begin.

Starter AIs are available in the Starter Kit. They can help you get started with coding your own bot. Check out the community events this week and have fun coding!
 	The Goal
Build armies to defeat your opponent by destroying their headquarters.
 	Rules
The map

The map is a grid of size 12x12, where the top-left corner is the cell (0,0). The map is randomly generated at the start of each game.

Both players start with headquarters (HQ) from opposite edges of the map ((0,0) and (11,11)).

A map cell can be either:

void (#): not a playable cell.
neutral (.): doesn't belong to any player.
captured (O or X): belongs to a player.
inactive (o or x): belongs to a player but inactive.
Territory ownership

Throughout the game, each player will capture cells to enlarge their territory. A player territory is composed of all the cells owned by the player that are active.

A cell is said to be active if and only if the cell is connected to the headquarters. That is, there exists a path of owned cells from the headquarters to this cell.

territory-ownership
The red territory is composed of 6 cells. The 3 red-dark cells are now inactive because the blue player interrupted part of this territory. By capturing, for example, the cell marked by an X, the red player can make these cells active again.


Income

At the beginning of each turn, a player gains or loses gold based on their income. A player has +1 income for each active cell owned.

Every turn, army units cost some income (upkeep).

Level 1 units reduce income by 1 per unit.
If a player has negative income and cannot pay their upkeep using their gold, all of the player's units die and the player's gold is reset to 0.


Armies

Army units can move to capture cells and to destroy opponent's buildings and units.

Level 1 units can be trained using the command TRAIN 1 x y. The target cell (x,y) must be in the player's territory or its direct neighbourhood (adjacent cells). Level 1 units cost 10 to train.

Level 1 units can destroy other level 1 units and HQ. Only the attacking unit survives.

Each unit can only move one cell per turn by using the command MOVE id x y.

It's not possible to train or move on a cell with a friendly building or unit on it.

An army unit cannot move on the same turn it's trained.

When using MOVE id x y, if the distance between the unit and the target coordinates (x,y) is greater than 1, the unit moves towards the target.

To train a unit or move it on an enemy unit or building, the attacking unit must be able to destroy the defending unit or building. If so, the attacking unit always survives. Else, the action is invalid; nothing happens.

If a unit is on an inactive cell at the beginning of a turn, the unit is instantly destroyed.

Level	1
Recruitment cost	10
Upkeep	1
Can kill units level	1
Can destroy	HQ
Order of actions

All actions are processed sequentially. Invalid actions are ignored.

action-sequence-diagram
Victory Conditions
Destroy the enemy headquarters.
After 100 turns, you have more military power than your opponent. The military power is computed by the sum of the cost of all of your units + your amount of gold.
Lose Conditions
You fail to provide a valid command in time.
You provide a unrecognized command.
 	Game Input
Initialization input
Line 1: one integer numberMineSpots: the number of mine spots on the map. Mine spots will be used from Wood1 league onwards.

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
x and y: the building's coordinates.
Next line:unitCount: the amount of units on the map.

Next unitCount lines: five integers

owner
0: Owned
1: Enemy
unitId: this unit's unique id
level: always 1 (only in this league).
x and y: the unit's coordinates.
Output
A single line being a combination of these commands separated by ;
MOVE id x y
TRAIN level x y where level can only be 1
WAIT to do nothing.
You can add a message to display in the viewer by appending the command MSG my message.

Example: "MOVE 1 2 3; TRAIN 3 3 3; MOVE 2 3 1; MSG Team Fire"
Constraints
Allotted response time to output is ≤ 50ms.
Allotted response time to output on the first turn is ≤ 1000ms.

What is in store in the higher leagues?

The extra rules available in higher leagues are:
In Wood 2, you can train army units of level 2 and 3.
In Wood 1, you can build mines.
In Bronze, you can build towers.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
  int x;
  int y;
};

class Map {
  vector<string> grid;
  vector<Point> mines;

  public:
    void resetGrid() {
      grid.clear();
    }

    void updateGrid(string line) {
      grid.push_back(line);
    }

    void resetMines() {
      mines.clear();
    }

    void addMine(Point p) {
      mines.push_back(p);
    }
};

int main()
{
    int number_mine_spots;
    cin >> number_mine_spots; cin.ignore();
    for (int i = 0; i < number_mine_spots; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
    }

    // game loop
    while (1) {
        int gold;
        cin >> gold; cin.ignore();
        int income;
        cin >> income; cin.ignore();
        int opponent_gold;
        cin >> opponent_gold; cin.ignore();
        int opponent_income;
        cin >> opponent_income; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string line;
            cin >> line; cin.ignore();
        }
        int building_count;
        cin >> building_count; cin.ignore();
        for (int i = 0; i < building_count; i++) {
            int owner;
            int building_type;
            int x;
            int y;
            cin >> owner >> building_type >> x >> y; cin.ignore();
        }
        int unit_count;
        cin >> unit_count; cin.ignore();
        for (int i = 0; i < unit_count; i++) {
            int owner;
            int unit_id;
            int level;
            int x;
            int y;
            cin >> owner >> unit_id >> level >> x >> y; cin.ignore();
        }

        cout << "WAIT" << endl;
    }
}