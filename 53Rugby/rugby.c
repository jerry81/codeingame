/*
Given a rugby score, your program must compute the different scoring combinations that lead to that particular score.
As a reminder:
- a try is worth 5 points
- after a try, a transformation kick is played and is worth 2 extra points if successful
- penalty kicks and drops are worth 3 points
Input
Line 1: the score
Output
N lines: number of tries, number of transformations, number of penalties / drops, separated by spaces
The combinations must be ordered by increasing order of tries, then transformations, then penalties/drops
Constraints
No impossible scores are given, there is always at least one valid combination.
Example
Input
12
Output
0 0 4
2 1 0
*/

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
    int N;
    scanf("%d", &N);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("tries transformations penalties\n");

    return 0;
}