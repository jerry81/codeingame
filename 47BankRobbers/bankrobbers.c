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
    int R;
    scanf("%d", &R);
    int V;
    scanf("%d", &V);
    long int vaults[V];
    long int queue[R];
    for (int i = 0; i < V; i++) {
        int C;
        int N;
        scanf("%d%d", &C, &N);
        int combinations = 0;
        int vowels_count = C-N;
        int digit_count = N;
        int digitSum = 1;
        while (digit_count > 0) {
          digitSum *= 10;
          --digit_count;
        }
        fprintf(stderr, "combin now %d digitSum now %d\n",  combinations, digitSum);
        if (digitSum > 1) {
          combinations += digitSum;
        }
        int vowel_sum = 1;
        while (vowels_count > 0) {
          vowel_sum *= 5;
          --vowels_count;
        }
        fprintf(stderr, "combin now %d vowelSum now %d\n",  combinations, vowel_sum);
        if (vowel_sum > 1) {
          combinations *= vowel_sum;
        }
        vaults[i] = combinations;
        fprintf(stderr, "combinations is %d\n", combinations);
    }
    int minIdx = 0;
    int min = -1;
    // init main loop
    for (int i = 0; i < R; ++i) {
      queue[i] = vaults[i];
      if (min < 0 || queue[i] < min) {
        min = queue[i];
        minIdx = i;
      }
    }
    fprintf(stderr, "min is %d", min);
    // get min of the items in queue

    // 1 robber
    // 1 vault, 3 chars, 1 digit 10*5*5 = 50 * 5 = 250
    // 4

//   4
//   4
//   3 2
//   4 1
//   7 6
//   7 1
//   5000000

// this case is easy - as fast as the slowest robber
// (7,6 case) 10^6 * 5 = 5M yes

// 2
// 4
// 3 1
// 3 2
// 4 0
// 4 0
// 1125
// 2 robbers, 4 valuts
// total = 0
// enqueue 3 1 (10 * 5^2)
// enqueue 3 2 (10^2 * 5)
// get min of the two
// total += min
// get remainder of the other
// dequeue min, modify other to remainder
// enqueue 4,0
// until no queue empty and vaults empty



    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("1\n");

    return 0;
}