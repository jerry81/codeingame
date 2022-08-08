#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 struct Answer {
   char label[129];
   char smiley[3];
 };

int main()
{
    int N;
    scanf("%d", &N); fgetc(stdin);
    struct Answer answers[N];
    char xs[N][129]; // TIL 2d array
    for (int i = 0; i < N; i++) {
        char x[129];
        scanf("%[^\n]", x); fgetc(stdin);
        strcpy(xs[i],x);
    }
    for (int i = 0; i < N; i++) {
        int firstsum = -1;
        struct Answer a;
        strcpy(a.label, xs[i]);
        int curi = 0;
        int sum = 0;
        while (xs[i][curi]) {
            int multiplier = xs[i][curi] - '0';
            int sq =  multiplier * multiplier;
            sum += sq;
            ++curi;
            // sum created
        }
        firstsum = sum;

        // options to convert to string
        // sprintf
        // log10 loop with modulo 10
        // itoa?
        // until firstsum reached again or sum becomes 1
        while (sum != 1) {
        //   // must convert int, sum to chararr
          curi = 0;
          char asC[129];
          sprintf(asC,"%d", sum);
          sum = 0;
          while (asC[curi]) {
            int multiplier = asC[curi] - '0';
            int sq =  multiplier * multiplier;
            sum += sq;
            ++curi;
          }
          fprintf("sum is %d", sum);
          if (sum == firstsum) {
            fprintf(stderr, "repeated %d!", sum);
            strcpy(a.smiley,":(");
            break;
          }
          strcpy(a.smiley,":)");
        }
        answers[i] = a;
    }
    for (int i = 0; i < N; ++i) {
    struct Answer a = answers[i];
    printf("%s %s\n", a.label, a.smiley);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    return 0;

    // 4, 9 = 13
    // 1 9 = 10
    // 1

    // 4 16 20
    // 4 0 4
    // 4 16
    // 2 36 38
    // 9 64 73
    // 49 9 58
    // 25 64 89
    // 64 81  145
    // 1 16 25 42
    // 16 4 20 - only have to store one
}