// https://www.codingame.com/ide/puzzle/wordle-colorizer

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    unordered_map<char, int> position_lookup;
    unordered_map<char, bool> presence_lookup;
    string answer;
    getline(cin, answer);
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string attempt;
        getline(cin, attempt);
    }


    cout << "OXOXO" << endl;
}

// 2 maps, position, presence