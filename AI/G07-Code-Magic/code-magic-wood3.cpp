/*


This is a league based challenge.

Wood leagues should be considered as a tutorial which lets players discover the different rules of the game.
In Bronze league, all rules will be unlocked and the real challenge will begin.
 	The Goal
Draft a deck of cards, battle an opponent with those cards and reduce their Health Points (HP) from 30 to 0.
 	Rules
This game is a two-player card game which is played in two phases: the Draft phase and the Battle phase.
During the Draft phase, both players must create a deck of 30 cards.
Once the Draft phase is over, both decks are shuffled.
During the Battle, the board is divided in two parts: each player plays cards from their hand on their side of the board.
To reduce the health points of an opponent, the player must make use of cards to deal damage.
 	Draft Phase
For 30 turns, both players are given a choice between 3 different cards. Players select the card they want to add to their deck by using the PICK command followed by 0, 1 or 2.
By default, the PASS command will pick the first card.
Both players can select the same card, they will each receive a copy.
 	Battle Phase
Card Draw
First player starts with 4 cards in hand whereas the second player starts with 5.
Each turn, the active player draws one additional card from their deck.
Both players possess runes which have an impact on card draw. However, runes should be ignored until the Bronze league.

Mana
Mana is necessary to play cards from the hand.
The first player starts with 1 max mana, the second with 2 max mana.
Each player can spend as much mana per turn as they have max mana.
The second player receives his +1 max mana bonus until he spends all his mana during a turn.
Each turn, the active player is granted one additional max mana, unless they already have 12 max mana (13 for the second player who didn't spend his bonus).
 	Card TypesIn this league, there is only one type of card: Creatures.

Creatures
Placing a creature card from the hand to the board is called summoning.
A player summons creatures to their side of the board by paying their cost in mana. They are used to attack the opponent and also serve as a defense against the creatures of the opposing player.
Creatures have a cost in mana, attack points and defense points.
By default, creatures can't attack the turn they are summoned. They can attack once per turn only.
When a creature attacks another one, they both deal damage equals to their attack to the defense of the other creature. When a creature attacks the opponent, it deals damage equals to its attack to the HP of the opponent.
Creatures are removed from play when their defense reaches 0 or less.
 	Gameplay
Possible Actions
SUMMON id to summon the creature id from your hand.
ATTACK id1 id2 to attack creature id2 with creature id1.
ATTACK id -1 to attack the opponent directly with creature id.
PASS to do nothing this turn.
A player can do any number of valid actions during one turn. Actions must be separated by a semi-colon ;.

Game End
The game is over once any player reaches 0 or less HP.
Victory Conditions
Reduce your opponent Health Points (HP) from 30 to 0 or less.
Loss Conditions
Your HP gets reduced to 0 or less.
You do not respond in time or output an unrecognized command.

 	Advanced Details
Advanced details will be available in the Bronze league, as well as the game's source code for reference.

 	Game Input
Input for one game turn
First 2 lines: for each player, playerHealth, playerMana, playerDeck and playerRune:
Integer playerHealth: the remaining HP of the player.
Integer playerMana: the current maximum mana of the player.
Integer playerDeck: the number of cards in the player's deck. During the Draft phase, the second player has less card in his deck than his opponent.
Integer playerRune: to be ignored in this league
Integer playerDraw: to be ignored in this league.
The player's input comes first, the opponent's input comes second.

During the Draft phase, playerMana is always 0.

Next line:
Integer opponentHand, the total number of cards in the opponent's hand. These cards are hidden until they're played.
Integer opponentActions, the number of actions performed by the opponent during his last turn.
Next opponentActions lines: for each opponent's action, string cardNumberAndAction containing the cardNumber of the played card, followed by a space, followed by the action associated with this card (see Possible Actions section).

Next line: Integer cardCount: during the Battle phase, the total number of cards on the board and in the player's hand. During the Draft phase, always 3.

Next cardCount lines: for each card, cardNumber, instanceId, location, cardType, cost, attack, defense, abilities, myhealthChange, opponentHealthChange and cardDraw:
Integer cardNumber: the identifier of a card (see complete list).
Integer instanceId: the identifier representing the instance of the card (there can be multiple instances of the same card in a game).
Integer location, during the Battle phase:
0: in the player's hand
1: on the player's side of the board
-1: on the opponent's side of the board
Always 0 during the Draft phase.
Integer cardType: always 0 for this league.
Integer cost: the mana cost of the card,
Integer attack: the attack points of the creature.
Integer defense: the defense points of the creature.
String abilities of size 6: to be ignored in this league
Integer myHealthChange: to be ignored in this league.
Integer opponentHealthChange: to be ignored in this league.
Integer cardDraw: to be ignored in this league.
Output for one game turn of the Draft
PICK nb where nb equals 0, 1 or 2 to choose one of the three proposed cards to add to your deck.
PASS to do nothing (picks the 1st card by default).
Output for one game turn of the Card Battle
The available actions are:
SUMMON id to summon the creature of instanceId id from the player's hand.
ATTACK idAttacker idTarget to attack an opposing creature or opposing player of instanceId idTarget with a creature on the board of instanceId idAttacker.
idTarget can be the "no-creature" identifier -1. It is used to attack the opponent directly.
PASS to do nothing.
Players may use several actions by using a semi-colon ;.
Players may append text to each of their actions, it will be displayed in the viewer.

Example: SUMMON 3;ATTACK 4 5 yolo; ATTACK 8 -1 no fear.
Constraints
0 ≤ cost ≤ 12
0 ≤ creatures on one side of the board ≤ 6
0 ≤ cards in hand ≤ 8

Response time for the first draft turn ≤ 1000ms
Response time for the first battle turn ≤ 1000ms
Response time per turn ≤ 100ms

What is in store in the higher leagues?

The extra rules available in higher leagues are:

In Wood 2, creatures can have abilities.
In Wood 1, players can draft and play another type of cards: Items.
In Bronze, more abilities for creatures!

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct GameMove {
  int type; // 0 SUMMON, 1 ATTACK, 2 PICK, other PASS
  int id;
  int id2;
  GameMove(int i1 = -1,int i2=-1, int m=2): id(i1), id2(i2), type(m){};
  string stringify() {
    switch (type) {
      case 0:
        return "SUMMON " + std::to_string(id);
      case 1:
        return "ATTACK " + std::to_string(id) + " " + std::to_string(id2);
      case 2:
        return "PICK " + std::to_string(id);
      default:
        return "PASS";
    }
  }
};

class Card {
  int id;
  int instance_id;
  int location; // 0 player hand / draft, 1 player side, 2 opponent side
  int cost;
  int attack;
  int defense;
  Card(int i, int ii, int loc, int c, int a, int d):id(i), instance_id(ii), location(loc), cost(c), attack(a), defense(d){};
};

class Player {
  int health;
  int mana;
  bool me;
  int deck_size;
  Player(int h, int m, int d, bool me = false) : health(h), mana(m), deck_size(d), me(me) {};
};

int main()
{

    // game loop
    while (1) {
        for (int i = 0; i < 2; i++) {
            int player_health;
            int player_mana;
            int player_deck;
            int player_rune;
            int player_draw;
            cin >> player_health >> player_mana >> player_deck >> player_rune >> player_draw; cin.ignore();
        }
        int opponent_hand;
        int opponent_actions;
        cin >> opponent_hand >> opponent_actions; cin.ignore();
        for (int i = 0; i < opponent_actions; i++) {
            string card_number_and_action;
            getline(cin, card_number_and_action);
        }
        int card_count;
        cin >> card_count; cin.ignore();
        for (int i = 0; i < card_count; i++) {
            int card_number;
            int instance_id;
            int location;
            int card_type;
            int cost;
            int attack;
            int defense;
            string abilities;
            int my_health_change;
            int opponent_health_change;
            int card_draw;
            cin >> card_number >> instance_id >> location >> card_type >> cost >> attack >> defense >> abilities >> my_health_change >> opponent_health_change >> card_draw; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "PASS" << endl;
    }
}