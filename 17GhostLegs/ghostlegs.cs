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
    private void PrintArr(string[] arr) {
        foreach (string i in arr) {
            //textBox3.Text += ("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            Console.Error.WriteLine("item in arr is {0}", i);
        }
    } 
    private char findEnd(char start, string[] lines) {
      Console.Error.WriteLine("start is {0}", start);
      return '1';
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
            Console.Error.WriteLine("i is {0}", i);
            char start = lines[0][i];
            char end = s.findEnd(start, lines);

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");
            Console.Error.WriteLine("end is {0}", end);
            // Console.WriteLine("{0}{1}",start,end);
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

       //  Console.WriteLine("{0}{1}",start,end);
    }
}