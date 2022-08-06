// 	Goal
// For every fraction in the form 1/n (where n is an integer > 0), we can always find two positive integers x and y such that:

// 1/n = 1/x + 1/y

// There can be one or more pairs of x and y fitting the above equation.


// Example
// Given n = 2
// 1/2 = 1/6 + 1/3
// 1/2 = 1/4 + 1/4


// Could you list out all these equations for a given n?
// Input
// Line 1: Integer n
// Output
// All combinations of n, x, y in the format 1/n = 1/x + 1/y, where x ≥ y

// Sort the list by x in descending order.
// Write each equation on its own line.
// Constraints
// 1 ≤ n ≤ 1000000
// Example
// Input
// 2
// Output
// 1/2 = 1/6 + 1/3
// 1/2 = 1/4 + 1/4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    scanf("%d", &n);
    int alist[n];
    long long int blist[n];
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    // observing exmaple cases, max x, y is always n*2, a,b=n*2 is always part of list
    // also can start trying from n+1
    int ptr = 0;
    for (int i = n+1; i <= n * 2; ++i) {
      // bulk of the logic
      long long int asLongLong = (long long int) i;
      long long int asLongLong2 = (long long int) n;
      fprintf(stderr, "i is %d, n is %d, long double is %lld\n", i, n, (asLongLong*asLongLong2));
      long double b = (long double)(asLongLong*asLongLong2) / (long double)(asLongLong-asLongLong2);
      fprintf(stderr, "b is %Lf\n", b);
      if (ceilf(b) == b) {
        alist[ptr] = i;
        blist[ptr] = (long long int)b;
        ++ptr;
      }
    }
    for (int ptr2 = 0; ptr2 < ptr; ++ptr2) {
      printf("1/%d = 1/%lld + 1/%d\n", n, blist[ptr2], alist[ptr2]);
    }
    return 0;
}

/*
n = 17 example
1/17 = 1/18 + 1/306
trial and error?
1/17 = 1/34 + 1/34 ...
17/578 34/578

1/18 + 1/306 = 17/306 + 1/306 = 18 / 306 = 17
1/19 + 1/y = 1/17 ??
(19*y / 19) + (19/y*19) = 1/17
19y/19y + 19/19y = 19y + 19 / 19y = 1/17
34
*/