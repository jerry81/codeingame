/*

The Goal
The Pilipius want to offer a present to one of them. The thing is, they all have different budgets to invest in this present. Of course, their unique wish is to find the fairest method that will determine the maximum budget that each Pilipiu can afford. The Pilipius have been discussing this issue for days, and up until now, they have not managed to find a totally satisfactory solution.

The Doctor decides to give a helping hand by creating a program. His idea is to check if the Pilipius have enough money to buy the present, and if so, to calculate how much each Pilipiu should pay, according to their respective budget limit.
 	Rules
The Doctor has in hand the list of maximum budgets for each Pilipiu. The Doctor's aim is to share the cost very precisely. To respect the Pilipius democratic values and to select the best solution, the Doctor decides that:
no Pilipiu can pay more than his maximum budget
the optimal solution is the one for which the highest contribution is minimal
if there are several optimal solutions, then the best solution is the one for which the highest second contribution is minimal, and so on and so forth...
Moreover, to facilitate the calculations, the Doctor wants each financial participation to be an integer of the local currency (nobody should give any cents).
 	Examples
For example, the Pilipius wish to buy a gift that cost 100. The first Pilipiu has a budget of 3, the second has a budget of 45 and the third has a budget of 100.

In that case:

Budget	Solution
3	3
45	45
100	52
Second example: they still wish to buy a gift that costs 100 but the second Pilipiu has a budget of 100 this time.

In that case:

Budget	Solution
3	3
100	48
100	49
 	Game Input
Input
Line 1: the number N of participants

Line 2: the price C of the gift

N following lines: the list of budgets B of participants.

Output
If it is possible to buy the present : N lines, each containing the contribution of a participant. The list is sorted in ascending order.
Otherwise the word IMPOSSIBLE.
Constraints
0 < N ≤ 2000
0 ≤ C ≤ 1000000000
0 ≤ B ≤ 1000000000
Examples
Input
3
100
20
20
40
Output
IMPOSSIBLE
Input
3
100
40
40
40
Output
33
33
34
Input
3
100
100
1
60
Output
1
49
50

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> results;

void getRemainderR(int sum, vector<int> remaining) {
  if (remaining.size() == 0) {
    results.push_back(sum);
    return;
  }

  int avg = sum / remaining.size();
  cerr << "avg is " << avg << endl;
  int min = remaining.back();
  int new_sum = sum - avg;
  if (min < avg) {
    new_sum = sum-min;
  }
  remaining.pop_back();
  getRemainderR(new_sum, remaining);
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    int c;
    int sum = 0;
    vector<int> items;
    cin >> c; cin.ignore();
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; cin.ignore();
        sum+=b;
        items.push_back(b);
    }
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());
    if (sum < c) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      getRemainderR(sum, items);
      sort(results.begin(), results.end());
      for (int i:results) {
        cout << i << endl;
      }
    }

}