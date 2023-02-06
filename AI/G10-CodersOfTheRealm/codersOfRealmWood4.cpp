#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Place and pick tiles to build the richest land.
 * You always have player id 0 and your grid is always given first.
 **/

int main()
{

    // game loop
    while (1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 13; j++) {
                string grid_line;
                cin >> grid_line; cin.ignore();
            }
        }
        for (int i = 0; i < 4; i++) {
            int cur_tile_id; // id of a tile being played this turn
            string cur_first_square; // first square of a tile being played this turn
            string cur_second_square; // second square of a tile being played this turn
            int cur_player_id; // id of the player who will place that tile
            int current; // 1 if the tile is in play this turn, 0 otherwise
            cin >> cur_tile_id >> cur_first_square >> cur_second_square >> cur_player_id >> current; cin.ignore();
        }
        for (int i = 0; i < 4; i++) {
            int next_tile_id; // id of a tile to be picked for next turn
            string next_first_square; // first square of a tile to be picked for next turn
            string next_second_square; // second square of a tile to be picked for next turn
            int next_player_id; // id of the player who has picked that tile, -1 if the tile has not been picked yet
            cin >> next_tile_id >> next_first_square >> next_second_square >> next_player_id; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // PUT x y rotation
        // PICK tileId
        cout << "PUT 0 0 0" << endl;
        cout << "PICK 1" << endl;
    }
}
