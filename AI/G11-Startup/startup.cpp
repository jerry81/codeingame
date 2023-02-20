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
        cerr << "we are on turn " << turn << endl;
        cin >> turn; cin.ignore();
        int income; // Your income for this turn
        cin >> income; cin.ignore();
        int cash; // Cash of your start-up
        cin >> cash; cin.ignore();
        int devs;
        cin >> devs; cin.ignore();
        cerr << " we have " << devs << " devs " << endl;
        int sellers;
        cin >> sellers; cin.ignore();
        cerr << " we have " << sellers << " sellers " << endl;
        int managers;
        cin >> managers; cin.ignore();
        cerr << " we have " << managers << " managers " << endl;
        int features;
        cin >> features; cin.ignore();
        int tests; // Tests developed in your software
        cin >> tests; cin.ignore();
        cerr << " we have " << tests << " tests " << endl;
        int bugs; // Bugs in your software
        cin >> bugs; cin.ignore();
        cerr << " we have " << bugs << " bugs " << endl;
        int totalMktShare = 0;
        for (int i = 0; i < player_count; i++) {
            int start_up_id; // Start-up id
            int market_share; // Market share of the start-up in thousands
            int reputation; // Reputation of the start-up
            cin >> start_up_id >> market_share >> reputation; cin.ignore();
            totalMktShare+=market_share;
        }

        cerr << "total is " << totalMktShare << endl;

       cerr << "cash " << cash << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cerr << "income is " << income << endl;
        int salaries = 10 * devs + 10 * sellers + 20 * managers;
                cerr << "salaries is " << salaries << endl;

        int net = income - salaries;
        cerr << "net is " << net << endl;
        // <devsToHire> <sellerToHire> <managersToHire> <maintenanceDevs> <competitiveSellers> <targetId>
        cerr << "devs is " << devs << endl;
        int maintanenceCount = ((devs-1) > 0) ? (devs-1) : 0;

        if (maintanenceCount > 10) maintanenceCount -= (maintanenceCount/4);
        string maint = to_string(maintanenceCount);
       // string comp = to_string(sellers/2);
        int capacity = managers * 2;
        int toHire = min(capacity, 4);
        int mgrs = ((managers*4) < (devs + sellers)) ? 0:1;
        int toHireSellers = min(capacity, 1);
        cerr << "features is " << features << endl;
        if (net > 0 && cash > 500) {
          dev_cap++;
          seller_cap++;
        }
       int comp = sellers / 2;
       //if (totalMktShare < 200) comp = 0;

       if (totalMktShare > 900) comp = (sellers);
        if (devs < dev_cap && ((devs - sellers) < 8)) {
            cout << toHire << " 0 " << mgrs << " " << maint << " " << comp << endl;
        } else if ((sellers < seller_cap) && (features >= 10)) {
            cout << "0 " << toHire << " " << mgrs << " " << maint << " " << comp << endl;
        } else {
          cout << "0 0 0 " << maint << " " << comp << endl;
        }
    }
}