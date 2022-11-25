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
      // but in c# also struct pass by value, class pass by reference
      string pattern;
      int h;
      int w;
      List<string> picture = new List<string>();
      List<List<char>> frame = new List<List<char>>();
      int frameH;
      int frameW;

      public Frame(string p, int h, int w) {
        this.pattern = p;
        this.h = h;
        this.w = w;
      }

      public void AddLine(string s) {
        this.picture.Add(s);
      }


      public void Test() {
        Console.Error.WriteLine($"pattern {this.pattern}");
        foreach (var v in picture) {
            Console.Error.WriteLine(v);
        }
      }

      public void buildRing(int offset) {
        char patternItem = this.pattern[offset];
        for (int i = offset; i < (this.frameH - offset); ++i) {
          if ((i == offset) || (i == (this.frameH - offset - 1))) {
            for (int j = offset; j < (this.frameW - offset); ++j) {
                this.frame[i][j] = patternItem;
            }
          } else {
            this.frame[i][offset] = patternItem;
            this.frame[i][this.frameW - offset - 1] = patternItem;
          }
        }
      }

      public void BuildFrame() {
        // initialize the frame
        this.frameW = (this.pattern.Length * 2) + this.w + 2;
        this.frameH = (this.pattern.Length * 2) + this.h + 2;
        for (int i = 0; i < frameH; ++i) {
          this.frame.Add(new List<char>());
          for (int j = 0; j < this.frameW; ++j) {
            this.frame[i].Add(' ');
          }
        }
        for (int offset = 0; offset < this.pattern.Length; ++offset) {
          this.buildRing(offset);
        }
      }

      public void PrintFrame() {
        foreach (List<char> s in this.frame) {
          string t = new string(s.ToArray());
          Console.Error.WriteLine(t);
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
        f.Test();
        f.BuildFrame();
        f.PrintFrame();

        Console.WriteLine("Write framed picture line by line here");
    }
}