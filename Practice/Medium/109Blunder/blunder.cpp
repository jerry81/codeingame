/*

	The Goal
Blunder is a depressed robot who heals his depression by partying and drinking alcohol. To save him from a life of debauchery, his creators have reprogrammed the control system with a more rudimentary intelligence. Unfortunately, he has lost his sense of humor and his former friends have now rejected him.

Blunder is now all alone and is wandering through the streets with the intention of ending it all in a suicide booth.

To intercept him and save him from almost certain death, the authorities have given you a mission: write a program that will make it possible to foresee the path that Blunder follows. To do so, you are given the logic for the new intelligence with which Blunder has been programmed as well as a map of the city.

 	Rules
The 9 rules of the new Blunder system:

Blunder starts from the place indicated by the @ symbol on the map and heads SOUTH.
Blunder finishes his journey and dies when he reaches the suicide booth marked $.
Obstacles that Blunder may encounter are represented by # or X.
When Blunder encounters an obstacle, he changes direction using the following priorities: SOUTH, EAST, NORTH and WEST. So he first tries to go SOUTH, if he cannot, then he will go EAST, if he still cannot, then he will go NORTH, and finally if he still cannot, then he will go WEST.
Along the way, Blunder may come across path modifiers that will instantaneously make him change direction. The S modifier will make him turn SOUTH from then on, E, to the EAST, N to the NORTH and W to the WEST.
The circuit inverters (I on map) produce a magnetic field which will reverse the direction priorities that Blunder should choose when encountering an obstacle. Priorities will become WEST, NORTH, EAST, SOUTH. If Blunder returns to an inverter I, then priorities are reset to their original state (SOUTH, EAST, NORTH, WEST).
Blunder can also find a few beers along his path (B on the map) that will give him strength and put him in “Breaker” mode. Breaker mode allows Blunder to destroy and automatically pass through the obstacles represented by the character X (only the obstacles X). When an obstacle is destroyed, it remains so permanently and Blunder maintains his course of direction. If Blunder is in Breaker mode and passes over a beer again, then he immediately goes out of Breaker mode. The beers remain in place after Blunder has passed.
2 teleporters T may be present in the city. If Blunder passes over a teleporter, then he is automatically teleported to the position of the other teleporter and he retains his direction and Breaker mode properties.
Finally, the space characters are blank areas on the map (no special behavior other than those specified above).
Your program must display the sequence of moves taken by Blunder according to the map provided as input.

The map is divided into lines (L) and columns (C). The contours of the map are always unbreakable # obstacles. The map always has a starting point @ and a suicide booth $.

If Blunder cannot reach the suicide booth because he is indefinitely looping, then your program must only display LOOP.
 	Example
Let the map below:

######
#@E $#
# N  #
#X   #
######
In this example, Blunder will follow this sequence of moves:

SOUTH (initial direction)
EAST (because of the obstacle X)
NORTH (change of direction caused by N)
EAST (change of direction caused by E)
EAST (current direction, until end point $)
 	Game Input
Input
Line 1: the number of lines L and columns C on the map, separated by a space.

The following L lines: a line of the length C representing a line on the map. A line can contain the characters #, X, @, $, S, E, N, W, B, I, T and space character.

Output
If Blunder can reach $, then display the sequence of moves he has taken. One move per line: SOUTH for the South, EAST for the East, NORTH for the North and WEST for the west.
If Blunder cannot reach $, then only display LOOP.
Constraints
4 ≤ C ≤ 100
4 ≤ L ≤ 100
Example
Input
10 10
##########
#        #
#  S   W #
#        #
#  $     #
#        #
#@       #
#        #
#E     N #
##########
Output
SOUTH
SOUTH
EAST
EAST
EAST
EAST
EAST
EAST
NORTH
NORTH
NORTH
NORTH
NORTH
NORTH
WEST
WEST
WEST
WEST
SOUTH
SOUTH

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

struct Point {
  int x;
  int y;
  void print_me() {
    cerr << "Point x is: " << x << ", y is: " << y << endl;
  }
  Point(int x=0, int y=0) : x(x),y(y) {}
};

class Board {
  bool inverted;
  bool berserk;
  int cols;
  int rows;

  Point* current = new Point();
  Point* endpoint = new Point();
  vector<string> grid;
  int counter = 0;

  Point* get_position_of_unique_char(vector<string> g, string searched) {
    Point* ret = new Point();
    for (int i = 0; i < g.size(); ++i) {
      string row = g[i];
      size_t found = row.find(searched);
      // https://stackoverflow.com/questions/131803/unsigned-int-vs-size-t
      // size_t is unsigned integer type result of sizeof operator
      // guaranteed to be big enough for largest obj in system
      // auto conversion seems flexible
      if (found != string::npos) {
        ret->y = i;
        ret->x = found;
        break;
      }
    }
    return ret;
  }

  int next_dir() {
    int mod = counter % 4;
    mod = (mod < 0) ? 4 + mod : mod;
  }

  void next_point() {
    cerr << "current is at " << current->y << ", " << current->x << endl;
    int ny = current->y;
    int nx = current->x;
    char next_sq;

    switch (next_dir()) {
      case 0: // S
        ny = ny+1;
        if (ny >= rows) {
          move_counter();
          return next_point();
        }
        break;
      case 1: // E
        nx = nx+1;
        if (nx >= cols) {
          move_counter();
          return next_point();
        }

        break;
      case 2: // N
        ny = ny-1;
        if (ny < 0) {
          move_counter();
          return next_point();
        }

        break;
      default: // W
        nx = nx-1;
        if (nx < 0) {
          move_counter();
          return next_point();
        }

    }

    next_sq = grid[ny][nx];
    cerr << "next_sq is " << next_sq<< endl;
    if (next_sq == '#') {
      move_counter();
      return next_point();
    }

    if (next_sq == 'X' && !berserk) {
      move_counter();
      return next_point();
    }

    if (next_sq == 'S') counter = 0;
    if (next_sq == 'E') counter = 1;
    if (next_sq == 'N') counter = 2;
    if (next_sq == 'W') counter = 3;

    if (next_sq == 'I') inverted = !inverted;

    current->x = nx;
    current->y = ny;
  }

  void move_counter() {
    counter += inverted ? -1: 1;
  }

  void print_move() {
    cerr << "counter is " << counter << endl;
    switch (next_dir()) {
        case 0:
          cout << "SOUTH" << endl;
          break;
        case 1:
          cout << "EAST" << endl;
          break;
        case 2:
          cout << "NORTH" << endl;
          break;
        default:
          cout << "WEST" << endl;
    }
  }

  public:
    Board(vector<string> g, int r, int c) :
      inverted(false), berserk(false), grid(g), rows(r), cols(c) {
        current = get_position_of_unique_char(g, "@");
        endpoint = get_position_of_unique_char(g, "$");
      }

    bool should_continue() {
      return (current->x != endpoint->x || current->y != endpoint->y);
    }

    void move() {
        counter = 0;
        next_point();
        print_move();
    }
};


int main()
{
    int l;
    int c;
    cin >> l >> c; cin.ignore();
    vector<string> g;
    for (int i = 0; i < l; i++) {
        string row;
        getline(cin, row);
        g.push_back(row);
    }
    Board* b = new Board(g,l,c);

   while (b->should_continue()) {
      b->move();
    }
}