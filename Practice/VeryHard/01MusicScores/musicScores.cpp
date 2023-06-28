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

string findNote(vector<vector<int>> boundaries, int y, int ledgerThickness) {
  int noteThickness = boundaries[1][0] - boundaries[0][1];
  if (ledgerThickness == 1) ledgerThickness=2;
  // TODO:  "extra ledger, c"
  if (y < (boundaries[0][0] - ledgerThickness)) {
    return "G";
  } else if ((y >= (boundaries[0][0] - ledgerThickness)) &&
             (y <= (boundaries[0][1] + ledgerThickness))) {
    return "F";
  } else if ((y > (boundaries[0][1] + ledgerThickness)) &&
             (y < (boundaries[1][0] - ledgerThickness))) {
    return "E";
  } else if ((y >= (boundaries[1][0] - ledgerThickness)) &&
             (y <= (boundaries[1][1] + ledgerThickness))) {
    return "D";
  } else if ((y > (boundaries[1][1] + ledgerThickness)) &&
             (y < (boundaries[2][0] - ledgerThickness))) {
    return "C";
  } else if ((y >= (boundaries[2][0] - ledgerThickness)) &&
             (y <= (boundaries[2][1] + ledgerThickness))) {
    return "B";
  } else if ((y > (boundaries[2][1] + ledgerThickness)) &&
             (y < (boundaries[3][0] - ledgerThickness))) {
    return "A";
  } else if ((y >= (boundaries[3][0] - ledgerThickness)) &&
             (y <= (boundaries[3][1] + ledgerThickness))) {
    return "G";
  } else if ((y > (boundaries[3][1] + ledgerThickness)) &&
             (y < (boundaries[4][0] - ledgerThickness))) {
    return "F";
  } else if ((y >= (boundaries[4][0] - ledgerThickness)) &&
             (y <= (boundaries[4][1] + ledgerThickness))) {
    return "E";
  } else if ((y > (boundaries[4][1] + ledgerThickness)) && (y < (boundaries[4][1]+noteThickness-ledgerThickness))) {
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
  int ledgerThickness = ledgers.size() / 5;
  vector<vector<int>> ledgerLookup(5, vector<int>(2));
  for (int i = 0; i < 5; ++i) {
    ledgerLookup[i][0] = ledgers[i * ledgerThickness].second;
    ledgerLookup[i][1] = ledgerLookup[i][0] + ledgerThickness - 1;
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
      auto [leftCount, leftCol] = notes[idx * stemWidth];
      // int ccol = stemStarts[idx];
      auto [rightCount, rightCol] = notes[(idx + 1) * stemWidth - 1];

      int ccol = leftCol;
      // if left longer, then take the bottom left
      bool lowerLeft = true;
      cerr << "leftcol " << leftCol << " right col is " << rightCol << endl;
      if (leftCount < rightCount) {
        ccol = rightCol;
        lowerLeft = false;
        cerr << "bean is on upper right, left was " << leftCount
             << " and right was " << rightCount << endl;
        // cerr << "left freq " << cf[leftCol] << " right freq " << cf[rightCol]
        // << endl;
      } else {
        cerr << "bean is on lower left was " << leftCount << " and right was "
             << rightCount << endl;  // TODO: REMOVE
      }

      // if right longer take the top right
      for (int ch = 0; ch < h; ++ch) {
        if (grid[ch][ccol] && !isLine(ledgerLookup, ch)) {
          minStem = min(minStem, ch);
          maxStem = max(maxStem, ch);
        }
      }
      int y = lowerLeft ? maxStem : minStem;
      string noteStr = findNote(ledgerLookup, y, ledgerThickness);
      bool isHalf = true;
      if (lowerLeft) {
        isHalf = !(grid[y][ccol - 2 * stemWidth]);
      } else {
        isHalf = !(grid[y][ccol + 2 * stemWidth]);
      }
      string noteType = isHalf ? "H " : "Q ";
      output += noteStr + noteType;
    } else {
      // can't determine direction based on freq counts
      // must check lower left or upper right
      auto [count, col] = notes[idx];
      for (int ch = 0; ch < h; ++ch) {
        if (grid[ch][col] && !isLine(ledgerLookup, ch)) {
          minStem = min(minStem, ch);
          maxStem = max(maxStem, ch);
        }
      }
      // check lower left

      bool lowerLeft = grid[maxStem + 1][col - 1];
      int y = lowerLeft ? maxStem : minStem;
      string noteStr = findNote(ledgerLookup, y, ledgerThickness);
      bool isHalf = true;
      if (lowerLeft) {
        isHalf = !(grid[y][col - 2 * stemWidth]);
      } else {
        isHalf = !(grid[y][col + 2 * stemWidth]);
      }
      string noteType = isHalf ? "H " : "Q ";
      output += noteStr + noteType;
    }
  }

  output.pop_back();
  cout << output << endl;
}
