/*
Goal
A digital river is a sequence of numbers where every number is followed by the same number plus the sum of its digits. In such a sequence 123 is followed by 129 (since 1 + 2 + 3 = 6), which again is followed by 141.

We call a digital river river K, if it starts with the value K.

For example, river 7 is the sequence beginning with {7, 14, 19, 29, 40, 44, 52, ... } and river 471 is the sequence beginning with {471, 483, 498, 519, ... }.

Digital rivers can meet. This happens when two digital rivers share the same values. River 32 meets river 47 at 47, while river 471 meets river 480 at 519.

Given a number decide, whether it can be a meeting point of two or more digital rivers. For example, it is easy to check that only river 20 contains the number 20 in its sequence (as a starting point).

(Idea : BIO'99)
Input
Line 1: An integer r1.
Output
Line 1 : YES if r1 can be a meeting points of two digital rivers, NO otherwise.
Constraints
1 ≤ r1 < 100000
Example
Input
20
Output
NO
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int sum_digits_plus(int i)
{
    int n = log10(i) + 1; // gets base 10 log. (10^x = 10000, x = 4)
    char *numberArray = calloc(n, sizeof(char)); // calloc
    /*
    calloc() gives you a zero-initialized buffer, while malloc() leaves the memory uninitialized.
    */
    for (int j = n-1; j >= 0; --j, i /= 10) // statements that run each loop can be listed (comma seperated)
    {
        numberArray[j] = (i % 10) + '0'; // review - single digit to char trick
    }
    int s = 0;
    for (int k = 0; k < n; ++k) {
      int item = (int)numberArray[k] - '0';
      s += item;
    }
    return s;
}

int connection(int r_1) {
    for (int i = 1; i < r_1; ++i) {
      int s = i + sum_digits_plus(i);
      if (s == r_1) {
        return i;
      }
    }
    return -1;
}

int main()
{
    int r_1;
    scanf("%d", &r_1);
    // int s = sum_digits_plus(r_1);
    // fprintf(stderr, "s is %d\n", s);
    int i = connection(r_1);
    bool answer = false;
    if (i > 0) {
      answer = (connection(i)>0);
    }
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    char returned[4];
    strcpy(returned, answer ? "YES" : "NO");
    printf("%s\n", returned);

    return 0;
}

/* analysis
20
so the previous could be
x + y = 20
x < 20
y < 20
10 + 1
11 + 2
12 + 3
13 + 4
14 + 5
15 + 6
9 + 9 = 18..
10 + 1 = 11
11 + 2 = 13
x has no predecessors

13
12 + 3
11 + 2 yes
10 + 1
9 + 9

7 14
5 10 11 13

32 37 47

y = x + sum(dig(x))

y = 20
20 = x + sum(dig(x))

20 = x + a + b where a and b is 0 or 1, b is 0 - 9
x = 20 - a - b
a = 20 - x - b
b = 20 - a - x
substitution will not help here?

brute force?
x min is y - sum(max)
sum(max) is y

9915
9800
*/



