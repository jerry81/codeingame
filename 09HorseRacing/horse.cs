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
            if (i == 1) {
                smallest = Math.Abs(pi - numbers[0]);
                Console.Error.WriteLine("smallest is " + smallest);
            } else {
                for (int j = 0; j < i; j++) {
                    int newSmallest = Math.Abs(numbers[j] - pi);
                    if (smallest > newSmallest) {
                      smallest = newSmallest;
                    }
                }
            }
        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine(smallest);
    }
}