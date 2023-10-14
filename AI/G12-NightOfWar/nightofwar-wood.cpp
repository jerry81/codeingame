#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Jrke's special
 * -Kill your enemy soldiers or Have more bucks than your enemy at end of game
 **/

enum Direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };
vector<vector<int>> movements = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Point {
  int x;
  int y;
  Point(int y, int x) : x(x), y(y){};
  void print() { cerr << "point: " << y << ", " << x << endl; }
  string to_h() { return y + "," + x; }
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

struct BFSNode {
  Point *p;
  Direction d;
  BFSNode *startDir;
  string to_h() { return p->to_h() + "," + to_string(d); }
  BFSNode(Point *p, Direction d) : p(p), d(d){};
};

struct Soldier {
  Point *p;
  Direction d;
  int id;
  Soldier(int y, int x, int dir, int id) : id(id) {
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

          if (ny < sz && ny >= 0) grid[nx][ny] = 2;
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
          if (nx >= 0) grid[cy][nx] = 2;
        }

        int ny = cy - 1;
        if (ny < 0) break;

        for (int delta : {-1, 1}) {
          int nx = cx + delta;

          if (nx < sz && nx >= 0) grid[nx][ny] = 2;
        }
        break;
      }
      case DOWN: {
        for (int dy : {1, 2}) {
          int ny = cy + dy;
          if (ny < sz) grid[ny][cx] = 2;
          int nx = cx + dy;
          if (nx >= 0) grid[cy][nx] = 2;
          nx = cx - dy;
          if (nx >= 0) grid[cy][nx] = 2;
        }

        int ny = cy + 1;
        if (ny >= sz) break;

        for (int delta : {-1, 1}) {
          int nx = cx + delta;

          if (nx < sz && nx >= 0) grid[nx][ny] = 2;
        }
        break;
      }
      default: {  // RIGHT
        for (int dx : {1, 2}) {
          int nx = cx + dx;
          if (nx < sz) grid[cy][nx] = 2;
          int ny = cy + dx;
          if (ny >= 0) grid[ny][cx] = 2;
          ny = cy - dx;
          if (ny >= 0) grid[ny][cx] = 2;
        }

        int nx = cx + 1;
        if (nx > sz) break;

        for (int delta : {-1, 1}) {
          int ny = cy + delta;

          if (ny < sz && ny >= 0) grid[nx][ny] = 2;
        }
        break;
      }
    }
  }

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

  bool canShoot(Point *ep) {
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

const int DANGER = 2;

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
    vector<vector<int>> grid(map_size, vector<int>(map_size, 0));
    for (int i = 0; i < map_size; i++) {
      for (int j = 0; j < map_size; j++) {
        int block_owner;  // The playerId of this box owned player
        int x;            // This block's position x
        int y;            // This block's position y
        cin >> block_owner >> x >> y;
        grid[y][x] = block_owner;
        if (block_owner == my_id) {
          mySq++;
        } else {
          hSq++;
        }
        cin.ignore();
      }
    }
    int nextMyBucks = mySq * 2 + my_bucks;
    int nextHisBucks = hSq * 2 + opp_bucks;
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

    // for each soldier
    // enemy in range and enough money?  shoot

    for (auto m : mine) {
      for (auto h : his) {
        if (m->canShoot(h->p) && my_bucks >= 35) {
          cout << "ATTACK " << m->id << " " << h->id << endl;
          goto endLoop;
        }
      }
    }

    // move logic

    // start a lookahead to find current options?
    // bfs find shortest path to a enemy block // return first item in path

    // print any of actions - WAIT | MOVE <soldierId> <direction> | ATTACK
    // <soldierID> <soldierId to attack on> | LATER > UPGRADE <id> | DEGRADE
    // <opponent id> | SUICIDE <id>
    cout << "WAIT" << endl;
  }
}