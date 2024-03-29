/*
        Goal
You are playing blackjack against the bank, but they no longer know the rules!
Help her find who is the winner. To win at Blackjack, your hand must be stronger
than the banker's while not exceeding 21 (inclusive). If a hand exceeds 21
points, the opposing hand wins. If both exceeds 21, the bank win.

To calculate the value of a hand, we add the values ​​of the cards as
follows:
- From 2 to 9: each card has its own face value.
- The 10, J (Jacks), Q (Queens) and K (Kings) are worth 10.
- The A (Aces) are equivalent to 1 or 11 depending on the hand-holder's
advantage. If the hand does not exceed 21, the A counts 11. If, on the contrary,
it exceeds it, the A counts as 1; Example: if the hand is A A, the hand-holder
will have 12 points (11+1), because 11+11=22>21 which is not to the advantage of
the owner of the hand.
- The hand called "Blackjack" is composed of an A and a card worth 10, for a
total of 21, received from the start (with no other card therefore).

Entries are not listed in the order the cards were dealt (the order does not
matter) Example: A J 2 is not a blackjack, even if there is A and J, because
there is a third card.

If your hand is stronger: return Player
If your hand is weaker or bank has blackjack and not you: return Bank
If there is a tie: return Draw
If you have Blackjack and the bank has none: return Blackjack!
Input
Line 1 : bank_cards, bank cards (separated by a space)
Line 2 : player_cards, the player's cards (separated by a space)
Output
Player, Bank, Draw, Blackjack! depending on the situation
Constraints
Example
Input
8 2 2
7 6
Output
Player
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
  string bank_cards;
  getline(cin, bank_cards);
  string player_cards;
  getline(cin, player_cards);

  // step 1: split
  stringstream ss(bank_cards);
  string b_card;
  int b_ace = 0;
  int b_sum = 0;
  int b_count = 0;
  while (getline(ss, b_card, ' ')) {
    ++b_count;
    cerr << "bank card is " << b_card << endl;
    if (b_card.length() == 1) {
      if (isdigit(b_card[0])) {
        b_sum += (b_card[0] - '0');
      } else {
      if (b_card[0] == 'A') {
          b_ace += 1;
        } else {
        // J Q K
          b_sum += 10;
        }
      }
    } else {
      b_sum += 10;
    }
  }
  cerr << "bank total is " << b_sum << endl;

  stringstream ss2(player_cards);
  string p_card;
  int p_ace = 0;
  int p_sum = 0;
  int p_count = 0;
  while (getline(ss2, p_card, ' ')) {
    ++p_count;
    cerr << "player card is " << p_card << endl;
    cerr << "length is " << p_card.length() << endl;
    if (p_card.length() == 1) {
      if (isdigit(p_card[0])) {
        p_sum += (p_card[0] - '0');
      } else {
        // A
        if (p_card[0] == 'A') {
          p_ace += 1;
        } else {
        // J Q K
          p_sum += 10;
        }
      }
    } else {
      p_sum += 10;
    }
  }

  cerr << "player total is " << p_sum << endl;
  // optimize aces
  while (b_ace > 0) {
    --b_ace;
    if (b_sum + b_ace + 11 <= 21) {
      b_sum += 11;
    } else {
      b_sum += 1;
    }
  }

  while (p_ace > 0) {
    --p_ace;
    if (p_sum + p_ace + 11 <= 21) {
      p_sum += 11;
    } else {
      p_sum += 1;
    }
  }
  bool player_blackjack = p_sum == 21 && p_count == 2;
  bool bank_blackjack = b_sum == 21 && b_count == 2;
  if (player_blackjack && !bank_blackjack) {
    cout << "Blackjack!" << endl;
  } else if (player_blackjack && bank_blackjack) {
    cout << "Draw" << endl;
  } else if (p_sum <= 21 && p_sum > b_sum) {
    cout << "Player" << endl;
  } else if (p_sum > 21) {
    // bust
      cout << "Bank" << endl;
  } else if (b_sum > 21) {
    if (p_sum > 21) {
      cout << "Draw" << endl;
    } else {
      cout << "Player" << endl;
    }
  } else if (b_sum <= 21 && b_sum > p_sum) {
    cout << "Bank" << endl;
  } else {
    cout << "Draw" << endl;
  }
}