/*

	Goal
This program problem find out the consecutive string from a to z in alphabetical order in a multi-line string m of n lines of length n.
You can move up, right, left or down. First, you find the a.
if there is a b either up, down, left or right from the position of a, you can move there. if there is a c either up, down, left or right from the position of b, you can move there. continues below to z.
Rewrites all nonconsecutive strings of letters a through z to -.
In other words, this problem only displays the consecutive string from a to z in a multi-line string m of n lines of length n.
Answer to output , as follows.

Example:


10
qadnhwbnyw
iiopcygydk
bahlfiojdc
cfijtdmkgf
dzhkliplzg
efgrmpqryx
loehnovstw
jrsacymeuv
fpnocpdkrs
jlmsvwvuih


The answer to this is...


----------
----------
ba--------
c-ij------
d-hkl---z-
efg-mpqryx
----no-stw
--------uv
----------
----------


As above, only the string alphabetically from a to z should be displayed, and the other parts should be -.
Input
Line 1: An integer n for the size of the string figure.
Next n Lines: multi-line string m.
Output
Output only strings alphabetically from a to z should be displayed in multi-line string m, and the other parts should be -.
Constraints
10<=n<=30
m consists only of lowercase alphabetical characters.
There may be more than one a.
Example
Input
10
vkbjbzmbgb
abcccpzouv
fedopwlmcl
glmnqrszyw
hkrhiutymj
ijqcmvwxoc
pcvlpqzphl
hsgvoklcxy
urdjusmbmz
rchbcausnp
Output
----------
abc-------
fedop-----
glmnqrsz--
hk---uty--
ij---vwx--
----------
----------
----------
----------

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
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string m;
        cin >> m; cin.ignore();
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}

// loop all 'a'
// - try the chain for each
// helper int to char