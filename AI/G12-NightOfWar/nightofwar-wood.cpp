#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Jrke's special
 * -Kill your enemy soldiers or Have more bucks than your enemy at end of game
 **/

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

struct Point {
  int x = 0;
  int y = 0;
  string hash() { return std::to_string(x) + "," + std::to_string(y); }
  Point(int x = -1, int y = -1)
      : x(x), y(y){};  // init list syntax Constructor followed by :
                       // field(param), field(param)
};

struct Soldier {
  int id = -1;
  int owner = -1;
  int level;
  int direction = UP;
  Point p;
};
struct Block {
  Point p;
  int owner = 0;
};
class Game {
  int myId = 0;
  int mapSize = 0;

  vector<vector<Block>> map;
  vector<Soldier> my_s;
  vector<Soldier> e_s;

 public:
  Game(int myId = 0, int mapSize = 0) : myId(myId), mapSize(mapSize){};

  void reset() {
    map.clear();
    my_s.clear();
    e_s.clear();
  };

  void addMapLine(vector<Block> line) { map.push_back(line); };

  void addMySoldier(Soldier s) { my_s.push_back(s); };

  void addESoldier(Soldier s) { e_s.push_back(s); }
};

int main() {
  int my_id;  // Your unique player Id
  cin >> my_id;
  cin.ignore();
  int map_size;  // the size of map MapSize*MapSize
  cin >> map_size;
  cin.ignore();
  Game g = Game(my_id, map_size);

  // game loop
  while (1) {
    g.reset();
    int my_bucks;  // Your Money
    cin >> my_bucks;
    cin.ignore();
    int opp_bucks;  // Opponent Money
    cin >> opp_bucks;
    cin.ignore();
    for (int i = 0; i < map_size; i++) {
      vector<Block> line;
      for (int j = 0; j < map_size; j++) {
        int block_owner;  // The playerId of this box owned player
        int x;            // This block's position x
        int y;            // This block's position y
        Block b;
        cin >> block_owner >> x >> y;
        b.owner = block_owner;
        Point p = Point(x, y);
        b.p = p;
        line.push_back(b);
        cin.ignore();
      }
    }
    int active_soldier_count;  // Total no. of active soldier in the game
    cin >> active_soldier_count;
    cin.ignore();
    for (int i = 0; i < active_soldier_count; i++) {
      int owner_id;    // owner of the soldier
      int x;           // This soldier's position x
      int y;           // This soldier's position y
      int soldier_id;  // The unique identifier of soldier
      int level;       // Level of the soldier ignore for first league
      int direction;  // The side where the soldier is facing 0 = UP, 1 = LEFT ,
                      // 2 = DOWN, 3 = RIGHT
      cin >> owner_id >> x >> y >> soldier_id >> level >> direction;
      bool me = owner_id == my_id;
      Soldier s;
      s.owner = owner_id;
      s.p = Point(x,y);
      s.level = level;
      s.direction = direction;
      s.id = soldier_id;
      if (me) { g.addMySoldier(s); } else { g.addESoldier(s); }

      cin.ignore();
    }

    // print any of actions - WAIT | MOVE <soldierId> <direction> | ATTACK
    // <soldierID> <soldierId to attack on> | LATER > UPGRADE <id> | DEGRADE
    // <opponent id> | SUICIDE <id>
    cout << "WAIT" << endl;
  }
}