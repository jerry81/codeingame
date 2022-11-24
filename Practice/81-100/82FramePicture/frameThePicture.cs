/*

	Goal
The goal of this exercise is to draw a ASCII art frame around a given ASCII art picture.
Always leave one space between the edges of the given picture and the frame. Also remember to rotate the frame pattern around the picture.

For instance, if the frame pattern is:
+.

The frame should look like this:
+++++++
+.....+
+.   .+
+. P .+
+.   .+
+.....+
+++++++
Input
Line 1: the ASCII art pattern to use to frame the picture
Line 2: the height h and the width w of the picture
Next h lines: the ASCII art picture
Output
Framed ASCII art picture.
Constraints
pattern length is <= 10
1 <= h <= 10
picture line length is <= 50
Example
Input
#
1 1
x
Output
#####
#   #
# x #
#   #
#####

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
    class Frame {
      // TIL: default accessibility private in class, public in struct
      string pattern;
      int h;
      int w;
      List<string> picture = new List<string>();
      int ph;
      int pw;

      public Frame(string p, int h, int w) {
        this.pattern = p;
        this.h = h;
        this.w = w;
      }

      public void AddLine(string s) {
        this.picture.Add(s);
      }

      public void AnalyzePicture() {
        this.ph = this.picture.Count;
        this.pw = this.picture[0].Length;
      }

      public void Test() {
        Console.Error.WriteLine($"pattern {this.pattern}");
        Console.Error.WriteLine($"picture dim h {this.ph} w {this.pw}");
        foreach (var v in picture) {
            Console.Error.WriteLine(v);
        }
      }
    }

    static void Main(string[] args)
    {
        string framePattern = Console.ReadLine(); // the ASCII art pattern to use to frame the picture
        string[] inputs = Console.ReadLine().Split(' ');
        int h = int.Parse(inputs[0]); // the height of the picture
        int w = int.Parse(inputs[1]); // the width  of the picture
        Frame f = new Frame(framePattern,h,w);
        for (int i = 0; i < h; i++)
        {
            string line = Console.ReadLine(); // the ASCII art picture line by line
            f.AddLine(line);
        }
        f.AnalyzePicture();
        f.Test();
        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("Write framed picture line by line here");
    }
}