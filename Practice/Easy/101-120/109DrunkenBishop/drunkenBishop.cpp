/*

Goal
Have you ever wondered how the OpenSSH Random Art is produced?
They used 'The Drunken Bishop algorithm', designed by Alexander von Gernler.

"Bishop Peter finds himself in the middle of an ambient atrium. There are walls
on all four sides and apparently there is no exit. The floor is paved with
square tiles, strictly alternating between black and white. His head heavily
aching—probably from too much wine he had before—he starts wandering around
randomly. Well, to be exact, he only makes diagonal steps—just like a bishop on
a chess board. When he hits a wall, he moves to the side, which takes him from
the black tiles to the white tiles (or vice versa). And after each move, he
places a coin on the floor, to remember that he has been there before. After 64
steps, just when no coins are left, Peter suddenly wakes up. What a strange
dream!"

The algorithm is well described in the document "The drunken bishop: An analysis
of the OpenSSH fingerprint visualization algorithm" (link in reference). To
summarize, OpenSSH uses MD5 to generate a 128 bits fingerprint for the server's
key, for example in hexadecimal fc:94:b0:c1:e5:b0:98:7c:58:43:99:76:97:ee:9f:b7

You should create a chess board 17x9 (origin 0,0 at top left corner) and place a
Bishop (the letter S) at the center (position 8,4). 1111111 01234567890123456
 +---[CODINGAME]---+ x
0|                 |
1|                 |
2|                 |
3|                 |
4|        S        |
5|                 |
6|                 |
7|                 |
8|                 |
 +-----------------+
 y

Then, break the 128 bit fingerprint in input into pairs of bits that define 4
possible moves: 00: up-left (↖ North West ) 01: up-right (↗ North East) 10:
down-left(↙ South West) 11: down-right (↘ South East) During the 64 steps of the
algorithm, the bit pairs are processed byte-wise, from left to right and least
significant bits first. Example: The fingerprint FC:94 F     C       9     4 ...
     11 11 11 00 : 10 01 01 00 ...
      |  |  |  |    |  |  |  |
Step  4  3  2  1    8  7  6  5

For each pair of bits in the input we move the bishop one space on the board and
increment a counter recording how many times we visit each square. Instead of
moving off the board at the edges, the bishop slides along the sides as if they
were walls. For example, if the bishop is on the right edge of the board and the
next move is 01, we simply slide the bishop one space vertically up,
incrementing the counter on the new square as normal. If the Bishop ends up at a
corner and he cannot slide, he simply does not move (and we should increment
counter for that corner cell). Here the four cases: Position  | bit pair |
action
-------------+----------+--------
top left     |    00    | no move
top right    |    01    | no move
bottom left  |    10    | no move
bottom right |    11    | no move

At the end of the 64 steps, the board is drawn assigning a symbol to each
position on the board according to how many times it was visited. OpenSSH uses
these symbols:

0  1  2  3  4  5  6  7  8  9  10 11 12 13 14
   .  o  +  =  *  B  O  X  @  %  &  #  /  ^

We apply the wrap-around logic if the number of times visited is greater than
14, e.g. we use o if a position is visited for 17 times. The special values S
and the end value E mark the start and end position of the walk and overwrite
the real value of the respective position. Surround the chessboard with + for
corners, - for top and bottom edges and | for left and right edges. Put
[CODINGAME] at center in the top edge.

References:
http://www.dirk-loss.de/sshvis/drunken_bishop.pdf
https://www.jfurness.uk/the-drunken-bishop-algorithm/
https://dev.to/krofdrakula/improving-security-by-drawing-identicons-for-ssh-keys-24mc
Input
Line 1: Server fingerprint string format as group of 2 hexadecimal digit
separated by :. Output 11 lines: Random ASCII Art Constraints The input string
is always 16 bytes (separated by :), so there are exactly 64 steps that can be
produced by the input string. Example Input
fc:94:b0:c1:e5:b0:98:7c:58:43:99:76:97:ee:9f:b7
Output
+---[CODINGAME]---+
|       .=o.  .   |
|     . *+*. o    |
|      =.*..o     |
|       o + ..    |
|        S o.     |
|         o  .    |
|          .  . . |
|              o .|
|               E.|
+-----------------+

*/

#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str) {
  // Returns first token
  vector<string> ret;
  char* token = strtok(str.data(), ":");

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, ":");
  }

  return ret;
}

std::string hexToBit(char hexChar) {
  std::stringstream stream;
  stream << std::hex << hexChar;
  // first convert to uint
  unsigned int hexValue;
  stream >> hexValue;

  // then bitset to convert to binary
  // note, bits function
  std::bitset<4> bits(hexValue);
  return bits.to_string();
}

int binaryToInt(const std::string& binaryString) {
  return std::stoi(binaryString, nullptr,
                   2);  // stoi to convert the binary string to int
}

int main() {
  vector<vector<int>> chessboard(9, vector<int>(17, 0));
  int curx = 8;
  int cury = 4;
  vector<char> visitMap = {' ', '.', 'o', '+', '=', '*', 'B', 'O',
                           'X', '@', '%', '&', '#', '/', '^'};
  string fingerprint;
  getline(cin, fingerprint);
  vector<string> tokens = split(fingerprint);
  vector<int> moves;  // 0 UL, 1 UR, 2 DL, 3 DR
  vector<pair<int, int>> movesmap = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  // 16 hex pairs - 8 bits
  // 4 moves
  // 4*16 = 64 moves.
  for (string s : tokens) {
    string b1 = hexToBit(s[0]);
    string b2 = hexToBit(s[1]);
    moves.push_back(binaryToInt(b2.substr(2, 2)));
    moves.push_back(binaryToInt(b2.substr(0, 2)));
    moves.push_back(binaryToInt(b1.substr(2, 2)));
    moves.push_back(binaryToInt(b1.substr(0, 2)));
    // cout << "move 1 " << move1 << endl;
    // cout << "move 2 " << move2 << endl;
    // cout << "move 3 " << move3 << endl;
    // cout << "move 4 " << move4 << endl;
  }
  for (int move : moves) {
    auto [dy,dx] = movesmap[move];
    curx += dx;
    curx = min(curx, 16);
    curx = max(curx, 0);
    cury += dy;
    cury = min(cury, 8);
    cury = max(cury, 0);
    chessboard[cury][curx]++;
  }
  // cerr << "printing chessboard " << endl;
  // for (auto a: chessboard) {
  //   cerr << endl;
  //   for (int i: a) {
  //     cerr << i;
  //   }
  // }
  // print frame
  cout << "+---[CODINGAME]---+" << endl;
  for (int i = 0; i < chessboard.size(); ++i) {
    vector<int> line = chessboard[i];
    string s = "|";
    for (int j = 0; j < line.size(); ++j) {
      int freq = line[j];
      if (i == 4 && j == 8) {
        s+= "S";
        continue;
      }

      if (i == cury && j == curx) {
        s+= "E";
        continue;
      }

      s+=visitMap[freq%15];
    }
    s+= "|";
    cout << s << endl;
  }


  cout << "+-----------------+" << endl;


}