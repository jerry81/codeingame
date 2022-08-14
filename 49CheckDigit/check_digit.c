/*
Goal
International Standard Book Number (ISBN) is a unique numeric commercial book identifier.

Before year 2007 ISBNs were 10-digit long. After that year ISBNs extended to 13 digits. In both ISBN-10 and ISBN-13 standards, the last digit is the check digit, for error detection.

ISBN-10 check digit is calculated by Modulus 11 with decreasing weights on the first 9 digits.
Example: 030640615?
0×10 + 3×9 + 0×8 + 6×7 + 4×6 + 0×5 + 6×4 + 1×3 + 5×2 = 130.
130 / 11 = 11 remainder 9.
Check digit is the value needed to add to the sum to make it dividable by 11. In this case it is 2.
So the valid ISBN is 0306406152.
In case 10 being the value needed to add to the sum, we use X (upper case X) as the check digit instead of 10.

ISBN-13 check digit is calculated by Modulus 10 with alternate weights of 1 and 3 on the first 12 digits.
Example: 978030640615?
9×1 + 7×3 + 8×1 + 0×3 + 3×1 + 0×3 + 6×1 + 4×3 + 0×1 + 6×3 + 1×1 + 5×3 = 93.
93 / 10 = 9 remainder 3.
Check digit is the value needed to add to the sum to make it dividable by 10. So the check digit is 7. The valid ISBN is 9780306406157.

Your task is to validate a list of ISBNs.

A valid ISBN should contain the digits 0 to 9 only, except for the check digit X which is determined as explained above. X or other improper characters appearing in the wrong place will render an ISBN invalid.
Input
Line 1: An integer N for the number of ISBNs to verify.
Next N lines: One line for each ISBN to verify.

In this puzzle we assume all ISBNs have been normalized - have spaces and dash characters removed.
Output
Line 1: A string Y invalid: where Y is the number of invalid ISBNs.
Next Y lines: One line for each invalid ISBN, in the same order as given in the inputs.
Constraints
1 ≤ N ≤ 500
1 ≤ Y ≤ N (i.e. there will always be at least one invalid ISBN in each case)
Example
Input
6
0306406152
013603599X
1145185215X
9780306406157
9780306406154
978043551907X
Output
3 invalid:
1145185215X
9780306406154
978043551907X
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

char get_checksum(char isbn[21]) {
  int i = 0;
  while (isbn[i] != '\0') {
    ++i;
  }
  fprintf(stderr, "len is %i\n", i);
  return 'a';
}

int main()
{
    int N;
    scanf("%d", &N); fgetc(stdin); // fget c: gets character from file pointer - must be reading the new line
    char ISBNs[N][21];
    for (int i = 0; i < N; i++) {
        char ISBN[21];
        scanf("%[^\n]", ISBN); fgetc(stdin);
        strcpy(ISBNs[i],ISBN);
        fprintf(stderr, "Isbns is %s\n", ISBNs[i]);
        get_checksum(ISBN);
    }




    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("answer\n");

    return 0;
}