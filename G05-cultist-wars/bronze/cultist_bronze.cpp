#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Convert neutral units and attack enemy ones
 **/

void move(int unit_id, int x, int y) {
  cout << unit_id << " MOVE " << x << " " << y << endl;
}

void shoot(int unit_id, int target_id) {
  cout << unit_id << " MOVE " << target_id << endl;
}

void convert(int unit_id, int target_id) {
  cout << unit_id << " CONVERT " << target_id << endl;
}

typedef struct Unit {
  int id;
  int type;
  int hp;
  int x;
  int y;
  int owner;
} Unit;

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
        for (int i = 0; i < num_of_units; i++) {
            int unit_id; // The unit's ID
            int unit_type; // The unit's type: 0 = Cultist, 1 = Cult Leader
            int hp; // Health points of the unit
            int x; // X coordinate of the unit
            int y; // Y coordinate of the unit
            int owner; // id of owner player
            cin >> unit_id >> unit_type >> hp >> x >> y >> owner; cin.ignore();

        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // WAIT | unitId MOVE x y | unitId SHOOT target| unitId CONVERT target
        cout << "WAIT" << endl;
    }
}