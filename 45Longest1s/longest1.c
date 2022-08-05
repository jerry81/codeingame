// 	Goal
// Given some bitstring b, you may change one bit from a 0 to a 1 in order to create the longest possible sequence of consecutive 1s. Output the length of the resulting longest sequence.

// Example: 11011101111
// Flipping the second 0 results in 11011111111, where the longest sequence of 1s is 8 long.
// Input
// Line 1: The bitstring b
// Output
// Line 1: The length of the longest possible sequence of 1s after flipping one bit
// Constraints
// 0 < number of bits in b < 1000
// b contains at least one 0
// Example
// Input
// 00
// Output
// 1

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
    char b[1000];
    scanf("%[^\n]", b);

    int i = 0;
    chunks = []
    while (b[i]) {
      ++i;
    }
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    // find "widths" of chunks and mark their start and end
    printf("answer\n");

    return 0;
}