#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

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
  vector<pair<int,int>> d_2_enemies;
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
  if (u1.x == u2.x) {
    if (u1.y > u2.y) {
      for (int i = u1.y; i != u2.y; --i) {
        if (g_lines[i][u1.x] == 'x') {
          return true;
        }
      }
    } else {
      for (int i = u1.y; i != u2.y; ++i) {
        if (g_lines[i][u1.x] == 'x') {
          return true;
        }
      }
    }

    return false;
  }

  double slope =
      ((double)u1.y - (double)u2.y) / ((double)u1.x - (double)u2.x) * -1;
  if (u1.x > u2.x) {
    for (int x = u1.x; x != u2.x; --x) {
      int y = (int)floor(slope * (double)x) + u1.y;
      if (g_lines[y][x] == 'x') {
        return true;
      }
    }
  } else {
    for (int x = u1.x; x != u2.x; ++x) {
      int y = (int)floor(slope * (double)x) + u1.y;
      if (g_lines[y][x] == 'x') {
        return true;
      }
    }
  }
  return false;
}

int manhattan(Unit u1, Unit u2) { return abs(u1.x - u2.x) + abs(u1.y - u2.y); }

int compare_manhattans(Unit u1, Unit u2) {
  return manhattan(leader, u1) < manhattan(leader, u2);
}

pair<int,int> getClosestEnemyD(Unit u) {
  pair<int,int> closest(-1,7*13);
  for (pair<int,int> p:u.d_2_enemies) {
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
  pair<int,int> prev_loc(-1,-1);

  while (1) {
    bool stuck = false;
    int num_of_units;  // The total number of units on the board
    cin >> num_of_units;
    cin.ignore();
    Unit enemy_leader;
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
      if (u.type == 1) {
        if (u.owner == my_id) {
          leader = u;
          if (leader_moved) {
            if (prev_loc.first>=0) {
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
    for (Unit friendly: friendlies) {
      friendly.d_2_leader = manhattan(friendly, leader);
      friendly.d_2_e_leader = manhattan(friendly, enemy_leader);
      // transform(enemies.begin(), enemies.end(),
      //   [](Unit u) {
      //   }
      // ); seems c++ transform more trouble than just for loop
      for (Unit enemy: enemies) {
        pair<int,int> distance_entry(enemy.id, manhattan(friendly, enemy));
        friendly.d_2_enemies.push_back(distance_entry);
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

      int targetx = my_id ? 12 : 0;
      int targety = my_id ? 6 : 0;
      move(leader.id, targetx, targety);
      continue;
    } else {
      // leader dead!
      // target closest enemy with soldiers
      int cfi = -1;
      int cei = -1;
      int cd = 13*7;
      for (Unit f:friendlies) {
        pair<int,int> closest = getClosestEnemyD(f);
        if (closest.second < cd) {
          cd = closest.second;
          cei = closest.first;
          cfi = f.id;
        }
        if (f.d_2_e_leader < cd) {
          cd = f.d_2_e_leader;
          cfi = f.id;
          cei = enemy_leader.id;
        }
      }
      if (cfi > 0 && cei > 0) {
        shoot(cfi, cei);
        continue;
      }

      // unitId SHOOT targetId
    }
    cout << "WAIT" << endl;
  }
}