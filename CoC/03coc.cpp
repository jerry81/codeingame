/*

In this Clash you have to recreate the emoji system of CodinGame.
For example, if you type this in the chat you get:
:slight_smile: --> :)
:disappointed: --> :(
Input
An string s
Output
The string, with emojis inserted:
:slight_smile: ---> :)
:disappointed: ---> :(
:loud_laugh: ---> XD [not a real chat emoji conversion]
:open_mouth: ---> :o
:stuck_out_tongue: ---> :p
THESE WILL BE THE ONLY EMOJIS COMING IN THE TEST CASES
Constraints
Length of s <= 100
Each word is seprated by a single whitespace
Example
Input
This is SOO easy :loud_laugh:
Output
This is SOO easy XD

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/



 vector<string> split(string str) {
    // Returns first token
    vector<string> ret;
    char *token = strtok(str.data(), " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
      ret.push_back(token);
      token = strtok(nullptr, " ");

    }

    return ret;
  }
  unordered_map<string,string> lookup;
int main()
{
    string s;
    getline(cin, s);
    lookup[":slight_smile:"] = ":)";
    lookup[":disappointed:"] = ":(";
    lookup[":loud_laugh:"] = "XD";
    lookup[":open_mouth:"] = ":o";
      lookup[":stuck_out_tongue:"] = ":p";
    string news = "";
    vector<string> spl = split(s);
    bool init = false;
    for (string s: spl) {
        if (!lookup[s].empty()) {
            if (init) {
                news+= " ";

            }
            init = true;
            news+=lookup[s];
        } else {
            if (init) {
            news+=" ";
            }
                init = true;
            news+=s;
        }
    }
    cout << news << endl;
}