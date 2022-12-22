/*

The Goal
You mission is to print a specific line of the Conway sequence.
 	Rules
Warning! This sequence can make you ill. The reasoning is simple but unusual: Read a line aloud whilst looking at the line above and you will notice that each line (except the first) makes ​​an inventory of the previous line.

1
1 1
2 1
1 2 1 1
1 1 1 2 2 1
3 1 2 2 1 1
...
- Line 3 shows 2 1 because the line 2 contains two 1, one after the other.
- Line 4 displays 1 2 1 1 because the line 3 contains one 2 followed by one 1.
- Line 5 displays 1 1 1 2 2 1 because the line 4 contains one 1 followed by one 2 followed by two 1.

This sequence refers to a technique used to encode ranges in order to compress identical values ​​without losing any information. This type of method is used, amongst others, to compress images.

Your mission is to write a program that will display the line L of this series on the basis of an original number R (R equals 1 in our example).

 	Game Input
Input
Line 1: The original number R of the sequence.

Line 2: The line L to display. The index of the first line is 1.

Output
The line L of the sequence. Each element of the sequence is separated by a space.
Constraints
0 < R < 100
0 < L ≤ 25
Example
Input
1
6
Output
3 1 2 2 1 1

*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

queue<int> get_next_sequence(queue<int> seq) {
    vector<int> counts;
    vector<int> values;
    bool should_print = false;
    int cur_count = 0;
    while (!seq.empty()) {
      int item =  seq.front();
      seq.pop();
      if (counts.empty()) {
        counts.push_back(1);
        values.push_back(item);
        continue;
      }


      int last_item = values.back();
      if (last_item == item) {
        ++counts.at(counts.size() - 1);
        continue;
      }

      counts.push_back(1);
      values.push_back(item);
    }

    queue<int> next_sequence;
    for (int i = 0; i < counts.size(); ++i) {
      next_sequence.push(counts[i]);
      next_sequence.push(values[i]);
    }


    return next_sequence;
}

void pq(queue<int> q) {
                while (!q.empty()) {
            cerr <<"queeue item " << q.front() << endl;
            q.pop();
    }
}

void panswer(queue<int> q) {
  string s = to_string(q.front());
  q.pop();
  while (!q.empty()) {
      int i = q.front();
      q.pop();
      s+=i;
      q.pop();
  }
  cout << s << endl;
}


int main()
{
    int r; // first number
    cin >> r; cin.ignore();
    int l; // nth row
    cin >> l; cin.ignore();
    queue<int> initial_seq;
    initial_seq.push(r);
    while (l > 1) {
        initial_seq = get_next_sequence(initial_seq);
        --l;
        // pq(initial_seq);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    panswer(initial_seq); // print nth row
}