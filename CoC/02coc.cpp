#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 vector<string> split(string str) {
    // Returns first token
    vector<string> ret;
    char *token = strtok(str.data(), ", ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
      ret.push_back(token);
      token = strtok(nullptr, ", ");

    }

    return ret;
  }

int main()
{
    string wishlist;
    getline(cin, wishlist); // The list containing the items to search for.
    int n; // The amount of items you will dig through.
    vector<string> tokens = split(wishlist);
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string item;
        getline(cin, item);
        if (find(tokens.begin(), tokens.end(), item) != tokens.end()) {

         cout << "YOINK" << endl;
        } else {
            cout << "YEET" << endl;
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}

/*

Goal
Given a string representing the item you are currently looking at item while dumpster diving, you must output whether to YEET or to YOINK the item depending on if it is in your wishlist or not.

To "YEET" something means to throw it (discard) and to "YOINK" something means to grab it (keep).
Input
Line 1: Comma-and-space-separated strings wishlist containing the items you wish to keep if found.
Line 2: An integer N for the number of items found in the dumpster.
Next N lines: A case-sensitive string item representing the item you are currently looking at.
Output
N lines: Your response to the item being looked at.
YEET if you should keep the item.
YOINK if you should discard the item.
Constraints
1 ≤ N ≤ 100
Example
Input
Cup, Table, TV
1
TV
Output
YOINK

*/