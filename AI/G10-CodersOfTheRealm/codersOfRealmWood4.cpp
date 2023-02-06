#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Tile {
  char type = '_';
  int crowns = 0;
  void print() {
    cerr << "tile type is " << type << " crowns is " << crowns << endl;
  }
};

struct Grid {
  vector<string> rawGrid;
  vector<vector<Tile>> g;
  void addLine(string line) {
    // convert line to vector of tiles
    vector<Tile> tiles;
    rawGrid.push_back(line);
    for (int i = 0; i < 13; ++i) {
      Tile ti;
      int start = i * 2;
      ti.type = line[start];
      ti.crowns = line[start+1] - '0';
      tiles.push_back(ti);
    }
    g.push_back(tiles);
  }
};

int main()
{

    Grid my_grid;

    // game loop
    while (1) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 13; j++) {
                string grid_line;
                cin >> grid_line; cin.ignore();
                if (i == 0) {
                  my_grid.addLine(grid_line);
                }
            }
        }

        for (int i = 0; i < 13; ++ i) {
          for (int j = 0; j < 13; ++ j) {
            cerr << "i " << i << endl;
            cerr << "j " << j << endl;
            my_grid.g[i][j].print();
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
