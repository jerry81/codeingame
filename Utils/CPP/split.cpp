#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string str = "example string";
  stringstream ss(str);
  string tok;
  while (getline(ss, tok, ' ')) {
    cerr << "tok is " << tok << endl;
  }

}

