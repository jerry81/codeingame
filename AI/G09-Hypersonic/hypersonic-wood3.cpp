/*


This is a league based puzzle.

For this puzzle, multiple versions of the same game are available. Once you have
proven your skills on this first version, you will access a higher league and
extra rules will be unlocked. The Goal Destroy more boxes than your opponent
with your bombs in this Bomberman-inspired game. Rules The game is played on a
grid 13 units wide and 11 units high. The coordinate X=0, Y=0 is the top left
cell.

For now, the game is played with 2 players only. Each player starts out on a
corner of the map. All actions players take are computed simultaneously.

Boxes are scattered across the grid, and can be destroyed by bombs.

The map works as follows:
Each cell of the grid is either a floor or a box. Floor cells are indicated by a
dot ( .), and boxes by a zero ( 0). Floor cells may be occupied by any number of
players. A random amount of boxes between 30 and 65 inclusive will be placed
symmetrically across the grid. The players work as follows: Every turn, a player
may move horizontally or vertically to an adjacent floor cell. If a bomb is
already occupying that cell, the player won't be able to move there. Players can
occupy the same cell as a bomb only when the bomb appears on the same turn as
when the player enters the cell. Using the MOVE command followed by grid
coordinates will make the player attempt to move one cell closer to those
coordinates. The player will automatically compute the shortest path within the
grid to get to the target point. If the given coordinates are impossible to get
to, the player will instead target the valid cell closest to the given
coordinates. Using the BOMB command followed by map coordinates will make the
player attempt to place a bomb on the currently occupied cell, then move one
cell closer to the given coordinates. Players may stay on the cell on which they
place a bomb. Players can only have 1 bomb in the grid at one time. In this
league, players are not hurt by bombs (they are using practice explosives). The
bombs work as follows: Bombs have an 8 round timer. On each subsequent round,
the timer will decrease by 1. On the round where the timers hits 0, the bomb
explodes. In this league, explosions have a range of 3, meaning they span
horizontally and vertically up to 3 squares in each direction unless they
encounter a box or other bomb. Explosions will cause the boxes they hit to be
destroyed. Explosions will cause the bombs they hit to also explode. After 200
rounds, the player who hit the most boxes with their bombs wins.

The game state of every round is given to you as a list of entities, each with a
entityType, owner, position, param1 and param2.

The entityType will be:
For players: 0.
For bombs: 1.
The owner will be:
For players: id of the player ( 0 or 1).
For bombs: id of the bomb's owner.
The param1 will be:
For players: number of bombs the player can still place.
For bombs: number of rounds left until the bomb explodes.
The param2 is not useful for the current league, and will always be:
For players: explosion range of the player's bombs (= 3).
For bombs: explosion range of the bomb (= 3).

Victory Conditions
You are the one who blew up the most boxes.

Lose Conditions
Your program does not respond in time.
You provide invalid input.
        Expert Rules
Details on how a round is computed:
At the start of the round, all bombs have their countdown decreased by 1.
Any bomb countdown that reaches 0 will cause the bomb to explode immediately,
before players move. Any bomb caught in an explosion is treated as if it had
exploded at the very same moment. Explosions do not go through obstructions such
as boxes or other bombs, but are included on the cells the obstruction occupies.
A single obstruction may block the explosions of several bombs that explode on
the same turn. Once the explosions have been computed, any box hit scores a
point to the owner of each explosion. This means that the destruction of 1 box
can count for 2 different players. Players then perform their actions
simultaneously. Destroyed boxes are removed. Any bombs placed by a player appear
at the end of the round. Note The program must first read initialization input
and then, within an infinite loop, read the contextual data from the standard
input and provide to the standard output the desired instructions. Game Input
Initialization input
Line 1: 3 integers, width, height and myId. width and height represent the size
of the grid and will always be 13 and 11 respectively, and are given for purely
for convenience. myId is your player's id. Input for one game turn First height
lines: a string row representing each row of the grid. Each character can be: .
an empty cell. 0 a box. Next line: an integer entities for the amount of
entities on the grid. Next entities lines : 6 space separated integers
entityType , owner , x , y , param1 & param2 . Represents a player or a bomb.
Output for one game turn
One of the following:
MOVE followed by two integers x and y.
BOMB followed by two integers x and y.

You may append text to your instructions, it will be displayed in the viewer.
e.g. MOVE 1 1 hypersonic. Constraints

Response time per turn ≤ 100 ms
Response time for the first turn ≤ 1000 ms

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  Point(int x = -1, int y = -1) : x(x), y(y){};
};

class Grid {
  vector<string> grid;
  vector<string> processedGrid;
  int size;

 public:
  void addRow(string row) { grid.push_back(row); }

  void reset() { grid.clear(); }

  void setSize(int size) { size = size; }

  int getSize() { return size; }

  char at(Point p) { return grid[p.y][p.x]; }

  vector<int> findBoxesInRow(int row) {
    string r = grid[row];
    vector<int> ret;
    for (int i = 0; i < r.length(); ++i) {
      if (r[i] == '0') ret.push_back(i);
    }
    return ret;
  }

  void print() {
    cerr << "Grid: " << endl;
    for (string s : grid) {
      cerr << s << endl;
    }
  }

  bool isSquareAPath(int x, int y, vector<string> g) {
    char c = g[y][x];

    if (c == '0') return false;

    if (c == '.') return true;

    return isdigit(c);
  }

  void incrementSquare(int x, int y) {
    char c = processedGrid[y][x];
    if (c == '.') c = '0';

    int i = c + '0';
    i++;

    processedGrid[y][x] = i - '0';
  }

  void processSquare(int x, int y) {
    bool uObstacle = false;
    bool dObstacle = false;
    bool lObstacle = false;
    bool rObstacle = false;
    for (int i = 1; i < 4; ++i) {
      int uy = y - i;
      int dy = y + i;
      int lx = x - i;
      int rx = x + i;

    }
  }

  void processGrid() {
    processedGrid = grid;  // copy
    for (int y = 0; y < grid.size(); ++y) {
      vector<int> boxes = findBoxesInRow(y);
    }
  }

  Grid(){};
};

int main() {
  int width;
  int height;
  int my_id;
  cin >> width >> height >> my_id;
  cin.ignore();

  // game loop
  while (1) {
    Grid g;
    for (int i = 0; i < height; i++) {
      string row;
      cin >> row;
      cin.ignore();
      g.addRow(row);
    }
    g.print();
    int entities;
    cin >> entities;
    cin.ignore();
    for (int i = 0; i < entities; i++) {
      int entity_type;
      int owner;
      int x;
      int y;
      int param_1;
      int param_2;
      cin >> entity_type >> owner >> x >> y >> param_1 >> param_2;
      cin.ignore();
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "BOMB 6 5" << endl;
  }
}