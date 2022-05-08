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
public class Helper 
{
   public void PrintArr(string[] arr) {
        foreach (string i in arr) {
            //textBox3.Text += ("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            Console.Error.WriteLine("item in arr is {0}", i);
        }
    }  
}
class Solution
{
    static void Main(string[] args)
    {
        Helper h = new Helper();
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        string[] lines = new string[H];
        for (int i = 0; i < H; i++)
        {
            string line = Console.ReadLine();
            lines[i] = line;
        }

        h.PrintArr(lines);

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("answer");
    }
}