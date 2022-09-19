#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
} Unit;

Unit leader; // global

void move(int unit_id, int x, int y) {
  cout << unit_id << " MOVE " << x << " " << y << endl;
}

void shoot(int unit_id, int target_id) {
  cout << unit_id << " MOVE " << target_id << endl;
}

void convert(int unit_id, int target_id) {
  cout << unit_id << " CONVERT " << target_id << endl;
}

int manhattan(Unit u1, Unit u2) {
  return abs(u1.x - u2.x) + abs(u1.y - u2.y);
}

int compare_manhattans(Unit u1, Unit u2) {
  return manhattan(leader, u1) < manhattan(leader, u2);
}

int adjacent_neutral(Unit leader, vector<Unit> neutrals) {
  // -1 means no adjacent
  if (neutrals.empty()) return -1;

  for (Unit n: neutrals) {
    if (manhattan(leader, n) == 1) {
      return n.id;
    }
  }

  return -1;
}

int main()
{
    int my_id; // 0 - you are the first player, 1 - you are the second player
    cin >> my_id; cin.ignore();
    int width; // Width of the board
    int height; // Height of the board
    cin >> width >> height; cin.ignore();
    string lines[height];
    for (int i = 0; i < height; i++) {
        string y; // A y of the board: "." is empty, "x" is obstacle
        cin >> y; cin.ignore();
        lines[i] = y;
    }

    // game loop
    while (1) {
        int num_of_units; // The total number of units on the board
        cin >> num_of_units; cin.ignore();
        Unit enemy_leader;
        vector<Unit> neutrals;
        vector<Unit> friendlies;
        vector<Unit> enemies;
        for (int i = 0; i < num_of_units; i++) {
            int unit_id; // The unit's ID
            int unit_type; // The unit's type: 0 = Cultist, 1 = Cult Leader
            int hp; // Health points of the unit
            int x; // X coordinate of the unit
            int y; // Y coordinate of the unit
            int owner; // id of owner player
            cin >> unit_id >> unit_type >> hp >> x >> y >> owner; cin.ignore();
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
              } else {
                enemy_leader = u;
              }
            } else { // cultists
              if (u.owner == 2) {
                neutrals.push_back(u);
              } else if (u.owner == my_id) {
                friendlies.push_back(u);
              } else {
                enemies.push_back(u);
              }
            }
        }

        cerr << "my leader pos " << leader.x << "," << leader.y << endl;
        cerr << "enemy leader pos " << enemy_leader.x << "," << enemy_leader.y << endl;
        for (Unit u:neutrals) {
          cerr << "neutral at " << u.x << "," << u.y <<endl;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // WAIT | unitId MOVE x y | unitId SHOOT target| unitId CONVERT target
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


        cout << "WAIT" << endl;
    }
}