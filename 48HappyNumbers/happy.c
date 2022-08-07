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
    scanf("%d", &N); fgetc(stdin);
    char xs[N][129]; // TIL 2d array
    for (int i = 0; i < N; i++) {
        char x[129];
        scanf("%[^\n]", x); fgetc(stdin);
        strcpy(xs[i],x);
    }
    for (int i = 0; i < N; i++) {
        int firstsum = -1;
        char curStr[129] = xs[i];
        int curi = 0;
        while (curStr[curi]) {
        }
        fprintf(stderr, "xs[i] is %s\n", xs[i]);
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("23 :)\n");

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