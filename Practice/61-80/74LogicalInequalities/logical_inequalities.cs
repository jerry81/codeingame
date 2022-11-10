/*

Goal
We are looking at a system of inequalities. Here all inequalities are simple and consist of one variable on each side. Considering a system of strict inequalities, determine whether this system is inherently consistent or if there is a flaw. A flaw is a contradiction of two or more inequalities, e.g. A > B > C > A. This is not possible from a logical point of view.
Input
Line 1: a positive integer n
The following n lines: inequalities of format LETTER > LETTER
Output
A string "consistent" if all inequalities are consistent or "contradiction" if there is a contradiction found.
Constraints
0 < n < 26
LETTER is a single letter in uppercase
Example
Input
2
A > B
B > C
Output
consistent

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
            string row = Console.ReadLine();
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("consistent/contradiction");
    }
}