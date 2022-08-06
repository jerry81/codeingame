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
    for (int i = 0; i < V; i++) {
        int C;
        int N;
        scanf("%d%d", &C, &N);
    }
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