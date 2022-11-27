/*

	Goal
The task here is to print the ASCII representation of n mountains where the height of each mountain is given.
Input
Line 1: an integer n for the number of mountains
Line 2: n space-separated integers for the height of each mountain
Output
An ASCII representation of the mountain where each rise in the mountain is represented by '/' and fall by '\'
(Output lines shall not contain trailing spaces)
Constraints
0<n<15
0<height<15
(every mountain's base starts on the bottom-most line)
Example
Input
3
1 2 1
Output
   /\
/\/  \/\

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
    class Mountains {
      int count;
      int height;
      int width;
      List<int> mountains = List<int>();
      List<List<char>> mountains = new List<List<char>>();
      public Mountains(int n) {
        this.count = n;
      }

      public void ProcessMountain(string mountain) {

      }
    }

    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine()); // the number of mountains
        string[] inputs = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            int height = int.Parse(inputs[i]);// height of the mountain
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("answer");
    }
}