/*

	Goal
n opponents, all standing in a circle around you (clockwise from player 0 to n-1), have challenged you to games of "Rock, Paper, Scissors" at the same time. So confident are these players, that they have all shown their moves, and are waiting for you to respond.

You have to win as many of the games as you can, by playing a single move (either Rock, Paper, or Scissors) against an opponent of your choice (player 0 to n-1), then playing the same move against the next player clockwise, and proceeding round the group until you lose a round, or you've played everybody.

- You may start with any opponent, but you must win the first game.
- After the first win, play the same move against each following opponent in the circle, until you lose a game, or until you have played every opponent.
- A draw does not count as a win, or as a loss.
- If there is more than one possible play with the maximum number of wins, the play starting from the lower-numbered opponent takes priority.

For anyone who never played the game:
Rock beats Scissors
Scissors beats Paper
Paper beats Rock
https://en.wikipedia.org/wiki/Rock_paper_scissors

EXAMPLE
6
Scissors
Paper
Rock
Paper
Scissors
Rock

The players surround you, and declare their moves:

    0=S
5=R     1=P
    YOU
4=S     2=R
    3=P

Starting at 0, you play Rock - you win 1 before losing to Paper
Starting at 1, you play Scissors - you win 1 before losing to Rock
Starting at 2, you play Paper - you win 1 and draw 1 before losing to Scissors
Starting at 3, you play Scissors - you win 1 and draw 1 before losing to Rock
Starting at 4, you play Rock - you win 1, draw 1, win 1 before losing to Paper
Starting at 5, you play Paper - you win 1 before losing to Scissors

Solution:
Rock
4
Input
First line: integer n, the number of opponents
Next n lines: string a, representing each player's move (starting with player 0, and proceeding clockwise around you)
Output
The move that maximises the number of games you win:
First line: Your move b
Second line: Integer p, the 0-indexed position of your starting opponent
Constraints
1 <= n <= 10
a and b may be Rock, Paper, or Scissors
Example
Input
4
Paper
Paper
Paper
Rock
Output
Scissors
0

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int play(string p1, string p2) {
  if (p1 == p2) return 0;

  if (p1 == "Rock" && p2 == "Scissors") return 1;

  if (p1 == "Scissors" && p2 == "Paper") return 1;

  if (p1 == "Paper" && p2 == "Rock") return 1;

  return -1;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<string> moves(n, "");
    for (int i = 0; i < n; i++) {
        string a;
        getline(cin, a);
        moves[i] = a;
    }

    int maxWins = 0;
    int maxIdx = 0;
    string maxMove = "Rock";
    vector<string> possibilities = {"Rock", "Paper", "Scissors"};
    for (int i = 0; i < n; ++i) {
      for (string move: possibilities) {
        int cur = i;
        int curcount = 0;
        int opponentsFaced = 0;
        while (opponentsFaced < n) {
          opponentsFaced++;
          int res = play(move,moves[cur]);
          if (opponentsFaced == 1 && res < 1) break;

          if (res < 0) break;
          if (res > 0) {
            curcount++;
            if (curcount > maxWins) {
              maxWins = curcount;
              maxIdx = i;
              maxMove = move;
            }
          }

          cur++;
          cur%=n;
        }
      }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << maxMove << endl;
    cout << maxIdx << endl;
}