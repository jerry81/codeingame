/*
The Goal
The aim of this game is to help Blub escape a forest by sending him a sequence
of instructions that will make him spell out a given sentence using magic
stones.

For this question, you will be asked to output a single line as a solution. Your
rank will be evaluated by the length of your output, which you will want to
minimize. Rules Your program receives a string of uppercase characters – the
magic phrase Blub needs to spell out – and must output a sequence of characters,
each representing an action for Blub to perform. These actions will have Blub
move around in the forest, interacting with the different stones.

The forest Blub is trapped works as follows:
The forest contains 30 zones.
Blub can move left and right through the zones which are all aligned. He does
this when he receives a less-than < or greater-than > sign. The last zone is
connected to the first zone, effectively creating a looping area. Each zone
contains a magic stone upon which is inscribed a rune with which Blub can
interact.

Runes work as follows:
Every rune is represented by a letter of the alphabet (A-Z) or an empty space.
All runes start out as a space.
Blub can change the value of the letter on the rune by rolling back and forth
through the possibilities. He does this when he receives a plus + or minus -
character. The letter after Z is space. The letter after space is A. Blub can
trigger a rune. This will add the displayed letter to the phrase he is spelling
out. He does this when he receives a dot . character. One rune can be triggered
several times. You lose if: At the end of Blub's move sequence, the wrong
message is displayed. Blub performs 4000 moves or more in the forest. You do not
supply Blub with a valid sequence of actions.

Victory Conditions
You win if the magic phrase is spelled out correctly at the end of Blub's move
sequence. Expert Rules For expert CodinGamers, we've added the loops! You can
skip this section until you've really tried the rest.

These actions are also available:
[: If the current rune contains a space, skip all instructions up to the
matching closing bracket ], otherwise continue normally.
]: If the current rune contains a space, continue normally, otherwise perform
the instructions starting from the matching opening bracket [. This makes it
possible to have Blub perform more actions with less characters for your program
to output.

For example, AAAAAAAAAAAAAAAAAAAAAAAAAA (A x26) can be achieved with a simple
+.......................... as well as with +>-[<.>-].

Experiment with different techniques, if you have the guts!
        Example
If Blub needs to spell out the word AB, you could give him the instructions
+.+.. He will: Make the first rune go from space to A. Trigger the A. Make rune
go from A to B. Trigger the B. Alternatively, you could also give him the
instructions +.>++. to achieve the same result. Experiment with different
tactics! Note Don’t forget to run the tests by launching them from the “Test
cases” window. You do not have to pass all tests to enter the leaderboard. Each
test you pass will earn you some points (for example 10%).

Warning: the tests provided are similar to the validation tests used to compute
the final score but remain different. This is a “harcoding” prevention
mechanism. Harcoded solutions will not get any points.

Your score is computed from the number of characters you send to Blub and only
if the test case is passed.

Do not hesitate to switch to debug mode () if you get stuck.
        Game Input
The program must first read the initialization data from standard input. Then,
provide to the standard output one line with all of Blub's instructions. Input
Line 1: one string magicPhrase, the message you must help Blub to spell out.

Output
A single line containing a valid sequence of actions for Blub.

Here are the available actions you can send to Blub:
>: Blub moves one zone to the right.
<: Blub moves one zone to the left.
+: Blub rolls the letter on the rune of the zone he is in one letter along the
alphabet.
-: Blub rolls the letter on the rune of the zone he is in one letter back
through the alphabet.
.: Blub triggers the rune to add its letter to the magic phrase.
Constraints
magicPhrase contains between 1 and 500 characters.
magicPhrase is composed of uppercase letters (A-Z) and spaces.
Allotted response time to output is ≤ 2 seconds.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> cache;

struct Rune {
  char cur = ' ';
  char plus() {
    if (cur == ' ') {
      cur = 'A';
      return cur;
    }
    if (cur == 'Z') {
      cur = ' ';
      return cur;
    }

    cur += 1;
    return cur;
  }
  char minus() {
    if (cur == 'A') {
      cur = ' ';
      return cur;
    }

    if (cur == ' ') {
      cur = 'Z';
      return cur;
    }

    cur -= 1;
    return cur;
  }
};

vector<Rune> zones(30);
int curRune = 0;

int forwardDistance(char cur, char target) {
  if (cur == ' ') {
    cur += 59;
  }

  if (target == ' ') {
    target += 59;
  }

  if (cur <= target) return target - cur;

  return 27 - (cur - target);
}

int backwardsDistance(char cur, char target) {
  if (cur == ' ') {
    cur += 59;
  }

  if (target == ' ') {
    target += 59;
  }

  if (cur >= target) return cur - target;

  return 27 - (target - cur);
}

string getNextSection(int forwardDist, int backwardsDist) {
  string brainFork = "";
  if (forwardDist <= backwardsDist) { /* extract*/
    for (int i = 0; i < forwardDist; ++i) {
      brainFork += "+";
      zones[curRune].plus();
    }
  } else {
    for (int i = 0; i < backwardsDist; ++i) {
      brainFork += "-";
      zones[curRune].minus();
    }
  }
  return brainFork;
}

int main() {
  // space - 32, A - 65, Z - 90

  cache[' '] = -1;
  for (char c = 'A'; c <= 'Z'; ++c) {
    cache[c] = -1;
  }

  string magic_phrase;
  getline(cin, magic_phrase);
  string brainFork = "";
  for (char c : magic_phrase) {
    char current = zones[curRune].cur;
    if (current == c) {
      brainFork += '.';
      continue;
    }

    if (cache[c] >= 0) {
          if (c == ' ')  cerr << "cache space is " << cache[' '] << endl;

      if (cache[c] > curRune) {
        while (curRune != cache[c]) {
          curRune++;
          brainFork += '>';
        }
      } else {
        while (curRune != cache[c]) {
          curRune--;
          brainFork += '<';
        }
      }
      brainFork += '.';
      continue;
    }
    int forwardFromSpace = forwardDistance(' ', c);
    int backwardsFromSpace = backwardsDistance(' ', c);
    int fromSpace = min(forwardFromSpace, backwardsFromSpace);
    while (zones[curRune].cur != ' ') {
      curRune++;
      brainFork += '>';
    }
    brainFork += getNextSection(forwardFromSpace, backwardsFromSpace);
    if (c != ' ' && cache[c] < 0) cache[c] = curRune;

    brainFork += ".";
  }
  cout << brainFork << endl;
}

/*

26 chars + 1 space with wraparound

30 runes with wraparound

characters used: 11489

6.5k characters is the goal

- idea 1 - compare - steps to go from space or from current rune

characters used in this: 9953

Try again - this time, for sake of simplicity

- if letter has been stored, go to that letter.
- if not, then create the letter in the next available space.

characters used: 9536

*/