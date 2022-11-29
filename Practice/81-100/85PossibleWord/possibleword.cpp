/*

Goal
You are an examiner for different languages. Every year you get a lot of texts and should check if the words are in the language. Since you are lazy but highly motivated, you decide to automate this process.

Fortunately, the languages are pretty simple. So you want to build a state machine for every language, which can tell you quickly whether a word is in the language or not.

Now you have already built the languages, but you don't want to write code for each language individually. So now you have to come up with a flexible system that accepts your language and uses it to build a functioning machine.

Tip: draw the machine to better understand what is meant by status and transitions
Hint: https://en.wikipedia.org/wiki/Deterministic_finite_automaton


The following example refers to the example at the bottom (first test)

Just the necessary information from the input:
Word: "abc"
states : A B
startState : A
endState : B
Transitions :
A a B
A c B
B b A

You start in state A (startState). The first character found is an 'a'. According to the corresponding transition ( A a B ), you move to state B.

You are now in state B. The next character found is a 'b'. According to the corresponding transition ( B b A ), you move to state A.

Back in state A. The last character found is a 'c'. According to the corresponding transition ( A c B ), you move to state B again.

The word is over, the final state is B. This is in the set of the allowed final states (endStates), so the word "abc" is valid, and you print "true".
Input
Line 1: A string input for the alphabet which can lead to changes in state, separated with space

Line 2: A string states for the possible states, separated with space

Line 3: An integer numberOfTransitions for the number of transitions

Next numberOfTransitions lines: A string transition for the transition from one state to the next

Next line: A string startState for the state in which you start

Next line: A string endStates for all allowed final states, separated with space

Next line: An integer numberOfWords for the number of words

Next numberOfWords lines: A string word for the word which should be tested
Output
"true" or "false", depending on whether the tested word is in the language or not.

If the word contains a character that is not in the alphabet, "false" is expected.

If you are in a state and get a character that is in the alphabet but no transition, also return "false"
Constraints
input: always lower case

states: always upper case

numberOfTransitions > 0

startState: there will always be exactly one

numberOfEndStates > 0

0 < numberOfWords ≤ 10

Warning: the word can contain characters which are not in the input!

Warning: Not every state has a subsequent state for every input! But every input leads to at most one different state in every state! There is no input that leads to 2 or more other states. So if you are in state A, the input a points either to none or one state!
Example
Input
a b c
A B
6
A a B
A b B
A c B
B a A
B b A
B c A
A
B
10
a
ab
abc
abcd
abcde
aabbcc
aabbcca
abcabcabc
z
abcabcabo
Output
true
false
true
false
false
false
true
true
false
false

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class StateMachine {
  private:
    struct Transition {
      char nc;
      char ns;
    };
    char start_state;
    char end_state;
    vector<char> alphabet;
    unordered_map<char,vector<Transition>> state_lookup;
  public:
    StateMachine(string states, string alphabet) {
      for (char c:states) {
        if (c != ' ') {
          vector<Transition> t;
          state_lookup.insert({c,t});
        }
      }
      for (char c:alphabet) {
        if (c != ' ') {
          alphabet.push_back(c);
        }
      }
    }

    void add_transition(string transition) {
      Transition t;
      t.nc = transition[2];
      t.ns = transition[4];
      state_lookup[transition[0]].push_back(t);
    }

    void print_all() {
      for (char c: alphabet) {
        cerr << "alpha " << c << endl;
      }
      for (auto x: state_lookup) {
        cerr << "state " << x.first << endl;
        for (auto y: x.second) {
          cerr << "next char " << y.nc << " next state " << y.ns << endl;
        }
      }
    }
};

int main()
{
    string input;
    getline(cin, input);
    string states;
    getline(cin, states);
    StateMachine sm = StateMachine(states, input);
    int number_of_transitions;
    cin >> number_of_transitions; cin.ignore();
    for (int i = 0; i < number_of_transitions; i++) {
        string transition;
        getline(cin, transition);
        sm.add_transition(transition);
    }
    sm.print_all();
    string start_state;
    getline(cin, start_state);
    string end_states;
    getline(cin, end_states);
    int number_of_words;
    cin >> number_of_words; cin.ignore();
    for (int i = 0; i < number_of_words; i++) {
        string word;
        getline(cin, word);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "true or false" << endl;
}