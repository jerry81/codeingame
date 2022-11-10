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
class LogicGraph {
  Dictionary<string, List<string>> neighbors = new Dictionary<string, List<string>>();
  bool traverse(string start, string end) {
    string cur = start;
    while (true) {
      if (cur == end) return true;
      if (!neighbors.ContainsKey(cur) || neighbors[cur].Count == 0) return false;

      cur = neighbors[cur][0];
    }
  }
  public bool AddEntry(string row) {
    string[] sa = row.Split(" > ");
    if (neighbors.ContainsKey(sa[0]) && neighbors.ContainsKey(sa[1])) {
      if (traverse(sa[1], sa[0])) return false;
    }

    if (!neighbors.ContainsKey(sa[0])) {
      neighbors.Add(sa[0], new List<string>());
      neighbors[sa[0]].Add(sa[1]);
    }

    if (!neighbors.ContainsKey(sa[1])) {
      neighbors.Add(sa[1], new List<string>());
    }

    return true;
  }
}

class Solution
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        LogicGraph lg = new LogicGraph();
        for (int i = 0; i < n; i++)
        {
            string row = Console.ReadLine();
            if (!lg.AddEntry(row)) {
              Console.WriteLine("contradiction");
              return;
            };
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("consistent");
    }
}

/*
  store dictionary of Lists of Letters NodeToNeighbors

  helper -> traverse(start, searchfor)

  for each item pair a, b
    if a and b don't exist
      - create a: [b]
      - create b: []
    if a exists but not b
      -  a neighbors << b
      - create b: []
    if b exists but not a
      - create a: [b]
      - b do nothing
    if both exist
      traverse(b,a)
      if false then a.neighbors << b
*/