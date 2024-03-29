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
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

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

struct Register {
  vector<Rune> zones;
  int curRune = 0;
  unordered_map<char, set<int>> cache;
  Register() {
    zones.resize(30);
    for (int i = 0; i < 30; ++i) {
      cache[' '].insert(i);
    }
  }

  char cur() { return zones[curRune].cur; }

   char getF() {
     int plusOne = curRune+1;
     if (plusOne == 30) plusOne = 0;
     return zones[plusOne].cur;
   }

    char getB() {
      int minusOne = curRune -1;
      if (minusOne < 0) minusOne = 29;
      return zones[minusOne].cur;
    }

  void moveForward() {
    curRune += 1;
    curRune %= 30;
  }

  void moveBackwards() {
    curRune -= 1;
    if (curRune < 0) {
      curRune += 30;
    }
  }

  bool hasCached(char c) { return !cache[c].empty(); }

  int getDistToCache(char c) {
    if (!hasCached(c)) return 40;

    auto st = cache[c];
    int minDist = 40;
    for (int i : st) {
      // forward distance.  cur rune 29 , cache 0, expect 1
      int forward = (i >= curRune) ? i - curRune : i + (30 - curRune);
      // backwards distance  cur = 0 i = 29, expect 1
      int backwards = (i <= curRune) ? curRune - i : curRune + (30 - i);
      backwards *= -1;

      int absbackwards = abs(backwards);
      int absMinDist = abs(minDist);
      if (absbackwards < forward) {
        if (absMinDist > absbackwards) {
          minDist = backwards;
        }
      } else {
        if (absMinDist > forward) {
          minDist = forward;
        }
      }
    }
    return minDist;
  }

  void printCache() {
    for (auto a : cache) {
      for (auto item : a.second) {
        cerr << "checking cache for " << a.first << endl;
        cerr << "item is " << item << endl;
      }
    }
  }

  void incr() {
    cache[zones[curRune].cur].erase(curRune);
    zones[curRune].plus();
    cache[zones[curRune].cur].insert(curRune);
  }

  void decr() {
    cache[zones[curRune].cur].erase(curRune);
    zones[curRune].minus();
    cache[zones[curRune].cur].insert(curRune);
  }
};

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

Register reg;

string getNextSection(int forwardDist, int backwardsDist) {
  string brainFork = "";
  if (forwardDist <= backwardsDist) { /* extract*/
    for (int i = 0; i < forwardDist; ++i) {
      brainFork += "+";
      reg.incr();
    }
  } else {
    for (int i = 0; i < backwardsDist; ++i) {
      brainFork += "-";
      reg.decr();
    }
  }
  return brainFork;
}

pair<int,int> getMaxCount(string& s) {
  int longest = 0;
  int startidx = 0;
  int longestStart = 0;
  char cur = '0';
  int curcount = 0;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == cur) {
      curcount++;
      if (longest < curcount) {
        longest = curcount;
        longestStart = startidx;
      }
    } else {
      curcount = 1;
      startidx = i;
      cur = c;
    }
  }
  return {longest, longestStart};
}

string simplify(string s) {
  auto [a,b] = getMaxCount(s);
  int times = a/26;
  if (times > 0) {

  }
  int rem = a%26;
  char repeated = s[b];
  string replace = "";
  if (times > 0) replace+= '>';
  for (int i = 0; i < times; ++i) {
    replace += "-[<.>-]";
  }
  if (rem > 0) {
    replace += '<';
  }
  for (int i = 0; i < rem; ++i) {
    replace += repeated;
  }
  if (a > 26) {
    s = s.substr(0,b) + replace  + s.substr(b+a);
  }
  return s;
}

int main() {
  // space - 32, A - 65, Z - 90

  string magic_phrase;
  getline(cin, magic_phrase);
  string brainFork = "";
  for (char c : magic_phrase) {
    char current = reg.cur();
    int forwardDist = forwardDistance(current, c);
    int backwardsDist = backwardsDistance(current, c);
    int fromCurRune = min(forwardDist, backwardsDist);
    int forwardFromSpace = forwardDistance(' ', c);
    int backwardsFromSpace = backwardsDistance(' ', c);
    int distToSpace = reg.getDistToCache(' ');
    int fromSpace =
        min(forwardFromSpace, backwardsFromSpace) + abs(distToSpace);
    int fromFNeighbor = 1+forwardDistance(reg.getF(), c);
    int fromFNeighborBack = 1+backwardsDistance(reg.getF(), c);
    int fromF = min(fromFNeighbor,fromFNeighborBack);

    int fromBNeighbor = 1+forwardDistance(reg.getB(), c);
    int fromBNeighborBack = 1+backwardsDistance(reg.getB(), c);
    int fromB = min(fromBNeighbor,fromBNeighborBack);

    int distFromCache = reg.getDistToCache(c);

    int minCurRune = min(fromCurRune, fromSpace);



    if (fromB < minCurRune && fromB < fromSpace && fromB < distFromCache && fromB < fromF) {
      // from forward logic
      brainFork += '<';
      reg.moveBackwards();
      brainFork += getNextSection(fromBNeighbor-1, fromBNeighborBack-1);
      brainFork += '.';
      continue;
    }

    if (fromF < minCurRune && fromF < fromSpace && fromF < distFromCache && fromF < fromB) {
      // from forward logic
      brainFork += '>';
      reg.moveForward();
      brainFork += getNextSection(fromFNeighbor-1, fromFNeighborBack-1);
      brainFork += '.';
      continue;
    }

    if (minCurRune <
        abs(distFromCache)) {  // using current rune is better than using cache.
      if (fromCurRune <= fromSpace) {  // starting new register
        if (c == ' ' && abs(fromCurRune) > 3) {
         brainFork+="[-]";
         while (reg.cur() != ' ') reg.decr();
        } else {
        brainFork += getNextSection(forwardDist, backwardsDist);
        }

      } else {  // using current register

          if (distToSpace >= 0) {
            bool shouldpr = true;
            if (abs(distToSpace) > 3) {
              shouldpr = false;
              brainFork += "[>]";
            }
          while (distToSpace > 0) {
            distToSpace--;
            reg.moveForward();
            if (shouldpr) brainFork += ">";
          }
        } else {
          bool shouldpr = true;
          if (abs(distToSpace) > 3) {
            shouldpr = false;
            brainFork += "[<]";
          }
          while (distToSpace < 0) {
            distToSpace++;
            if (shouldpr) brainFork += '<';
            reg.moveBackwards();
          }
        }

        brainFork += getNextSection(forwardFromSpace, backwardsFromSpace);


      }
    } else {
      if (distFromCache >= 0) {
        while (distFromCache > 0) {
          distFromCache--;
          brainFork += '>';
          reg.moveForward();
        }
      } else {
        while (distFromCache < 0) {
          distFromCache++;
          brainFork += '<';
          reg.moveBackwards();
        }
      }
    }

    brainFork += ".";
  }

  string processed = simplify(brainFork);

  cout << processed << endl;
}

/*

wow this gives 6833!

if a pattern is repeated 26 times, then use a loop

replacing the single chars - and shaky logic still got 100%.
brings us down to 6744.
- eek out another 250?


down to 6657.

6655

tweaking the last 150?
- extra check - add neighbors

gets us down to 6393!!!! great success
- lets add the backwards check too

- add back check gives us 6276

- no changes
*/
