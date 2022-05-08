using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    private char findEnd(char start, string[] lines, int startIdx, int w) {
      int curX = startIdx;
      int curY = 1;
      char curChar = lines[curY][curX];
      while (curChar == '|') {
        int lx = curX - 1;
        int rx = curX + 1;
        if (lx > 1) {
          char leftC = lines[curY][lx];
          if (leftC == '-') {
              curX -= 3;
              curY += 1;
              curChar = lines[curY][curX];
              continue;
          }
        }
        if (rx < (w - 2)) {
          char rightC = lines[curY][rx];
          if (rightC == '-') {
              curX += 3;
              curY += 1;
              curChar = lines[curY][curX];
              continue;
          }
        }
        curY += 1;
        curChar = lines[curY][curX];
      }
      return curChar;
    }

    static void Main(string[] args)
    {
        Solution s = new Solution();
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        string[] lines = new string[H];
        for (int i = 0; i < H; i++)
        {
            string line = Console.ReadLine();
            lines[i] = line;
        }

        for (int i = 0; i < W; i+=3) {
            char start = lines[0][i];
            char end = s.findEnd(start, lines, i, W);
            Console.WriteLine("{0}{1}",start,end);
        }
    }
}