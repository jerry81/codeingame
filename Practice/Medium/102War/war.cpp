/*

The Goal
Let's go back to basics with this simple card game: war!

Your goal is to write a program which finds out which player is the winner for a given card distribution of the "war" game.
 	Rules
War is a card game played between two players. Each player gets a variable number of cards of the beginning of the game: that's the player's deck. Cards are placed face down on top of each deck.

Step 1 : the fight
At each game round, in unison, each player reveals the top card of their deck – this is a "battle" – and the player with the higher card takes both the cards played and moves them to the bottom of their stack. The cards are ordered by value as follows, from weakest to strongest:
2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A.

Step 2 : war
If the two cards played are of equal value, then there is a "war". First, both players place the three next cards of their pile face down. Then they go back to step 1 to decide who is going to win the war (several "wars" can be chained). As soon as a player wins a "war", the winner adds all the cards from the "war" to their deck.

Special cases:
If a player runs out of cards during a "war" (when giving up the three cards or when doing the battle), then the game ends and both players are placed equally first.
The test cases provided in this puzzle are built in such a way that a game always ends (you do not have to deal with infinite games)
Each card is represented by its value followed by its suit: D, H, C, S. For example: 4H, 8C, AS.

When a player wins a battle, they put back the cards at the bottom of their deck in a precise order. First the cards from the first player, then the one from the second player (for a "war", all the cards from the first player then all the cards from the second player).

For example, if the card distribution is the following:
Player 1 : 10D 9S 8D KH 7D 5H 6S
Player 2 : 10H 7H 5C QC 2C 4H 6D
Then after one game turn, it will be:
Player 1 : 5H 6S 10D 9S 8D KH 7D 10H 7H 5C QC 2C
Player 2 : 4H 6D

Victory Conditions
A player wins when the other player no longer has cards in their deck.
 	Game Input
Input
Line 1: the number N of cards for player one.

N next lines: the cards of player one.

Next line: the number M of cards for player two.

M next lines: the cards of player two.

Output
If players are equally first: PAT
Otherwise, the player number (1 or 2) followed by the number of game rounds separated by a space character. A war or a succession of wars count as one game round.
Constraints
0 < N, M < 1000
Example
Input
3
AD
KC
QC
3
KH
QS
JC
Output
1 3

*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int processCard(string card) {
  if (card.size() == 3) {
    return 10;
  }

  char first_char = card[0];
  switch (first_char) {
    case 'A':
      return 14;
    case 'K':
      return 13;
    case 'Q':
      return 12;
    case 'J':
      return 11;
    default:
      return first_char - '0';
  }
}

int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    queue<int> p1;
    queue<int> p2;
    for (int i = 0; i < n; i++) {
        string cardp_1; // the n cards of player 1
        cin >> cardp_1; cin.ignore();
        int processed = processCard(cardp_1);
        p1.push(processed);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp_2; // the m cards of player 2
        cin >> cardp_2; cin.ignore();
        int processed = processCard(cardp_2);
        p2.push(processed);
    }

    int rounds = 0;

    while (p1.size() > 0 && p2.size() > 0) {
      rounds = rounds+1;
      // pop
      queue<int> winstack1;
      queue<int> winstack2;
      int c1 = p1.front();
      p1.pop();
      int c2 = p2.front();
      p2.pop();
      winstack1.push(c1);
      winstack2.push(c2);
      if (c1 > c2) {
        while (winstack1.size() > 0) {
          p1.push(winstack1.front());
          winstack1.pop();
        }
        while (winstack2.size() > 0) {
          p1.push(winstack2.front());
          winstack2.pop();
        }
        continue;
      } else if (c1 < c2) {
        while (winstack1.size() > 0) {
          p1.push(winstack1.front());
          winstack1.pop();
        }
        while (winstack2.size() > 0) {
          p1.push(winstack2.front());
          winstack2.pop();
        }
        continue;
      }
    }

    int winner = (p1.size() == 0) ? 2 : 1;

    cout << winner << " " << rounds << endl;
}