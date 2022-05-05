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
        // make dict of circuits 
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            string name = inputs[0];
            int R = int.Parse(inputs[1]);
        }
        string circuit = Console.ReadLine();
        // identify series and parallels
        // simple nesting example
        // [ ( A B ) [ C A ] ]
        // split " " 
        // stacks
        /*
         [
         (
           A
           B
          ) - can evaluate value
          left with 
          [
            val 
           (
           C
           A
           ) - evaluate value 2
           remaining [ val value2 
           ]
           evaluate 
        */
        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("Equivalent Resistance");
    }
}