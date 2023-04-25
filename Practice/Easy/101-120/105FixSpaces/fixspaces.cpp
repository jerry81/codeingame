/*

	Goal
You are given two strings, the first contains the original sentence, with words in the right order but no spaces. The second has the words in random order but with spaces to differentiate them. Fix the original sentence by adding spaces where they should be.

Every test has at least one solution, but there are some cases where the original sentence can not unambiguously be deciphered. In those cases print Unsolvable.

NB: Tests 1-14 cover simple cases and should help you debug your program. Tests 15-16 check the performance.
Input
Line 1 : A string. The original sentence, with words in the right order but no spaces.
Line 2 : A string containing the words in random order but with spaces to differentiate them.
Output
The original sentence with the necessary spaces added to it or the string Unsolvable.
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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;


struct TrieNode {
  unordered_map<char, TrieNode*> children;
  string path = "";
};

vector<string> split(string str, char* delimiter = " ") {
  // Returns first token
  vector<string> ret;

  char *token = strtok(str.data(), delimiter);

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, " ");
  }

  return ret;
}

int main()
{
    TrieNode* root = new TrieNode();
    string original;
    getline(cin, original);
    string words;
    getline(cin, words);
    vector<string> spl = split(words, " ");

    for (string s: spl) {
      TrieNode* cur = root;

      for (char c: s) {
        if (cur->children.find(c) == cur->children.end()) {
          cur->children[c] = new TrieNode();
          cur->children[c]->path = s;
        }

        cur = cur->children[c];
      }
    }
    string ret = "";
    TrieNode* cur = root;
    for (char c: original) {
      if (cur->children.find(c) == cur->children.end()) {
        ret += ' ';
        cur = root;
      }

      if (cur->children.find(c) == cur->children.end()) {
        cout << "Unsolvable" << endl;
      }


      ret += c;
      cur = cur->children[c];
    }
    cout << ret << endl;
}

// ABCAFEAHI
// AHI AFE ABC

// build trie?
//       A
//  H    F     B
//  I    E     C
