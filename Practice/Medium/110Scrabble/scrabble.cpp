/*

The Goal
When playing Scrabble©, each player draws 7 letters and must find a word that
scores the most points using these letters.

A player doesn't necessarily have to make a 7-letter word; the word can be
shorter. The only constraint is that the word must be made using the 7 letters
which the player has drawn.

For example, with the letters  etaenhs, some possible words are: ethane, hates,
sane, ant.

Your objective is to find the word that scores the most points using the
available letters (1 to 7 letters).

 Rules
In Scrabble©, each letter is weighted with a score depending on how difficult it
is to place that letter in a word. You will see below a table showing the points
corresponding to each letter:


Letters	Points
e, a, i, o, n, r, t, l, s, u	1
d, g	2
b, c, m, p	3
f, h, v, w, y	4
k	5
j, x	8
q, z	10
The word banjo earns you 3 + 1 + 1 + 8 + 1 = 14 points.

A dictionary of authorized words is provided as input for the program. The
program must find the word in the dictionary which wins the most points for the
seven given letters (a letter can only be used once). If two words win the same
number of points, then the word which appears first in the order of the given
dictionary should be chosen.


All words will only be composed of alphabetical characters in lower case. There
will always be at least one possible word.

 Game Input
Input
Line 1: the number N of words in the dictionary

N following lines: the words in the dictionary. One word per line.

Last line: the 7 letters available.

Output
The word that scores the most points using the available letters (1 to 7
letters). The word must belong to the dictionary. Each letter must be used at
most once in the solution. There is always a solution. Constraints 0 < N <
100000 Words in the dictionary have a maximum length of 30 characters. Example
Input
5
because
first
these
could
which
hicquwh
Output
which

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> lookup;

int tally_points(string s) {
  int tally = 0;
  for (char c:s) {
    tally+=lookup[c];
  }
  return tally;
}

int max_points = 0;
string best_string = "";

void build_lookup() {
  lookup['e'] = 1;
  lookup['a'] = 1;
  lookup['i'] = 1;
  lookup['o'] = 1;
  lookup['n'] = 1;
  lookup['r'] = 1;
  lookup['t'] = 1;
  lookup['l'] = 1;
  lookup['s'] = 1;
  lookup['u'] = 1;
  lookup['d'] = 2;
  lookup['g'] = 2;
  lookup['b'] = 3;
  lookup['c'] = 3;
  lookup['m'] = 3;
  lookup['p'] = 3;
  lookup['f'] = 4;
  lookup['h'] = 4;
  lookup['v'] = 4;
  lookup['w'] = 4;
  lookup['y'] = 4;
  lookup['k'] = 5;
  lookup['j'] = 8;
  lookup['x'] = 8;
  lookup['q'] = 10;
  lookup['z'] = 10;
}

unordered_map<char, int> freq_in_hand;

unordered_map<char, int> build_freq(string letters) {
  unordered_map<char, int> freq;
  for (char c:letters) {
    bool contains = freq.find(c)!=freq_in_hand.end();
    if (contains) {
      ++freq[c];
    } else {
      freq[c] = 1;
    }
  }
  return freq;
}
vector<string> dict_items;

bool can_build(string w) {
  unordered_map<char, int> temp = freq_in_hand;
  for (char c:w) {
    if (temp.find(c) == temp.end()) {
      return false;
    }

    if (--temp[c] < 0) {
      return false;
    }
  }
  return true;
}


int get_points(string w) {
  bool test = can_build(w);
  return can_build(w) ? tally_points(w):0;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string w;
    getline(cin, w);
    dict_items.push_back(w);
  }

  build_lookup();
  string letters;
  getline(cin, letters);
  freq_in_hand = build_freq(letters);
  for (string word:dict_items) {
    int pts = get_points(word);
    if (pts > max_points) {
      max_points = pts;
      best_string = word;
    }
  }


  cout << best_string << endl;
}