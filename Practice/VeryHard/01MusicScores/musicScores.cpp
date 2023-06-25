#include <limits.h>

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

bool isLine(vector<vector<int>> boundaries, int y) {
  return (y >= boundaries[0][0] && y <= boundaries[0][1]) ||
         (y >= boundaries[1][0] && y <= boundaries[1][1]) ||
         (y >= boundaries[2][0] && y <= boundaries[2][1]) ||
         (y >= boundaries[3][0] && y <= boundaries[3][1]) ||
         (y >= boundaries[4][0] && y <= boundaries[4][1]);
}

string findNote(vector<vector<int>> boundaries, int y) {
  int tbd = 1;
  // TODO:  "extra ledger, c"
  if (y < boundaries[0][0]) {
    return "G";
  } else if (y >= boundaries[0][0] && y <= boundaries[0][1]) {
    return "F";
  } else if (y > boundaries[0][1] && y < boundaries[1][0]) {
    return "E";
  } else if (y >= boundaries[1][0] && y <= boundaries[1][1]) {
    return "D";
  } else if (y > boundaries[1][1] && y < boundaries[2][0]) {
    return "C";
  } else if (y >= boundaries[2][0] && y <= boundaries[2][1]) {
    return "B";
  } else if (y > boundaries[2][1] && y < boundaries[3][0]) {
    return "A";
  } else if (y >= boundaries[3][0] && y <= boundaries[3][1]) {
    return "G";
  } else if (y > boundaries[3][1] && y < boundaries[4][0]) {
    return "F";
  } else if (y >= boundaries[4][0] && y <= boundaries[4][1]) {
    return "E";
  } else if (y > boundaries[4][1] && y < tbd) {
    return "D";
  } else {
    return "C";
  }
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

  for (auto vec : ledgerLookup) {
    cerr << "ledger lookup" << endl;
    cerr << vec[0] << " to " << vec[1] << endl;
  }

  // start getting stems

  pair<int, int> firstStem = cf[0];
  float thresh = firstStem.first * .8;
  int idx = 1;
  while (cf[idx].first > thresh) {
    ++idx;
  }
  vector<pair<int, int>> notes(cf.begin(), cf.begin() + idx);
  sort(notes.begin(), notes.end(), compare2);

  // find stem width
  int stemWidth = 1;
  while ((notes[stemWidth].second - notes[stemWidth - 1].second) == 1) {
    stemWidth++;
  }

  int numNotes = notes.size() / stemWidth;

  vector<int> stemStarts;
  for (int idx = 0; idx < numNotes; ++idx) {
    stemStarts.push_back(notes[idx * stemWidth].second);
  }

  string output = "";
  for (int idx = 0; idx < numNotes; ++idx) {
    int minStem = INT_MAX;
    int maxStem = INT_MIN;
    if (stemWidth > 1) {
      int leftCol = notes[idx * stemWidth].second;
      // int ccol = stemStarts[idx];
      int rightCol = leftCol + stemWidth - 1;
      int ccol = leftCol;
      // if left longer, then take the bottom left
      bool lowerLeft = true;
      if (cf[leftCol].first < cf[rightCol].first) {
        ccol = rightCol;
        lowerLeft = false;
        cerr << "bean is on upper right, left was " << leftCol << " and right was " << rightCol << endl;
        // cerr << "left freq " << cf[leftCol] << " right freq " << cf[rightCol] << endl;
      } else {
        cerr << "bean is on lower left " << endl; // TODO: REMOVE
      }

      // if right longer take the top right
      for (int ch = 0; ch < h; ++ch) {
        if (grid[ch][ccol] && !isLine(ledgerLookup, ch)) {
          minStem = min(minStem, ch);
          maxStem = max(maxStem, ch);
        }
        int y = lowerLeft ? maxStem : minStem;
        string noteStr = findNote(ledgerLookup, y);
        output += noteStr + "Q ";
      }
    } else {
      // handle 1 pixel case
    }
  }

  output.pop_back();
  cout << output << endl;
}
