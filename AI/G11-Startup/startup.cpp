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
    int dev_cap = 4;
    int seller_cap = 4;

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

       cerr << "cash " << cash << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cerr << "income is " << income << endl;
        int salaries = 10 * devs + 10 * sellers + 20 * managers;
                cerr << "salaries is " << salaries << endl;

        int net = income - salaries;
        cerr << "net is " << net << endl;
        // <devsToHire> <sellerToHire> <managersToHire> <maintenanceDevs> <competitiveSellers> <targetId>
        char maint = (devs/2) + '0';
        char comp = (sellers/2) + '0';
        int capacity = managers * 2;
        int toHire = min(capacity, 4);
        int toHireSellers = min(capacity, 1);
        cerr << "features is " << features << endl;
        if (devs < dev_cap) {
            cout << toHire << " 0 1 " << maint << " 0" << endl;
        } else if ((sellers < seller_cap) && (features >= 10)) {
            cout << "0 " << toHire << " 1 4 " << comp << endl;
        } else {
          cout << "0 0 0 4 0" << endl;
        }
    }
}