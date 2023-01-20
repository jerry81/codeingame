/*

Summary of the new rules:

Creatures now have special abilities.
        The Goal
Draft a deck of cards, battle an opponent with those cards and reduce their
Health Points (HP) from 30 to 0. Rules This game is a two-player card game which
is played in two phases: the Draft phase and the Battle phase. During the Draft
phase, both players must create a deck of 30 cards. Once the Draft phase is
over, both decks are shuffled. During the Battle, the board is divided in two
parts: each player plays cards from their hand on their side of the board. Each
player starts with 30 HP. Some cards can increase this number. To reduce the
health points of an opponent, the player must make use of cards to deal damage.
        Draft Phase
For 30 turns, both players are given a choice between 3 different cards. Players
select the card they want to add to their deck by using the PICK command
followed by 0, 1 or 2. By default, the PASS command will pick the first card.
Both players can select the same card, they will each receive a copy.
        Battle Phase
Card Draw
First player starts with 4 cards in hand whereas the second player starts
with 5. Each turn, the active player draws one additional card from their deck.
Some cards can make players draw additional cards at the beginning of the next
turn when played. Both players possess runes which have an impact on card draw.
However, runes should be ignored until the Bronze league.

Mana
Mana is necessary to play cards from the hand.
The first player starts with 1 max mana, the second with 2 max mana.
Each player can spend as much mana per turn as they have max mana.
The second player receives his +1 max mana bonus until he spends all his mana
during a turn. Each turn, the active player is granted one additional max mana,
unless they already have 12 max mana (13 for the second player who didn't spend
his bonus). Card TypesIn this league, there is only one type of card: Creatures.

Creatures
Placing a creature card from the hand to the board is called summoning.
A player summons creatures to their side of the board by paying their cost in
mana. They are used to attack the opponent and also serve as a defense against
the creatures of the opposing player. Creatures have a cost in mana, attack
points and defense points. Some creatures start with certain abilities. By
default, creatures can't attack the turn they are summoned. They can attack once
per turn only. When a creature attacks another one, they both deal damage equals
to their attack to the defense of the other creature. When a creature attacks
the opponent, it deals damage equals to its attack to the HP of the opponent.
Creatures are removed from play when their defense reaches 0 or less.
Creatures can have an effect on the player's health, the opponent's health or
the card draw of the player when played. Creatures can have different abilities:
Breakthrough: Creatures with Breakthrough can deal extra damage to the opponent
when they attack enemy creatures. If their attack damage is greater than the
defending creature's defense, the excess damage is dealt to the opponent.
Charge: Creatures with Charge can attack the turn they are summoned.
Guard: Enemy creatures must attack creatures with Guard first.
        Gameplay
Possible Actions
SUMMON id to summon the creature id from your hand.
ATTACK id1 id2 to attack creature id2 with creature id1.
ATTACK id -1 to attack the opponent directly with creature id.
PASS to do nothing this turn.
A player can do any number of valid actions during one turn. Actions must be
separated by a semi-colon ;.

Game End
The game is over once any player reaches 0 or less HP.
Victory Conditions
Reduce your opponent Health Points (HP) from 30 to 0 or less.
Loss Conditions
Your HP gets reduced to 0 or less.
You do not respond in time or output an unrecognized command.

        Advanced Details
Advanced details will be available in the Bronze league, as well as the game's
source code for reference.

        Game Input
Input for one game turn
First 2 lines: for each player, playerHealth, playerMana, playerDeck and
playerRune: Integer playerHealth: the remaining HP of the player. Integer
playerMana: the current maximum mana of the player. Integer playerDeck: the
number of cards in the player's deck. During the Draft phase, the second player
has less card in his deck than his opponent. Integer playerRune: to be ignored
in this league Integer playerDraw: the additional number of drawn cards - this
turn draw for the player, next turn draw (without broken runes) for the
opponent. The player's input comes first, the opponent's input comes second.

During the Draft phase, playerMana is always 0.

Next line:
Integer opponentHand, the total number of cards in the opponent's hand. These
cards are hidden until they're played. Integer opponentActions, the number of
actions performed by the opponent during his last turn. Next opponentActions
lines: for each opponent's action, string cardNumberAndAction containing the
cardNumber of the played card, followed by a space, followed by the action
associated with this card (see Possible Actions section).

Next line: Integer cardCount: during the Battle phase, the total number of cards
on the board and in the player's hand. During the Draft phase, always 3.

Next cardCount lines: for each card, cardNumber, instanceId, location, cardType,
cost, attack, defense, abilities, myhealthChange, opponentHealthChange and
cardDraw: Integer cardNumber: the identifier of a card (see complete list).
Integer instanceId: the identifier representing the instance of the card (there
can be multiple instances of the same card in a game). Integer location, during
the Battle phase: 0: in the player's hand 1: on the player's side of the board
-1: on the opponent's side of the board
Always 0 during the Draft phase.
Integer cardType: always 0 for this league.
Integer cost: the mana cost of the card,
Integer attack: the attack points of the creature.
Integer defense: the defense points of the creature.
String abilities of size 6: the abilities of a card. Each letter representing an
ability (B for Breakthrough, C for Charge and G for Guard). Integer
myHealthChange: the health change for the player. Integer opponentHealthChange:
the health change for the opponent. Integer cardDraw: the additional number of
cards drawn next turn for the player. Output for one game turn of the Draft PICK
nb where nb equals 0, 1 or 2 to choose one of the three proposed cards to add to
your deck. PASS to do nothing (picks the 1st card by default). Output for one
game turn of the Card Battle The available actions are: SUMMON id to summon the
creature of instanceId id from the player's hand. ATTACK idAttacker idTarget to
attack an opposing creature or opposing player of instanceId idTarget with a
creature on the board of instanceId idAttacker. idTarget can be the
"no-creature" identifier -1. It is used to attack the opponent directly. PASS to
do nothing. Players may use several actions by using a semi-colon ;. Players may
append text to each of their actions, it will be displayed in the viewer.

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

In Wood 1, players can draft and play another type of cards: Items.
In Bronze, more abilities for creatures!

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct GameMove {
  int type;  // 0 SUMMON, 1 ATTACK, 2 PICK, 3 USE, other PASS
  int id;
  int id2;
  GameMove(int i1 = -1, int i2 = -1, int m = 2) : id(i1), id2(i2), type(m){};
  string stringify() {
    switch (type) {
      case 0:
        return "SUMMON " + std::to_string(id);
      case 1:
        return "ATTACK " + std::to_string(id) + " " + std::to_string(id2);
      case 2:
        return "PICK " + std::to_string(id);
      case 3:
        return "USE " + std::to_string(id) + " " + std::to_string(id2);
      default:
        return "PASS";
    }
  }
};

struct GameMoves {
  vector<GameMove> moves;
  bool draft = false;
  void add(GameMove gm) { moves.push_back(gm); }
  string stringify() {
    string ret = "";
    for (GameMove gm : moves) {
      ret += gm.stringify();
      if (!draft) ret += ";";
    }
    if (!draft) ret += "PASS";

    return ret;
  }
  void setDraft(bool d) { draft = d; }
};

struct Card {
  int id;
  int instance_id;
  int location;  // 0 player hand / draft, 1 player side, 2 opponent side
  int cost;
  int attack;
  int defense;
  int kind;  // 0 creature, 1 green, 2 red, 3 blue
  // C Charge B Breakthru G Guard
  string abilities;
  Card(int i = -1, int ii = -1, int loc = -1, int c = -1, int a = -1,
       int d = -1, string ab = "", int card_type = 0)
      : id(i),
        instance_id(ii),
        location(loc),
        cost(c),
        attack(a),
        defense(d),
        abilities(ab),
        kind(card_type){};
  void print() {
    cerr << "id " << id << " attack " << attack << " defense " << defense
         << " kind " << kind << endl;
  }
  string hash() {
    return std::to_string(id) + "," + std::to_string(instance_id);
  }
  int totalStrength() { return attack + defense; }

  int costEffectiveness() { return totalStrength() - cost; }

  bool hasGuard() { return hasX("G"); }

  bool hasX(string a) { return abilities.find(a) != std::string::npos; }

  bool hasCharge() { return hasX("C"); }

  bool hasBreak() { return hasX("B"); }

  bool isCreature() { return kind == 0; }

  bool undefined() {
    return id==-1;
  }
};

struct CardMap {
  unordered_map<string, Card> lookup;
  void addCard(Card c) {
    if (lookup.find(c.hash()) == lookup.end()) {
      lookup[c.hash()] = c;
    }
  }
  void merge(CardMap toMerge) {
    for (auto item : toMerge.lookup) {
      addCard(item.second);
    }
  }

  void clear() { lookup.clear(); }

  bool contains(Card p) { return (lookup.find(p.hash()) != lookup.end()); }

  void print() {
    for (auto a : lookup) {
      cerr << "map item " << endl;
      a.second.print();
    }
  }

  Card first() {
    return lookup.begin()->second;
  }

  Card firstGuard() {
    for (auto a: lookup) {
      Card temp = a.second;
      if (temp.hasGuard()) {
        return temp;
      }
    }
    Card undefinedCard;
    return undefinedCard;
  }

  Card firstNonGuard() {
    for (auto a: lookup) {
      Card temp = a.second;
      if (!temp.hasGuard()) {
        return temp;
      }
    }
    Card undefinedCard;
    return undefinedCard;
  }
};

struct Player {
  int health;
  int mana;
  bool me;
  int deck_size;
  Player(int h = 0, int m = 0, int d = 0, bool me = false)
      : health(h), mana(m), deck_size(d), me(me){};
  void print() {
    cerr << "my health " << health << " mana " << mana << " deck size "
         << deck_size << endl;
  };
};

class Game {
  Player me;
  vector<Card> drafting;
  CardMap creatures_hand;
  CardMap items_hand;
  CardMap soldiers;
  CardMap enemyGuards;
  CardMap otherEnemy;

 public:
  void reset() {
    drafting.clear();
    creatures_hand.clear();
    items_hand.clear();
    soldiers.clear();
    enemyGuards.clear();
    otherEnemy.clear();
  }
  void addOtherEnemy(Card c) { otherEnemy.addCard(c); }
  void addEnemyGuard(Card c) { enemyGuards.addCard(c); }
  void addDraft(Card c) { drafting.push_back(c); }
  void setMe(int h, int m, int d) { me = Player(h, m, d, true); };
  bool draft() { return me.mana == 0; };
  void print() {
    cerr << "me" << endl;
    me.print();
    string phase = (draft() ? "draft" : "battle");
    cerr << "phase: " << phase << endl;
  };

  int pickCard() {
    int maxVal = 0;
    int maxIdx = 0;
    for (int i = 0; i < 3; ++i) {
      Card c = drafting[i];
      if (c.isCreature()) {
        int val = c.costEffectiveness();
        if (c.hasGuard()) val += 2;
        if (val > maxVal) {
          maxVal = val;
          maxIdx = i;
        }
      } else if (!c.hasBreak() && !c.hasCharge()) {
        return i;  // take items first?
      }
    }
    return maxIdx;
  };

  GameMoves battle() {
    GameMoves res;
    Card c = getLowestCard();
    if (me.mana >= c.cost) {
      GameMove gm;
      gm.type = 0;
      gm.id = c.instance_id;
      res.add(gm);
    }

    for (auto a : soldiers.lookup) {
      Card c = a.second;
      GameMove gm;
      gm.type = 1;
      gm.id = c.instance_id;
      if (enemyGuards.lookup.empty()) {
        gm.id2 = -1;
      } else {
        for (auto a : enemyGuards.lookup) {
          gm.id2 = a.second.instance_id;
          break;
        }
      }

      res.add(gm);
    }

    cerr << "res len is now " << res.moves.size() << endl;

    for (auto a : items_hand.lookup) {
      Card c = a.second;
      if (me.mana >= c.cost) {
        GameMove gm;
        gm.type = 3;
        gm.id = c.instance_id;
        cerr << "c type is " << c.kind << endl;
        switch (c.kind) {
          case 1: {  // green
            if (!soldiers.lookup.empty()) {
              auto a = soldiers.lookup.begin();  // TODO: strategy
              gm.id2 = a->second.instance_id;
              res.add(gm);
            }
            break;
          }
          case 2: {  // red
            // guards first, then others
            if (!enemyGuards.lookup.empty()) {
              gm.id2 = enemyGuards.lookup.begin()->second.instance_id;
              res.add(gm);
            } else if (!otherEnemy.lookup.empty()) {
              gm.id2 = otherEnemy.lookup.begin()->second.instance_id;
              res.add(gm);
            }
            break;
          }
          default: {
            res.add(gm);
            break;
          }
        }
      }
    }

    cerr << "res len (after) is now " << res.moves.size() << endl;

    return res;
  }

  void addCardToHand(Card c) {
    if (c.kind == 0) {
      creatures_hand.addCard(c);
    } else {
      items_hand.addCard(c);
    }
  }

  void addCardToField(Card c) { soldiers.addCard(c); }

  Card getHighestCard() {
    Card highest;
    int highestStr = 0;
    for (auto a : creatures_hand.lookup) {
      Card c = a.second;
      if (c.cost > highestStr) {
        highest = c;
        highestStr = highest.cost;
      }
    }
    return highest;
  }

  Card getLowestCard() {
    Card lowest;
    int lowestStr = 10000;
    for (auto a : creatures_hand.lookup) {
      Card c = a.second;
      if (c.cost < lowestStr) {
        lowest = c;
        lowestStr = c.cost;
      }
    }
    return lowest;
  }
};

Game g;

int main() {
  // game loop
  while (1) {
    g.reset();
    for (int i = 0; i < 2; i++) {
      int player_health;
      int player_mana;
      int player_deck;
      int player_rune;
      int player_draw;
      cin >> player_health >> player_mana >> player_deck >> player_rune >>
          player_draw;
      cin.ignore();
      if (i == 0) {
        g.setMe(player_health, player_mana, player_deck);
      }
    }
    int opponent_hand;
    int opponent_actions;
    cin >> opponent_hand >> opponent_actions;
    cin.ignore();
    for (int i = 0; i < opponent_actions; i++) {
      string card_number_and_action;
      getline(cin, card_number_and_action);
    }
    int card_count;
    cin >> card_count;
    cin.ignore();

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
      cin >> card_number >> instance_id >> location >> card_type >> cost >>
          attack >> defense >> abilities >> my_health_change >>
          opponent_health_change >> card_draw;
      cin.ignore();
      Card c = Card(card_number, instance_id, location, cost, attack, defense,
                    abilities, card_type);
      if (g.draft()) {
        g.addDraft(c);
      } else if (c.location == 0) {
        g.addCardToHand(c);
      } else if (c.location == 1) {
        g.addCardToField(c);
      } else {  // enemy
        if (c.hasGuard()) {
          g.addEnemyGuard(c);
        } else {
          g.addOtherEnemy(c);
        }
      }
    }

    int choice = g.pickCard();
    GameMoves gms;
    if (g.draft()) {
      GameMove gm;
      gm.id = choice;
      gm.type = 2;
      gms.add(gm);
      gms.setDraft(true);
    } else {
      gms = g.battle();
    }

    cout << gms.stringify() << endl;
  }
}

/*

multiple actions per turn
*/