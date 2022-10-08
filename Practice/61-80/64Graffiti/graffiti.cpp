/*

	Goal
You are paid by a farmer to paint his fence.

Knowing that the task can be too difficult for yourself, you sub-contracted the job to a school of students as their extracurricular activity, to draw graffiti on the fence.

After a whole day of work and fun, the students reported which sections of the fence have been painted. The students were working in small teams or individually, so that you got multiple separated reports from them.

The fence has markings on it at every meter, count from meter 0. A painted section is reported as
st ed
which means painting is done from [starting point] to [ending point].
We take only integer readings.

Example

    st      ed
    !░░░░░░░░!
 +--+--+--+--+--+--
 0  1  2  3  4  5

st = 1
ed = 4
painted length = 3


The painted sections may not be continuous, done on different parts of the fence. Some reported sections are even overlapping. The reports are not sorted in any special order.

Having the reports in hands, you want to know which sections of the fence have not been painted.
Input
Line 1: An integer L for the total length of the fence in meter
Line 2: An integer N for the number of reports
Next N lines: Each line defines a reported section, by format st ed.
Output
A list of unpainted sections, one section on each line, by format st ed,
sorted by st in ascending order.

If there is no unpainted section, output a line:

All painted
Constraints
1 ≤ L ≤ 2,000,000,000
1 ≤ N ≤ 100
0 ≤ st < ed ≤ L

Of course you can declare and use arrays. It is just a bad approach if you wish to create an array occupying 2GB continuous memory.
Example
Input
10
2
1 4
5 6
Output
0 1
4 5
6 10

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

struct Interval {
  long int s;
  long int e;
};


int main()
{
    int l;
    cin >> l; cin.ignore();
    int n;

    cin >> n; cin.ignore();
    Interval all[n];
    for (int i = 0; i < n; i++) {
        int st;
        int ed;
        cin >> st >> ed; cin.ignore();
        Interval next;
        next.s = st;
        next.e = ed;
        all[i] = next;
    }

    for (int i = 0; i < n; ++i) {
      cerr << "interval st,end " << all[i].s << " " << all[i].e << endl;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}

// step 1, store the intervals in structures