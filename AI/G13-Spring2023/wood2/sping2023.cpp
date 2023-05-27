#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int number_of_cells; // amount of hexagonal cells in this map
    cin >> number_of_cells; cin.ignore();
    for (int i = 0; i < number_of_cells; i++) {
        int type; // 0 for empty, 1 for eggs, 2 for crystal
        int initial_resources; // the initial amount of eggs/crystals on this cell
        int neigh_0; // the index of the neighbouring cell for each direction
        int neigh_1;
        int neigh_2;
        int neigh_3;
        int neigh_4;
        int neigh_5;
        cin >> type >> initial_resources >> neigh_0 >> neigh_1 >> neigh_2 >> neigh_3 >> neigh_4 >> neigh_5; cin.ignore();
        cerr << "type " << type << endl;
                cerr << "neigh_0 " << neigh_0 << endl;
                cerr << "neigh_1 " << neigh_1 << endl;
                cerr << "neigh_2 " << neigh_2 << endl;
                cerr << "neigh_3 " << neigh_3 << endl;
                cerr << "neigh_4 " << neigh_4 << endl;
                cerr << "neigh_5 " << neigh_5 << endl;

    }
    int number_of_bases;
    int baseIdx = 0;
    cin >> number_of_bases; cin.ignore();
    for (int i = 0; i < number_of_bases; i++) {
        int my_base_index;
        cin >> my_base_index; cin.ignore();
        baseIdx = my_base_index;
    }
    for (int i = 0; i < number_of_bases; i++) {
        int opp_base_index;
        cin >> opp_base_index; cin.ignore();
    }

    // game loop
    while (1) {
        int maxR = 0;
        int maxIdx = 0;
        for (int i = 0; i < number_of_cells; i++) {

            int resources; // the current amount of eggs/crystals on this cell
            int my_ants; // the amount of your ants on this cell
            int opp_ants; // the amount of opponent ants on this cell
            cin >> resources >> my_ants >> opp_ants; cin.ignore();
            cerr << "resources " << resources << endl;
                        cerr << "myants " << my_ants << endl;
            if (resources > maxR) {
                maxR = resources;
                maxIdx = i;
            }
        }



        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
        cout << "LINE " + to_string(maxIdx) + " " + to_string(baseIdx) + " 5;" << endl;
    }
}

/*

step 1: naive - put beacon on first available resource

*/