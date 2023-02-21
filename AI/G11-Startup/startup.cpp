#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Get the market!
 **/

int main() {
  int dev_cap = 4;
  int seller_cap = 4;

  // game loop
  while (1) {
    int id;  // Your player id
    cin >> id;
    cin.ignore();
    int player_count;  // Number of players
    cin >> player_count;
    cin.ignore();
    int turn;  // Number of turns since the beginning
    cin >> turn;
    cin.ignore();
    int income;  // Your income for this turn
    cin >> income;
    cin.ignore();
    int cash;  // Cash of your start-up
    cin >> cash;
    cin.ignore();
    int devs;
    cin >> devs;
    cin.ignore();
    int sellers;
    cin >> sellers;
    cin.ignore();
    int managers;
    cin >> managers;
    cin.ignore();
    int features;
    cin >> features;
    cin.ignore();
    int tests;  // Tests developed in your software
    cin >> tests;
    cin.ignore();
    int bugs;  // Bugs in your software
    cin >> bugs;
    cin.ignore();
    cerr << " we have " << bugs << " bugs " << endl;
    int totalMktShare = 0;
    for (int i = 0; i < player_count; i++) {
      int start_up_id;   // Start-up id
      int market_share;  // Market share of the start-up in thousands
      int reputation;    // Reputation of the start-up
      cin >> start_up_id >> market_share >> reputation;
      cin.ignore();
      totalMktShare += market_share;
    }
    cerr << "we are on turn " << turn << endl;
    cerr << " we have " << devs << " devs " << endl;
    cerr << " we have " << sellers << " sellers " << endl;
    cerr << " we have " << managers << " managers " << endl;
    cerr << " we have " << features << " features " << endl;
    cerr << " we have " << bugs << " bugs " << endl;
    cerr << " we have " << tests << " tests " << endl;
    cerr << "cash " << cash << endl;
    cerr << "income is " << income << endl;
    int salaries = 10 * devs + 10 * sellers + 20 * managers;
    cerr << "salaries is " << salaries << endl;
    int net = income - salaries;
    cerr << "net is " << net << endl;
    int hire_capacity = managers * 2;
    bool manager = true;
    int empCapacity = managers * 4;
    int devsH, sellersH = 0;
    if (managers <= 3) {
      devsH = empCapacity - managers;
    } else if (managers <= 6) {
      sellersH = empCapacity - managers;
    }
    int maint = devsH * (3/4);
    int comp = sellersH / 2;
    cout << devsH << " " << sellersH << " " << manager << " " << maint << " " << comp << endl;
    // if (totalMktShare < 200) comp = 0;
  }
}