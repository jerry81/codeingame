/*

Goal
I ordered beautiful mosaics online.
They were cheap, but they all came with the same issue: one single tile is not the good one.

Can you help me locate the wrong tile in each mosaic?

Each mosaic is made of N * N tiles.
Given a pattern of tiles that repeats to form a mosaic and the mosaic itself, you have to find the coordinates of the tile that doesn't fit the pattern.
The origin of the coordinates is at the top left corner of the mosaic.
Input
Line 1: An int N for the length (in tiles) of the side of the square mosaic.
Line 2: A string pattern for the pattern of tiles that form the mosaic.
Next N lines: a string that constitutes a row of the mosaic.
Output
A single line containing the coordinates of the wrong tile, formatted as (x,y)
Constraints
There is only one wrong tile in the mosaic.
The mosaic is always wider than the pattern.
Example
Input
6
xO
xOxOxO
xO/OxO
xOxOxO
xOxOxO
xOxOxO
xOxOxO
Output
(2,1)

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
    class PatternFinder {
      private string pattern;
      public PatternFinder(string pattern) {
        this.pattern = pattern;
      }
      public void Analyze(string line) {
        string[] split = line.split(this.pattern);
        for (var s in split) {
          Console.Error.WriteLine(s);
        }
      }
    }

    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        string pattern = Console.ReadLine();
        PatternFinder pf = PatternFinder(pattern);
        for (int i = 0; i < N; i++)
        {
            string row = Console.ReadLine();
            pf.Analyze(row);
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("(x,y)");
    }
}