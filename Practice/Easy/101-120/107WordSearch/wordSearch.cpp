/*

Goal
Word Search is a type of puzzle that asks the player to search for various words
within a grid of letters. They can be vertical, horizonal, backwards, diagonal,
etc. If you are unfamiliar with it, see banner image and/or
https://en.wikipedia.org/wiki/Word_search

But as a computer geek, that doesn't interest you; you want to program a way to
find those words instead.

Input will be a square grid of size lines (each line is size letters long),
followed by all the words to find.

Output the same square grid but hide any letters that aren't included in those
words.

~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

NOTE: If you enjoy this puzzle, see this similar one:
https://www.codingame.com/training/medium/hidden-word Input Line 1: An integer
size, denoting the number of lines of input Next size lines: A string ROW of
that square grid Next line: A string clues of all the words to find, separated
by spaces Output size lines: ROW with the unused letters hidden. In other words,
all unused characters should be replaced by a space character. Trailing spaces
should NOT be trimmed. Constraints • Each clue of clues has only letters (no
spaces). • clues are given in capitalized case (but look for the all-caps
version within the grid). Example Input 10 IPLUCJMCNY AAFIIVADZN TFUUSWGHWE
UBARTAGDOG
YSAJIGIUGR
DTEMRFEOKA
HYTEBKZCHM
BOMAHARBAL
WOOQPUERNE
HEZUYIJHNS
Abraham Bart Homer Lisa Maggie Marge Patty Selma
Output
  L   M
   I  A
    S G  E
 BARTAG  G
Y     I  R
 T  R E  A
  TE     M
  MAHARBAL
 O  P    E
H        S

*/

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<string> split(string str) {
  // Returns first token
  vector<string> ret;
  char* token = strtok(str.data(), " ");

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, " ");
  }

  return ret;
}

std::string toUpperCase(const std::string& str) {
  std::string upperStr = str;

  std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(),
                 [](unsigned char c) { return std::toupper(c); });

  return upperStr;
}

int main() {
  int size;
  vector<string> rows;
  vector<string> backwards;
  cin >> size;
  cin.ignore();
  for (int i = 0; i < size; i++) {
    string row;
    getline(cin, row);
    rows.push_back(row);
    reverse(row.begin(), row.end());
    backwards.push_back(row);
  }

  string clues;
  getline(cin, clues);

  vector<string> cluesspl = split(clues);
  vector<string> cluesUpper;
  for (string s : cluesspl) {
    cluesUpper.push_back(toUpperCase(s));
  }

  vector<vector<bool>> mat(size, vector<bool>(size, false));

  for (int i = 0; i < size; ++i) {
    string s = rows[i];
    string b = backwards[i];
    for (string cl : cluesUpper) {
      int startpos = s.find(cl);
      if (startpos != std::string::npos) {
        for (int x = 0; x < cl.size(); ++x) {
          mat[i][x + startpos] = true;
        }
      }
      startpos = b.find(cl);
      if (startpos != std::string::npos) {
        for (int x = 0; x < cl.size(); ++x) {
          mat[i][size - startpos - x - 1] = true;
        }
      }
    }
  }

  for (int i = 0; i < size; ++i) {
    string cur = "";
    for (int j = 0; j < size; ++j) {
      cur += rows[j][i];
    }
    for (string cl : cluesUpper) {
      string reversed = cur;
      reverse(reversed.begin(), reversed.end());
      int startpos = cur.find(cl);
      if (startpos != std::string::npos) {
        for (int y = 0; y < cl.size(); ++y) {
          mat[y+startpos][i] = true;
        }
      }
      startpos = reversed.find(cl);
      if (startpos != std::string::npos) {
        for (int y = 0; y < cl.size(); ++y) {
          mat[size - startpos - y - 1][i] = true;
        }
      }
    }
  }

  // 0 to size (l->r)
  for (int i = 0; i < size; ++i) {
    int x = i;
    int y = 0;
    string cur = "";
    while (x < size && y < size) {
      cur += rows[y][x];
      x++;
      y++;
    }
    string reversed = cur;
    reverse(reversed.begin(), reversed.end());
    for (string cl : cluesUpper) {
      int startpos = cur.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[offset+startpos][i+offset+startpos] = true;
        }
      }
      startpos = reversed.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[size - startpos - offset-1-i][size-offset-1-startpos] = true;
        }
      }
    }
  }
  for (int i = 1; i < size; ++i) {
    int y = i;
    int x = 0;
    string cur = "";
    while (x < size && y < size) {
      cur += rows[y][x];
      x++;
      y++;
    }
    string reversed = cur;
    reverse(reversed.begin(), reversed.end());

    for (string cl : cluesUpper) {
      int startpos = cur.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[i+offset+startpos][offset+startpos] = true;
        }
      }
      startpos = reversed.find(cl);

      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
 mat[size-1-startpos-offset][size-1-startpos-i-offset] = true;        }
      }
    }
  }

  // r -> l diagonals
  for (int i = size-1; i >= 0; --i) {
    int x = i;
    int y = 0;
    string cur = "";
    while (x >= 0 && y < size) {
      cur += rows[y][x];
      x--;
      y++;
    }
    string reversed = cur;
    reverse(reversed.begin(), reversed.end());
    for (string cl : cluesUpper) {
      int startpos = cur.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[offset+startpos][i-startpos-offset] = true;
        }
      }
      startpos = reversed.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[i - startpos - offset][offset+startpos] = true;
        }
      }
    }
  }
  // t->b (r->l) diagonals
   for (int i = 1; i < size; ++i) {
    int x = size-1;
    int y = i;
    string cur = "";
    while (x >= 0 && y < size) {
      cur += rows[y][x];
      x--;
      y++;
    }
    string reversed = cur;
    reverse(reversed.begin(), reversed.end());
    for (string cl : cluesUpper) {
      int startpos = cur.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[offset+startpos+i][size-1-startpos-offset] = true;
        }
      }
      startpos = reversed.find(cl);
      if (startpos != std::string::npos) {
        for (int offset = 0; offset < cl.size(); ++offset) {
          mat[size -1 - startpos - offset][offset+startpos+i] = true;
        }
      }
    }
  }

  for (int i = 0; i < size; ++i) {
    string cur = "";
    for (int j = 0; j < size; ++j) {
      cur += (mat[i][j]) ? string(1, rows[i][j]) : " ";
    }
    cout << cur << endl;
  }
}

/*

expected:
KOKOD EOTOT   I
   O   B      B
  L     M     M
 LTIUCSIBAESGLA
Y K  A   SRA AB
   EP   U RA S
G  RRS O F  HS
HRI WMM I    I
ELUA YIEOTLABE
D JME LT    M
WA KPDTILIKUMA
IKC  Y        H
GI    C
MA     A
 L      T


mine:
KOKOD EOTOT   I
   O   B      B
  L     M     M
 LTIUCSIBAES LA
Y K  A   SR  AB
   EP   U  A S
G  RRS O    HS
HRI WMM      I
ELUA YI OTLABE
D JME  T    M
WA KP TILIKUMA
IKC  Y        H
GI    C
MA     A
 L      T
*/