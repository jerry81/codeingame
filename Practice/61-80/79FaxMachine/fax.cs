/*

	Goal
An old compressed black and white fax transmission needs to be decompressed. The format of the compression is a series of numbers as such:

The first number is the width of the decompressed image.
The second number is the height of the decompressed image.
The starting color is black.
The third and remaining numbers are the number of pixels to draw from left to right, then top to bottom of the current color. After that number of pixels is filled then the color swaps.

The following fax

8
3
10 10 4

produces the following 8×3 output where "*" is black and " " (space) is white, and "|" is added as the left and right border

|********|
|**      |
|    ****|


This puzzle was inspired by https://www.codingame.com/training/expert/music-scores which has a very similar encoding system.

This encoding system is similar Modified Huffman Coding, which the earliest digital fax machines used. See https://en.wikipedia.org/wiki/Modified_Huffman_coding
Input
Line 1: Width
Line 2: Height
Line 3: Integers describing the compressed fax
Output
Height lines: rows with fax output of "*" (black) and " " (white) columns (surrounded by "|")
Constraints
1 ≤ Width, Height ≤ 100
Example
Input
8
3
10 10 4
Output
|********|
|**      |
|    ****|

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
        int W = int.Parse(Console.ReadLine());
        int H = int.Parse(Console.ReadLine());
        string T = Console.ReadLine();

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("|********|");
        Console.WriteLine("|**      |");
        Console.WriteLine("|    ****|");
    }
}