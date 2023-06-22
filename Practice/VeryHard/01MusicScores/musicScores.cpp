#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, string separator) {
  vector<string> ret;
      char* mutableStr = new char[str.size() + 1];
    std::strcpy(mutableStr, str.data());
  char *tok = strtok(mutableStr, separator.c_str());
  while (tok != nullptr) {
    ret.push_back(tok);
    tok = strtok(nullptr, separator.c_str());
  }
  return ret;
}

int main() {
  int w;
  int h;
  // cin >> w >> h;

  // cin.ignore();
  int wtest = 120;
  int htest = 176;

  string test1 = "W 4090 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 1040 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 58 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 80 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 58 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 66 B 10 W 4 B 2 W 103 B 12 W 3 B 2 W 101 B 16 W 1 B 2 W 101 B 16 W 1 B 2 W 100 B 20 W 99 B 21 W 99 B 21 W 98 B 22 W 98 B 22 W 98 B 22 W 98 B 22 W 98 B 22 W 98 B 22 W 98 B 22 W 99 B 20 W 100 B 20 W 101 B 18 W 103 B 16 W 104 B 16 W 106 B 12 W 63 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 2420 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 5050";
  string test2 = "W 4090 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 80 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 58 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 80 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 118 B 2 W 104 B 10 W 4 B 2 W 103 B 12 W 3 B 2 W 101 B 16 W 1 B 2 W 101 B 16 W 1 B 2 W 100 B 20 W 99 B 21 W 99 B 21 W 98 B 22 W 58 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 60 B 22 W 98 B 22 W 99 B 20 W 100 B 20 W 101 B 18 W 103 B 16 W 104 B 16 W 106 B 12 W 109 B 10 W 1384 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 2420 B 100 W 20 B 100 W 20 B 100 W 20 B 100 W 5050";
  string image;
  // getline(cin, image);
  w = wtest;
  h = htest;
  image = test2;
  vector<string> spl = split(image, " ");

  vector<vector<bool>> grid(h, vector<bool>(w, false));

  bool write = false;
  int cr = 0;
  int cc = 0;
  for (string s : spl) {
    if (s == "W") {
      write = false;
    } else if (s == "B") {
      write = true;
    } else {
      // convert to number
      int moveF = stoi(s);
      while (moveF > 0) {
        if (write) grid[cr][cc] = true;
        cc++;
        if (cc >= w) {
          cc = 0;
          cr++;
        }
        moveF--;
      }
    }
  }
  for (auto a: grid) {
    cout << endl;
    for (auto b: a) {
      string toP = (b == true) ? ".":" ";
      cout << toP;
    }
  }
  cout << "AQ DH" << endl;
}
