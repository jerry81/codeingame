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
} Answer;

/*
 more memory refresher
 calloc -> "contiguous allocation" - suitable for arrays - two args, num of blocks and block size i.e. calloc(n, sizeof(int))
 malloc -> one arg, single block
 free - deallocates memory
 realloc - 2 args, the pointer, the new size
 void *reallocarray(void *ptr, size_t nmemb, size_t size);
*/

int main()
{
    int N;
    struct Answer *answers;
    int answers_size = 0;
    scanf("%d", &N);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    int a,b,c;

    int al = N / 5; // should floor
    for (int i = 0; i <= al; ++i) {
      for (int j = 0; j <= i; ++j) {
        int workingSum = (i * 5) + (j * 2);
        struct Answer a = {0,0,0};
        a.a = i;
        a.b = j;
        if (workingSum == N) {
          // allocate
          answers = reallocarray(answers, (answers_size+1), sizeof(Answer));
          answers[answers_size] = a;
          ++answers_size;
        }
        if (workingSum >= N) continue;

        int diff = N - workingSum;
        if (diff % 3 == 0) {
          a.c = diff / 3;
          answers = reallocarray(answers, (answers_size+1), sizeof(Answer));
          answers[answers_size] = a;
          ++answers_size;
        }
      }
    }
    for (int i = 0; i < answers_size; ++i) {
        printf("%d %d %d\n", answers[i].a, answers[i].b, answers[i].c);
    }
    // fprintf(stderr, "al is %d\n", al);

    return 0;
}

/**
 * strategy
 * the problem statement suggests only loops are necessary
 * the largest input in examples is just 88
 * try brute force first
**/