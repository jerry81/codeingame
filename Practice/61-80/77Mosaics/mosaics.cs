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

class Solution
{
    class PatternFinder {
      private string pattern;
      private int curRow = 0;
      private int solRow = 0;
      private int solCol = 0;
      private List<string> rows = new List<string>();
      Dictionary<string,int> freq = new Dictionary<string, int>();
      Dictionary<string,int> rowLookup = new Dictionary<string, int>();
      public PatternFinder(string pattern) {
        this.pattern = pattern;
      }
      public void Analyze(string line) {
        rows.Add(line);
        string[] split = line.Split(this.pattern);
        int curCol = 0;
        foreach (string s in split) {
          if (s.Length > 0) {
            if (this.freq.ContainsKey(s)) {
              ++this.freq[s];
            } else {
              this.freq.Add(s,1);
            }
            this.rowLookup[s] = this.curRow;

          }
          ++curCol;
        }
        ++curRow;
      }

      void FindRow() {
        foreach (KeyValuePair<string,int> ele in this.freq) {
          if (ele.Value == 1) {
            this.solRow = this.rowLookup[ele.Key];
          }
        }
      }

      void FindCol() {
        string analyzedRow = this.rows[this.solRow];
        string checkedLine = this.pattern + this.pattern;
        int cycle = this.pattern.Length;

        bool found = false;
        string sub = analyzedRow.Substring(0, cycle);
        bool contains = checkedLine.Contains(sub);
        if (!contains) {
          found = true;
        }
        if (found) {
          for (int i = 1; i < cycle; ++i) {
           sub = analyzedRow.Substring(i, cycle);
           contains = checkedLine.Contains(sub);
            if (contains) {
              this.solCol = i-1;
              return;
            }
          }
        }
        for (int i = 1 ; i < analyzedRow.Length; ++i) {
           sub = analyzedRow.Substring(i, cycle);
           contains = checkedLine.Contains(sub);
          if (!contains) {
            this.solCol = i + cycle - 1;
            return;
          }
        }
      }

      public string GetSolution() {
        this.FindRow();
        this.FindCol();
        return $"({this.solCol},{this.solRow})";
      }
    }

    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        string pattern = Console.ReadLine();
        PatternFinder pf = new PatternFinder(pattern);
        for (int i = 0; i < N; i++)
        {
            string row = Console.ReadLine();
            pf.Analyze(row);
        }

        Console.WriteLine(pf.GetSolution());
    }
}
