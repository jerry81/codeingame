#include <limits.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/* CONSTANTS */
enum Direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };
const string directionNames[] = {"UP", "LEFT", "DOWN", "RIGHT"};
const vector<vector<int>> movements = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int DANGER = 2;

/* STRUCTS */
struct Point {
  int x;
  int y;
  Point(int y, int x) : x(x), y(y){};
  void print() { cerr << "point: " << y << ", " << x << endl; }
  string to_h() { return to_string(y) + "," + to_string(x); }
};

struct BFSNode {
  Point *p;
  Direction d;
  BFSNode *startDir;
  string to_h() { return p->to_h() + "," + to_string(d); }
  BFSNode(Point *p, Direction d) : p(p), d(d){};
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
  int lvl;
  Soldier(int y, int x, int dir, int id, int level) : id(id), lvl(level) {
    d = static_cast<Direction>(dir);
    p = new Point(y, x);
  }

  void setDanger(vector<vector<int>> &grid, int &sz) {
    int cx = p->x;
    int cy = p->y;

    switch (d) {
      case LEFT: {
        for (int dx : {-1, -2}) {
          int nx = cx + dx;
          if (nx >= 0) grid[cy][nx] = 2;
          int ny = cy + dx;
          if (ny >= 0) grid[ny][cx] = 2;
          ny = cy - dx;
          if (ny < sz) grid[ny][cx] = 2;
        }

        int nx = cx - 1;
        if (nx < 0) break;

        for (int delta : {-1, 1}) {
          int ny = cy + delta;

          if (ny < sz && ny >= 0) grid[ny][nx] = 2;
        }

        break;
      }
      case UP: {
        for (int dy : {-1, -2}) {
          int ny = cy + dy;
          if (ny >= 0) grid[ny][cx] = 2;
          int nx = cx + dy;
          if (nx >= 0) grid[cy][nx] = 2;
          nx = cx - dy;
          if (nx < sz) grid[cy][nx] = 2;
        }

        int ny = cy - 1;
        if (ny < 0) break;

        for (int delta : {-1, 1}) {
          int nx = cx + delta;

          if (nx < sz && nx >= 0) grid[ny][nx] = 2;
        }
        break;
      }
      case DOWN: {
        for (int dy : {1, 2}) {
          int ny = cy + dy;
          if (ny < sz) grid[ny][cx] = 2;
          int nx = cx + dy;
          if (nx < sz) grid[cy][nx] = 2;
          nx = cx - dy;
          if (nx >= 0) grid[cy][nx] = 2;
        }

        int ny = cy + 1;
        if (ny >= sz) break;

        for (int delta : {-1, 1}) {
          int nx = cx + delta;

          if (nx < sz && nx >= 0) grid[ny][nx] = 2;
        }
        break;
      }
      default: {  // RIGHT
        for (int dx : {1, 2}) {
          int nx = cx + dx;
          if (nx < sz) grid[cy][nx] = 2;
          int ny = cy + dx;
          if (ny < sz) grid[ny][cx] = 2;
          ny = cy - dx;
          if (ny >= 0) grid[ny][cx] = 2;
        }

        int nx = cx + 1;
        if (nx >= sz) break;

        for (int delta : {-1, 1}) {
          int ny = cy + delta;

          if (ny < sz && ny >= 0) grid[ny][nx] = 2;
        }
        break;
      }
    }
  }

  /* TODO: finish this */
  string bfs(vector<vector<int>> &grid, int &my_id, int &sz) {
    // path to closest
    unordered_set<string> visited;
    BFSNode *start = new BFSNode(p, d);
    queue<BFSNode *> neigh;
    visited.insert(start->to_h());
    neigh.push(start);
    while (!neigh.empty()) {
      BFSNode *cur = neigh.front();
      neigh.pop();

      for (int i = UP; i <= RIGHT; i++) {
        Direction dr = static_cast<Direction>(i);
        Direction except = forbiddenMove(dr);
        if (except == dr) continue;

        vector<int> change = movements[i];
        int ny = change[0] + cur->p->y;
        int nx = change[1] + cur->p->x;
        if (ny < 0 || ny >= sz) continue;

        if (nx < 0 || nx >= sz) continue;

        Point *nxtP = new Point(ny, nx);
        BFSNode *cneigh = new BFSNode(nxtP, dr);
        cneigh->startDir = (cur->startDir == nullptr) ? cur : cur->startDir;
        if (visited.find(cneigh->to_h()) != visited.end()) continue;

        neigh.push(cneigh);
      }
    }
  }

  bool canShoot(shared_ptr<Soldier> es) {
    if (lvl < es->lvl) return false;

    Point *ep = es->p;
    int dist = manhattanDist(p, ep);
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
        if (ep->x < p->x) return false;
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

/* METHODS */

string getBestMove(vector<vector<int>> &grid, vector<shared_ptr<Soldier>> &mine,
                   vector<shared_ptr<Soldier>> &his, int &sz, int &my_id) {
  // phase one - get single move
  for (auto a : mine) {
    // get the 3 possible moves
    Direction except = forbiddenMove(a->d);
    Point *pt = a->p;
    int cx = pt->x;
    int cy = pt->y;
    int dy = 0;
    int dx = 0;
    for (int i = UP; i <= RIGHT; ++i) {
      if (i == except) continue;

      switch (i) {
        case UP: {
          dy = -1;
          dx = 0;
          break;
        }
        case LEFT: {
          dx = -1;
          dy = 0;
          break;
        }
        case DOWN: {
          dy = 1;
          dx = 0;
          break;
        }
        case RIGHT: {
          dx = 1;
          dy = 0;
          break;
        }
        default:
          continue;
      }

      int nx = dx + cx;
      int ny = dy + cy;

      // rule out out of bounds

      if (nx < 0 || ny < 0) continue;
      if (nx >= sz || ny >= sz) continue;
      if (grid[ny][nx] == 2) continue;

      if (grid[ny][nx] == my_id) continue;

      return "MOVE " + to_string(a->id) + " " + directionNames[i];
    }
    // rule out danger squares
  }
  return "WAIT";
}

int closestDist(vector<shared_ptr<Soldier>> &mine,
                vector<shared_ptr<Soldier>> &his) {
  int mn = INT_MAX;
  for (auto a : mine) {
    for (auto b : his) {
      int dist = manhattanDist(a->p, b->p);
      mn = min(dist, mn);
    }
  }
  return mn;
}

void prepareForBattle(vector<shared_ptr<Soldier>> &mine) {
  if (mine.size() > 1) {
    cout << "SUICIDE " << mine.back()->id << endl;
  } else {
    cout << "UPGRADE " << mine.back()->id << endl;
  }
}

int main() {
  int my_id;  // Your unique player Id
  cin >> my_id;
  cin.ignore();
  int map_size;  // the size of map MapSize*MapSize
  cin >> map_size;
  cin.ignore();

  // game loop
  while (1) {
  endLoop:
    int my_bucks;  // Your Money
    cin >> my_bucks;
    cin.ignore();
    int opp_bucks;  // Opponent Money
    cin >> opp_bucks;
    cin.ignore();

    int mySq = 0;
    int hSq = 0;
    // three kinds of blocks
    // n, p, e
    vector<vector<int>> grid(map_size, vector<int>(map_size, -1));
    for (int i = 0; i < map_size; i++) {
      for (int j = 0; j < map_size; j++) {
        int block_owner;  // The playerId of this box owned player
        int x;            // This block's position x
        int y;            // This block's position y
        cin >> block_owner >> x >> y;
        grid[y][x] = block_owner;

        if (block_owner == my_id) {
          mySq++;
        } else if (block_owner != -1) {
          hSq++;
        }
        cin.ignore();
      }
    }
    int nextMyBucks = (mySq * 2) + my_bucks;
    int nextHisBucks = (hSq * 2) + opp_bucks;
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
      int level;       // 1 to 10
      int direction;  // The side where the soldier is facing 0 = UP, 1 = LEFT ,
                      // 2 = DOWN, 3 = RIGHT

      cin >> owner_id >> x >> y >> soldier_id >> level >> direction;
      vector<shared_ptr<Soldier>> &targetContainer =
          (owner_id == my_id) ? mine : his;
      targetContainer.push_back(
          std::make_shared<Soldier>(y, x, direction, soldier_id, level));
      if (owner_id != my_id) {
        Point *tmp = his.back()->p;
        grid[tmp->y][tmp->x] = 2;
      }
      cin.ignore();
    }

    // for each soldier
    // enemy in range and enough money?  shoot
    if (nextHisBucks >= 35) {
      for (auto h : his) {
        if (h->lvl > mine[0]->lvl) h->setDanger(grid, map_size);
      }
    }

    for (auto m : mine) {
      for (auto h : his) {
        if (m->canShoot(h) && my_bucks >= 35) {
          cout << "ATTACK " << m->id << " " << h->id << endl;
          goto endLoop;
        }
      }
    }

    if (closestDist(mine, his) < 6) {
      if (mine[0]->lvl < 10) {
        prepareForBattle(mine);
        goto endLoop;
      }
    }

    // check immediate neighbors for best move
    string move = getBestMove(grid, mine, his, map_size, my_id);

    cout << move << endl;

    // print any of actions - WAIT | MOVE <soldierId> <direction> | ATTACK
    // <soldierID> <soldierId to attack on> | LATER > UPGRADE <id> | DEGRADE
    // <opponent id> | SUICIDE <id>
  }
}