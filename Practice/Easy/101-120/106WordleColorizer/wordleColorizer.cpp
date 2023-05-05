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
    unordered_map<char, int> presence_lookup;
    string answer;
    getline(cin, answer);
    for (char c: answer) {
      presence_lookup[c] = true;
    }
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> lookup = presence_lookup;
        string attempt;
        getline(cin, attempt);
        string ans = "";
        for (int i = 0; i < attempt.size(); ++i) {
          if (answer[i] == attempt[i]) {
            ans+='#';
          } else if (lookup[attempt[i]] > 0) {
            ans+= 'O';
            lookup[attempt[i]]--;
          } else {
            ans+= 'X';
          }
        }
        cout << ans << endl;
    }
}

// 2 maps, position, presence