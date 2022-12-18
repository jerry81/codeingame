#include <iostream>
using namespace std;

int main() {
  cerr << "expect b: " << (char) ('a' + 1) << endl;

  cerr << "what's after z? Answer: " << (char) ('z' + 1) << endl;

  char c = 'a';
  while (c != '{') {
    cerr << "next char is " << c << endl;
    c = (char) (c + 1);
  }
  return 0;
}