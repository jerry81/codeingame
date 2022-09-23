#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

/**
 * Convert neutral units and attack enemy ones
 **/

typedef struct Unit {
  int id;
  int type;
  int hp;
  int x;
  int y;
  int owner;
  int d_2_leader;
  int d_2_e_leader;
  vector<pair<int, int>> d_2_enemies;
} Unit;

unordered_map<int, Unit> units_map;

Unit leader;  // global
vector<string> g_lines;
bool leader_moved = false;

void move(int unit_id, int x, int y) {
  if (leader.id == unit_id) {
    leader_moved = true;
  } else {
    leader_moved = false;
  }
  cout << unit_id << " MOVE " << x << " " << y << endl;
}

void shoot(int unit_id, int target_id) {
  leader_moved = false;
  cout << unit_id << " SHOOT " << target_id << endl;
}

void convert(int unit_id, int target_id) {
  leader_moved = false;
  cout << unit_id << " CONVERT " << target_id << endl;
}

bool path_has_obstacle(Unit u1, Unit u2) {
  cerr << "calc path obstacle from " << u1.id << " to " << u2.id << endl;
  if (u1.x == u2.x) {
    if (u1.y > u2.y) {
      for (int i = u1.y; i != u2.y; --i) {
        if (g_lines[i][u1.x] == 'x') {
          cerr << "end calc path obstacle" << endl;
          return true;
        }
      }
    } else {
      for (int i = u1.y; i != u2.y; ++i) {
        if (g_lines[i][u1.x] == 'x') {
          cerr << "end calc path obstacle" << endl;
          return true;
        }
      }
    }
    cerr << "end calc path obstacle" << endl;
    return false;
  }
  // slope depends on which is relatively left
  Unit left;
  Unit right;
  bool u1_left = u1.x < u2.x;
  left = u1_left ? u1 : u2;
  right = u1_left ? u2 : u1;
  double slope =
      (((double)right.y - (double)left.y) / ((double)right.x - (double)left.x));
  cerr << "slope is " << slope << endl;
  for (int x = 1; x < (right.x - left.x); ++x) {
    cerr << "left.y " << left.y << endl;
    int y = (int)floor(slope * (double)x) + left.y;
    fprintf(stderr, "y is %d x is %d\n", y, x);
    if (g_lines[y][x] ==
        'x') {  // negative number discovered here, it will break
      cerr << "end calc path obstacle" << endl;
      return true;
    }
  }
  cerr << "end calc path obstacle" << endl;
  return false;
}

int manhattan(Unit u1, Unit u2) { return abs(u1.x - u2.x) + abs(u1.y - u2.y); }

int compare_manhattans(Unit u1, Unit u2) {
  return manhattan(leader, u1) < manhattan(leader, u2);
}

pair<int, int> getClosestEnemyD(Unit u) {
  pair<int, int> closest(-1, 7 * 13);
  for (pair<int, int> p : u.d_2_enemies) {
    if (p.second < closest.second) {
      closest = p;
    }
  }
  return closest;
}

int adjacent_neutral(Unit leader, vector<Unit> neutrals) {
  // -1 means no adjacent
  if (neutrals.empty()) return -1;

  for (Unit n : neutrals) {
    if (manhattan(leader, n) == 1) {
      return n.id;
    }
  }

  return -1;
}

int main() {
  int my_id;  // 0 - you are the first player, 1 - you are the second player
  cin >> my_id;
  cin.ignore();
  int width;   // Width of the board
  int height;  // Height of the board
  cin >> width >> height;
  cin.ignore();
  string lines[height];
  for (int i = 0; i < height; i++) {
    string y;  // A y of the board: "." is empty, "x" is obstacle
    cin >> y;
    cin.ignore();
    lines[i] = y;
    g_lines.push_back(y);
  }

  // game loop
  pair<int, int> prev_loc(-1, -1);

  while (1) {
    bool stuck = false;
    int num_of_units;  // The total number of units on the board
    cin >> num_of_units;
    cin.ignore();
    Unit enemy_leader;
    bool enemy_leader_alive = false;
    vector<Unit> neutrals;
    vector<Unit> friendlies;
    vector<Unit> enemies;
    bool leader_alive = false;
    for (int i = 0; i < num_of_units; i++) {
      int unit_id;    // The unit's ID
      int unit_type;  // The unit's type: 0 = Cultist, 1 = Cult Leader
      int hp;         // Health points of the unit
      int x;          // X coordinate of the unit
      int y;          // Y coordinate of the unit
      int owner;      // id of owner player
      cin >> unit_id >> unit_type >> hp >> x >> y >> owner;
      cin.ignore();
      Unit u;
      u.id = unit_id;
      u.type = unit_type;
      u.hp = hp;
      u.x = x;
      u.y = y;
      u.owner = owner;
      units_map[unit_id] = u;
      if (u.type == 1) {
        if (u.owner == my_id) {
          leader = u;
          if (leader_moved) {
            if (prev_loc.first >= 0) {
              if (prev_loc.first == u.x && prev_loc.second == u.y) {
                stuck = true;
              }
            }
          }
          prev_loc.first = u.x;
          prev_loc.second = u.y;
          leader_alive = leader.hp > 0;
        } else {
          enemy_leader = u;
          enemy_leader_alive = enemy_leader.hp > 0;
        }
      } else {  // cultists
        if (u.owner == 2) {
          neutrals.push_back(u);
        } else if (u.owner == my_id) {
          friendlies.push_back(u);
        } else {
          enemies.push_back(u);
        }
      }
    }

    // populate distances
    /*
      int d_2_leader;
      int d_2_e_leader;
      vector<pair<int,int>> d_2_enemies;
    */
    // for (Unit friendly: friendlies) { TIL: without pointer, this won't update
    for (int i = 0; i < friendlies.size(); ++i) {
      int m_dist_l = manhattan(friendlies.at(i), leader);
      int m_dist_e_l = manhattan(friendlies.at(i), enemy_leader);
      friendlies.at(i).d_2_leader = m_dist_l;
      friendlies.at(i).d_2_e_leader = m_dist_e_l;
      units_map[friendlies.at(i).id].d_2_leader = m_dist_l;
      units_map[friendlies.at(i).id].d_2_e_leader = m_dist_e_l;

      // transform(enemies.begin(), enemies.end(),
      //   [](Unit u) {
      //   }
      // ); seems c++ transform more trouble than just for loop
      for (Unit enemy : enemies) {
        pair<int, int> distance_entry(enemy.id,
                                      manhattan(friendlies.at(i), enemy));
        fprintf(stderr, "calculating friendly %d to enemy %d\n",
                friendlies.at(i).id, enemy.id);
        bool obs = path_has_obstacle(friendlies.at(i), enemy);
        fprintf(stderr, "friendly %d to enemy %d is %d\n", friendlies.at(i).id,
                enemy.id, obs);
        friendlies.at(i).d_2_enemies.push_back(distance_entry);
        units_map[friendlies.at(i).id].d_2_enemies.push_back(distance_entry);
      }
    }

    // WAIT | unitId MOVE x y | unitId SHOOT target| unitId CONVERT target
    if (leader_alive && !stuck) {
      int neutral_id = adjacent_neutral(leader, neutrals);
      if (neutral_id > -1) {
        convert(leader.id, neutral_id);
        continue;
      }

      if (!neutrals.empty()) {
        sort(neutrals.begin(), neutrals.end(), compare_manhattans);
        move(leader.id, neutrals.front().x, neutrals.front().y);
        continue;
      }

      // int targetx = my_id ? 12 : 0;
      // int targety = my_id ? 6 : 0;
      // move(leader.id, targetx, targety);
      // continue;
    }
    // leader dead!
    // target closest enemy with soldiers
    int cfi = -1;
    int cei = -1;
    int cd = 13 * 7;
    for (Unit f : friendlies) {
      cerr << "analyzing friendly " << endl;
      pair<int, int> closest = getClosestEnemyD(f);
      cerr << "closest " << closest.first << endl;
      if (closest.second < cd) {
        cd = closest.second;
        cei = closest.first;
        cfi = f.id;
      }
      cerr << "analyze enemy leader " << endl;
      if (enemy_leader_alive && (f.d_2_e_leader < cd)) {
        cd = f.d_2_e_leader;
        cfi = f.id;
        cei = enemy_leader.id;
      }
      cerr << "enemy leader analyzed " << endl;
    }
    cerr << "cfi is " << cfi << " and cei is " << cei << endl;
    if (cfi >= 0 && cei >= 0) {
      shoot(cfi, cei);
      continue;
    }
    cout << "WAIT" << endl;
  }
  // unitId SHOOT targetId
}