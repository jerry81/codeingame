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
  cin >> w >> h;

  cin.ignore();
  string image;
  getline(cin, image);
  vector<string> spl = split(image, " ");

  vector<vector<bool>> grid(h, vector<bool>(w, false));

  bool write = false;
  int cr = 0;
  int cc = 0;
  vector<int> rf(h,0);
  vector<int> cf(w,0);
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
          rf[cr]++;
          cf[cc]++;
        }
        cc++;
        if (cc >= w) {
          cc = 0;
          cr++;
        }
        moveF--;
      }
    }
  }
  cerr << "row freqs " << endl;
  for (int i: rf) {
    cerr << i << ",";
  }
  cerr << endl;
  cerr << "col freqs " << endl;
  for (int i: cf) {
    cerr << i << ",";
  }
  cout << "AQ DH" << endl;
}
