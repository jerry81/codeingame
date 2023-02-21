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
    int devsH = 0;
    int sellersH = 0;
    int employees = devs + sellers;
    if (managers <= 3) {
      devsH = min(hire_capacity,empCapacity - employees);
    } else if (managers <= 3) {
      sellersH =  min(hire_capacity,empCapacity - employees);
    } else {
      devsH = min(hire_capacity/2, (empCapacity - employees)/2);
      sellersH = min(hire_capacity/2, (empCapacity-employees)/2);
    }
    int devsP = devsH + devs;
    cerr << "devsP is " << devsP << endl;
    int maint = (devsP * 3)/4;
    cerr << "maint is " << maint << endl;
    int sellersP = sellersH + sellers;
    int comp = sellersP / 2;
    cout << devsH << " " << sellersH << " " << manager << " " << maint << " " << comp << endl;
    // if (totalMktShare < 200) comp = 0;
  }
}