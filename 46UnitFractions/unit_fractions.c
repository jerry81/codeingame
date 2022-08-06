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

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("1/n = 1/x + 1/y\n");

    return 0;
}