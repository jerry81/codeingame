#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Get the market!
 **/

int main()
{

    // game loop
    while (1) {
        int id; // Your player id
        cin >> id; cin.ignore();
        int player_count; // Number of players
        cin >> player_count; cin.ignore();
        int turn; // Number of turns since the beginning
        cin >> turn; cin.ignore();
        int income; // Your income for this turn
        cin >> income; cin.ignore();
        int cash; // Cash of your start-up
        cin >> cash; cin.ignore();
        int devs;
        cin >> devs; cin.ignore();
        int sellers;
        cin >> sellers; cin.ignore();
        int managers;
        cin >> managers; cin.ignore();
        int features;
        cin >> features; cin.ignore();
        int tests; // Tests developed in your software
        cin >> tests; cin.ignore();
        int bugs; // Bugs in your software
        cin >> bugs; cin.ignore();
        for (int i = 0; i < player_count; i++) {
            int start_up_id; // Start-up id
            int market_share; // Market share of the start-up in thousands
            int reputation; // Reputation of the start-up
            cin >> start_up_id >> market_share >> reputation; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // <devsToHire> <sellerToHire> <managersToHire> <maintenanceDevs> <competitiveSellers> <targetId>
        cout << "0 0 0 0 0" << endl;
    }
}