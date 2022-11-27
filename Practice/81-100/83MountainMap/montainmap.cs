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
      int height = 0;
      int width = 0;
      List<int> mountains = new List<int>();
      List<List<char>> output = new List<List<char>>();

      public void ProcessMountain(int ht) {
        mountains.Add(ht);
        if (ht > this.height) {
          this.height = ht;
        }
        this.width+=2*ht;
      }

      void setupDraw() {
        for (int i = 0; i < this.height; ++i) {
          this.output.Add(new List<char>());
          for (int j = 0; j < this.width; ++j) {
            this.output[i].Add(' ');
          }
        }
      }

      void Render() {
        foreach (var o in this.output) {
          Console.WriteLine(new string(o.ToArray()));
        }
      }

      public void Draw() {
        this.setupDraw();
        int i = 0;
        foreach (int m in this.mountains) {
          for (int j = 0; j < m; ++j) {
            this.output[j][j+i] = '/';
            this.output[j][j+i+m] = '\\';
          }
          i+=(m*2);
        }
        this.Render();
      }
    }

    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine()); // the number of mountains
        Mountains m = new Mountains();
        string[] inputs = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            int height = int.Parse(inputs[i]);// height of the mountain
            m.ProcessMountain(height);
        }
        m.Draw();

    }
}