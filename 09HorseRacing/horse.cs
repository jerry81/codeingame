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
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        int[] numbers = new int[N];
        int smallest = 9000;
        for (int i = 0; i < N; i++)
        {
            int pi = int.Parse(Console.ReadLine());
            numbers[i] = pi;
        }
        Array.Sort(numbers);
        for (int i = 0; i < N-1; i++) {
          int a = numbers[i];
          int b = numbers[i+1];
          if (Math.Abs(a-b) < smallest) {
              smallest = Math.Abs(a-b);
          }
        }
        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine(smallest);
    }
}