/*

	The Goal
A finance company is carrying out a study on the worst stock investments and would like to acquire a program to do so. The program must be able to analyze a chronological series of stock values in order to show the largest loss that it is possible to make by buying a share at a given time t0 and by selling it at a later date t1. The loss will be expressed as the difference in value between t0 and t1. If there is no loss, the loss will be worth 0.
 	Game Input
Input
Line 1: the number n of stock values available.

Line 2: the stock values arranged in order, from the date of their introduction on the stock market v1 until the last known value vn. The values are integers.

Output
The maximal loss p, expressed negatively if there is a loss, otherwise 0.
Constraints
0 < n < 100000
0 < v < 231
Examples

Input
6
3 2 4 2 1 5
Output
-3

Input
6
5 3 4 2 3 1
Output
-4

Input
5
1 2 4 4 5
Output
0

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    vector<int> original;
    vector<int> maxes;
    int max = 0;
    vector<int> mins;
    int min = 2147483647;
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        original.push_back(v);
        if (v > max) {
          max = v;
        }
        maxes.push_back(max);
    }
    for (int i = n-1; i >-1; --i) {
      int o = original.at(i);
      if (o < min) {
        min = o;
      }
      mins.push_back(min);
    }

    reverse(mins.begin(), mins.end());
    cerr << "printing maxes"<<endl;
    for (int i:maxes) {
      cerr << i << endl;
    }
    cerr << "printing mins"<<endl;

    for (int i:mins) {
      cerr << i << endl;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}