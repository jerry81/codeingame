#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str) {
  // Returns first token
  vector<string> ret;
  char *token = strtok(str.data(), " ");

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, " ");
  }

  return ret;
}

vector<string> getTabloid(string s1, string s2) {
  int longestMatch = 0;
  vector<string> matches;
  for (int i = 0; i < s1.size(); ++i) {
    char c1 = tolower(s1[i]);
    string prefix1 = s1.substr(0, i);
    string suffix1 = s1.substr(i);
    for (int j = 0; j < s2.size(); ++j) {
      char c2 = tolower(s2[j]);
      if (c1 == c2) {
        string prefix2 = s2.substr(0, j);
        string suffix2 = s2.substr(j);
        // check overlap len
        int offset = 1;
        while ((offset + i) < s1.size() && (offset + j) < s2.size()) {
          if (s1[offset + i] != s2[offset + j]) {
            break;
          }
          offset++;
        }
        string toTest1 = prefix1 + suffix2;
        string toTest2 = prefix2 + suffix1;
        bool t1Pass = toTest1 != s1 && toTest1 != s2;
        t1Pass = t1Pass &&
                 (toTest1.size() >= s1.size() && toTest1.size() >= s2.size());
        bool t2Pass = toTest2 != s1 && toTest2 != s2;
        t2Pass = t2Pass &&
                 (toTest2.size() >= s1.size() && toTest2.size() >= s2.size());
        bool valid = t1Pass || t2Pass;
        if (!valid) continue;
        if (offset >= longestMatch) {
          if (offset > longestMatch) {
            longestMatch = offset;
            matches.clear();
          }
          if (t1Pass) matches.push_back(toTest1);
          if (t2Pass) matches.push_back(toTest2);
        }
        // make the two names
      }
    }

  }
    return matches;
}

void normalize(string &input) {
  for (int i = 1; i < input.size(); ++i) {
    input[i] = tolower(input[i]);
  }
  input[0] = toupper(input[0]);
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string a_couple;
    getline(cin, a_couple);
    vector<string> spl = split(a_couple);
    vector<string> res = getTabloid(spl[0], spl[2]);
    string suff = "";

    for (auto a: res) {
      normalize(a);
      suff += a;
      suff += " ";
    }
    if (res.empty()) suff = "NONE ";
    suff.pop_back();
    cout << spl[0] << " plus " << spl[2] << " = " << suff << endl;
  }

}