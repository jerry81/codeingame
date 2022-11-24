/*

	Goal
In a visit to a gallery I saw a contemporary art painting such that the whole picture is full of checker-pattern tiles, with alternating squares of darker and lighter colors (like the one in the banner). Though I was unable to appreciate how this painting was worth the quoted dollar value, I envisioned plenty of chessboards embedded in the pattern.

How many chessboards can be found in the painting? I was wondering.

A chessboard is defined as an area of 8x8 tiles and MUST have a white (or a lighter color) tile at the bottom-right corner. The painting has its strict orientation. One cannot rotate the painting to count nor count a rotated area as a valid chessboard.
Input
Line 1 : An integer n, for the number of lines to follow.
Following n lines : Each line is an independent test carrying three integers
row col isWhite.

row is the number of rows of tiles in the painting.
col is the number of columns of tiles in the painting.
isWhite is either 0 or 1. 0 means false; 1 means true. It indicates whether the lower-right corner of the painting is white (or is a lighter color).
Output
Write n lines. For each test, write an integer showing the number of valid chessboards that can be found in the painting.
Constraints
8 ≤ row, col ≤ 10000
1 ≤ n ≤ 100
Example
Input
5
8 8 0
9 8 1
8 10 0
10 9 0
10 11 1
Output
0
1
1
3
6

*/

using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());

        for (int i = 0; i < n; i++)
        {
            int ans = 0;
            string[] inputs = Console.ReadLine().Split(' ');
            int row = int.Parse(inputs[0]);
            int col = int.Parse(inputs[1]);
            int isWhite = int.Parse(inputs[2]);
            // count down rows until 8
            // cont down cols until 8
            // keep track of right-most color
            int rows = row-7;
            int cols = col-7;
            int perRow = rows/2; // default: floor division
            Console.Error.WriteLine($"rows {rows} cols {cols}");
            // bool rowcolor = isWhite == 1;
            // bool colcolor = isWhite == 1;
            // for (int r = row; r >=8; --r) {
            //   for (int c = col; c >=8; --c) {
            //     if (colcolor) {
            //       ++ans;
            //     }
            //     colcolor = !colcolor;
            //   }
            //   rowcolor = !rowcolor;
            //   colcolor = rowcolor;
            // }
            Console.WriteLine(ans);
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");


    }
}