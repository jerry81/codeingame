/*

	Goal
When two famous people get together and form a romantic couple, the Tabloids love to write about them and their adventures, scandals, and relationship drama.


The reporters combine (smoosh) their two individual names together to create a Couple-Name -- just for fun and to make it easier to write about them. Examples:
💕 Ben + Jennifer = Bennifer
💕 Brad + Angelina = Brangelina
💕 Heidi + Spencer = Speidi

Given the following rules, print out options for each couple.

RULES:
The overall process is:
Smoosh a left-substring (or whole name) of one person together with a right-substring (or whole name) of the other person, in such a way that there is at least 1 overlapping-letter (aka shared letter, aka common letter).
➤ Comparisons aren't case-sensitive.
➤ No spelling changes other than “sub-stringing”
➤ Must contain at least one letter from each person, that isn't part of the overlapping-letter(s).
➤ Must not be shorter than the shortest individual-name.
➤ Cannot be the same as either of the individual names because that's just silly

Only Max Overlapping:
➤ Include only Couple-Names with the most overlapping-letters possible. For example, if there is a Couple-Name that has 2 overlapping-letters, don't show others that have less than 2 overlapping-letters.

Formatting:
➤ A Couple-Name has only the first letter capitalized, regardless of the capitalization in the individual names.
➤ Where there are multiple options, list them alphabetically on the same line separated by spaces.
➤ If no options, print NONE


Sorry I can't help more, but Keanu Reeves and I are headed out on some excellent "Lisanu" adventures, on a luxury yacht in Cannes.
Or maybe Eddie Mark Jacobson and I (“Eddisa”) will have a Big Night Out on the Gold Coast.
Input
Line 1: An integer n, denoting the number of couples
Line 2: n couples, in the format of name1 (which is always a single word) and name2 (which is always a single word) and then sometimes a last name or other extra information just as FYI, in case you need it for your Tabloid story.
(name1 and name2 -- which are ALWAYS the 1st word and 3rd word in the input string -- is all you use to make a Couple-Name)
Output
n lines: Couple-Names for each couple: name1 plus name2 = alphabetized list of Couple-Names separated by spaces, or NONE
Constraints
Names do not have anything other than letters.
Example
Input
6
Lois and Clark
Ben and Jennifer
Tarzan and Jane
Priscilla and Elvis
Simba and Nala
Mork and Mindy
Output
Lois plus Clark = Clois
Ben plus Jennifer = Bennifer
Tarzan plus Jane = Tarzane
Priscilla plus Elvis = Elviscilla
Simba plus Nala = Simbala
Mork plus Mindy = NONE

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


class TabloidName {
  string name1 = "";
  string name2 = "";
  vector<string> names;
  int longest = 0;
  void checkConsecutive(int starti, int startj) {
    if (starti > name1.length()) return;

    if (startj > name2.length()) return;

    int offset = 0;
    int total = 1;
    if (1 > longest) longest = 1;
    while (((starti+offset) < name1.length()) || ((startj+offset) < name2.length())) {
      if (name1[starti+offset] == name2[startj+offset]) {
        total++;
        if (total > longest) longest++;
      }
      offset++;
    }
  };
  void setLongestSubstring() {
    for (int i = 0; i < name1.length(); ++i) {
      char curc = tolower(name1[i]);
      int curlen = 0;
      int offset = 0;
      for (int j = 0; j < name2.length(); ++j) {
        if (curc == tolower(name2[j])) {
          checkConsecutive(i+1, j+1);
        }
      }
    }
  };
  bool rule1(string attempt) {
    return (attempt != name1 && attempt != name2);
  };
  bool rule2(string attempt) {
    int l = attempt.length();
    return (l >= name1.length() || l >= name2.length());
  };
  void build() {
    cerr << "name1 " << name1 << " " << name2 << endl;
     cerr << "longest is " << longest << endl;
    for (int i = 0; i < name1.length(); ++i) {
      char curc = tolower(name1[i]);
      string prefix1 = name1.substr(0, i);
      string suffix1 = name1.substr(i + 1);
      for (int j = 0; j < name2.length(); ++j) {
        char curc2 = tolower(name2[j]);
        if (curc == curc2) {

          // next rule: max overlapping characters
          // substring 1 + substring 2
        }
      }
    }
  };
  public:
    TabloidName(string n1, string n2) : name1(n1), name2(n2) {
      setLongestSubstring();
      build();
    };
    string getNamesAsString() {

      string prefix = name1 + " plus " + name2 + " = ";
      if (names.empty()) return prefix + "NONE";

      string suffix = "";
      for (string s: names) {
        suffix += s;
        suffix += " ";
      }
      suffix.pop_back();
      return prefix + suffix;
    }

};


int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string a_couple;
        getline(cin, a_couple);
        // forgot how to split, again!!
        stringstream ss(a_couple);
        vector<string> names;
        string str;
        while (getline(ss,str, ' ')) {
          names.push_back(str);
        }
        TabloidName cur = TabloidName(names[0],names[2]);
        cout << cur.getNamesAsString() << endl;
    }





}