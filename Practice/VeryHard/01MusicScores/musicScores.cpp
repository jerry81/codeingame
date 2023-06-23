#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string separator) {
  vector<string> ret;
  char* mutableStr = new char[str.size() + 1];
  std::strcpy(mutableStr, str.data());
  char* tok = strtok(mutableStr, separator.c_str());
  while (tok != nullptr) {
    ret.push_back(tok);
    tok = strtok(nullptr, separator.c_str());
  }
  return ret;
}

bool customCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) return true;

  if (a.first < b.first) return false;

  return (a.second < b.second);
}

bool compare2(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int main() {
  int w;
  int h;
  cin >> w >> h;

  cin.ignore();
  string image;
  getline(cin, image);
  vector<string> spl = split(image, " ");

  vector<vector<bool>> grid(h, vector<bool>(w, false));

  bool write = false;
  int cr = 0;
  int cc = 0;
  vector<pair<int, int>> rf(h, {0, 0});
  vector<pair<int, int>> cf(w, {0, 0});
  for (string s : spl) {
    if (s == "W") {
      write = false;
    } else if (s == "B") {
      write = true;
    } else {
      // convert to number
      int moveF = stoi(s);
      while (moveF > 0) {
        if (write) {
          grid[cr][cc] = true;
          rf[cr].first++;

          cf[cc].first++;
        }
        cf[cc].second = cc;
        rf[cr].second = cr;
        cc++;
        if (cc >= w) {
          cc = 0;
          cr++;
        }

        moveF--;
      }
    }
  }
  std::sort(rf.begin(), rf.end(), customCompare);
  std::sort(cf.begin(), cf.end(), customCompare);
  // vector<pair<int,int>> ledgers(rf.begin(), rf.begin()+5);
  // cerr << "ledgers " << endl;
  //  for (auto [i,idx]: ledgers) {
  //    cerr << "i is " << i << " idx is " << idx << endl;
  //  }
  float sum5 = 0;
  for (int i = 0; i < 5; ++i) {
    sum5 += rf[i].first;
  }
  float avg = sum5 / 5.0;
  int totalLedgers = 5;
  float half = avg * .5;
  for (int i = 5; i < h; ++i) {
    if (rf[i].first < half) break;

    totalLedgers = i + 1;
  }

  vector<pair<int, int>> ledgers(rf.begin(), rf.begin() + totalLedgers);

  sort(ledgers.begin(), ledgers.end(), compare2);

  vector<vector<int>> ledgerLookup(5, vector<int>(2));
  int perL = ledgers.size() / 5;
  for (int i = 0; i < 5; ++i) {
    ledgerLookup[i][0] = ledgers[i * perL].second;
    ledgerLookup[i][1] = ledgerLookup[i][0] + perL - 1;
  }
  cerr << "ledgerLookup" << endl;

  for (auto a: ledgerLookup) {
    for (auto b: a) {
      cerr << "min " << b[0] << " max " << b[1] << endl;
    }
  }
  for (auto [a, b] : ledgers) {
    cerr << "ledger " << a << ", " << b << endl;
  }
  // cerr << "rows " << endl;
  // for (auto [i,idx]: rf) {
  //   cerr << i << " and idx is " << idx << ", ";
  // }
  // cerr << endl;
  // cerr << "cols " << endl;
  // for (auto [i, idx]: cf) {
  //   std::cerr << i << " and idx is " << idx << ", ";;
  // }
  cout << "AQ DH" << endl;
}
