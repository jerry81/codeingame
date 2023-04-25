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

