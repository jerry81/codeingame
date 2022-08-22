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

struct Answer {
  int a;
  int b;
  int c;
};

/*
 more memory refresher
 calloc -> "contiguous allocation" - suitable for arrays - two args, block size and size
 malloc -> one arg, single block
 free - deallocates memory
*/

int main()
{
    int N;
    struct Answer *answers;
    scanf("%d", &N);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    int a,b,c;

    printf("tries transformations penalties\n");

    return 0;
}

/**
 * strategy
 * the problem statement suggests only loops are necessary
 * the largest input in examples is just 88
 * try brute force first
**/