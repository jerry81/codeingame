/*

        Goal
You are given two strings, the first contains the original sentence, with words
in the right order but no spaces. The second has the words in random order but
with spaces to differentiate them. Fix the original sentence by adding spaces
where they should be.

Every test has at least one solution, but there are some cases where the
original sentence can not unambiguously be deciphered. In those cases print
Unsolvable.

NB: Tests 1-14 cover simple cases and should help you debug your program. Tests
15-16 check the performance. Input Line 1 : A string. The original sentence,
with words in the right order but no spaces. Line 2 : A string containing the
words in random order but with spaces to differentiate them. Output The original
sentence with the necessary spaces added to it or the string Unsolvable.
Constraints
The original string only contains uppercase letters.
The words string only contains uppercase letters and spaces.
Each word in words appears the same number of times in words and in original.
Each string is at most 1000 characters long.
The number of words is at most 200.
Example
Input
ABCDEFGHIJ
DEF J ABC GHI
Output
ABC DEF GHI J

*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

vector<string> split(string str, char* delimiter = " ") {
  // Returns first token
  vector<string> ret;

  char* token = strtok(str.data(), delimiter);

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, " ");
  }

  return ret;
}

void solvecountR(string remainstring, vector<string> remainwords,
                 string curstring, set<string>& solutions) {
  if (remainstring.size() == 0 && remainwords.size() == 0) {
    solutions.insert(curstring);
    return;
  }

  for (int i = 0; i < remainwords.size(); ++i) {
    vector<string> copied = remainwords;
    int testSize = remainwords[i].size();
    string substr = remainstring.substr(0, testSize);

    if (substr == remainwords[i]) {
      copied.erase(copied.begin() + i);
      solvecountR(remainstring.substr(testSize), copied,
                  curstring + substr + " ", solutions);
    }
  }
}

int main() {
  string original;
  getline(cin, original);
  string words;
  getline(cin, words);
  vector<string> spl = split(words, " ");
  set<string> solutions;
  solvecountR(original, spl, "", solutions);

  if (solutions.size() == 1) {
    for (auto a: solutions) {
        a.pop_back();
        cout << a << endl;
    }
  } else {
    cout << "Unsolvable" << endl;
  }


  return 0;
}

// ABCAFEAHI
// AHI AFE ABC

// build trie?
//       A
//  H    F     B
//  I    E     C

/*

broken case

ABABCDCDEABCDEABCD
CDE AB ABCD CDE AB ABCD

expected: AB ABCD CDE AB CDE ABCD
fails at: AB ABCD CDE ABCD
*/

// brute force

// try fitting each

// optimization options
// index by first letter
// then instead of deleting from array, we can just "mark" items as visited using bool