#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Jrke's special
 * -Kill your enemy soldiers or Have more bucks than your enemy at end of game
 **/

enum Direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };

struct Point {
  int x;
  int y;
  Point(int y, int x) : x(x), y(y){};
  void print() { cerr << "point: " << y << ", " << x << endl; }
};

Direction forbiddenMove(Direction cur) {
  switch (cur) {
    case UP:
      return DOWN;
    case LEFT:
      return RIGHT;
    case DOWN:
      return UP;
    default:
      return LEFT;
  }
}

int manhattanDist(Point *a, Point *b) {
  return abs(b->y - a->y) + abs(b->x - a->x);
};

struct Soldier {
  Point *p;
  Direction d;
  int id;
  Soldier(int y, int x, int dir, int id) : id(id) {
    d = static_cast<Direction>(dir);
    p = new Point(y, x);
  }
  bool canShoot(Point *ep) {
    int dist = manhattanDist(p, ep);
    cerr << "dist is " << dist << " dir is " << d << endl;
    p->print();
    cerr << "enemy " << endl;
    ep->print();
    if (dist > 2) return false;

    int dx = abs(ep->x - p->x);
    int dy = abs(ep->y - p->y);
    switch (d) {
      case UP: {
        if (ep->y > p->y) return false;
        break;
      }
      case DOWN: {
        if (ep->y < p->y) return false;
        break;
      }
      case RIGHT: {
        cerr << "yes this cae " << endl;
        cerr << "is " << ep->x << " < " << p->x << endl;
        if (ep->x < p->x) return false;
        cerr << "therefore breaking " << endl;
        break;
      }
      default: {  // LEFT
        if (ep->x > p->x) return false;
        break;
      }
    }
    return true;
  }
};

int main() {
  int my_id;  // Your unique player Id
  cin >> my_id;
  cin.ignore();
  int map_size;  // the size of map MapSize*MapSize
  cin >> map_size;
  cin.ignore();

  // game loop
  while (1) {
    int my_bucks;  // Your Money
    cin >> my_bucks;
    cin.ignore();
    int opp_bucks;  // Opponent Money
    cin >> opp_bucks;
    cin.ignore();
    // three kinds of blocks
    // n, p, e
    for (int i = 0; i < map_size; i++) {
      for (int j = 0; j < map_size; j++) {
        int block_owner;  // The playerId of this box owned player
        int x;            // This block's position x
        int y;            // This block's position y
        cin >> block_owner >> x >> y;
        cin.ignore();
      }
    }
    int active_soldier_count;  // Total no. of active soldier in the game
    cin >> active_soldier_count;
    cin.ignore();
    vector<shared_ptr<Soldier>> mine;
    vector<shared_ptr<Soldier>> his;
    for (int i = 0; i < active_soldier_count; i++) {
      int owner_id;    // owner of the soldier
      int x;           // This soldier's position x
      int y;           // This soldier's position y
      int soldier_id;  // The unique identifier of soldier
      int level;       // Level of the soldier ignore for first league
      int direction;  // The side where the soldier is facing 0 = UP, 1 = LEFT ,
                      // 2 = DOWN, 3 = RIGHT

      cin >> owner_id >> x >> y >> soldier_id >> level >> direction;
      vector<shared_ptr<Soldier>> &targetContainer =
          (owner_id == my_id) ? mine : his;
      targetContainer.push_back(
          std::make_shared<Soldier>(y, x, direction, soldier_id));
      cin.ignore();
    }

    for (auto m: mine) {
      for (auto h: his) {
        if (m->canShoot(h->p)) {
          cerr << "yoooo i can shoot him" << endl;
        }
      }
    }

    // for each soldier
    // enemy in range?

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // print any of actions - WAIT | MOVE <soldierId> <direction> | ATTACK
    // <soldierID> <soldierId to attack on> | LATER > UPGRADE <id> | DEGRADE
    // <opponent id> | SUICIDE <id>
    cout << "WAIT" << endl;
  }
}