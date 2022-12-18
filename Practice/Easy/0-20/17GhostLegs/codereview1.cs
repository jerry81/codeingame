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
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        // initialize containers
        int[] currentPos = new int[(int) (W + 2) / 3]; // (ME: he consolidates the array?)
        for (int i = 0; i < currentPos.Length; i++)
        {
            currentPos[i] = i;
        }
        char[] top = new char[currentPos.Length]; // me: arrays for top and bottom 
        char[] bottom = new char[currentPos.Length];
        // manage top
        string line = Console.ReadLine();
        for (int j = 0; j < currentPos.Length; j++)
        {
            top[j] = line[j*3]; // this is kind of nice...
        }
        // manage path
        for (int i = 1; i < H - 1; i++)
        {
            line = Console.ReadLine();

            for (int j = 0; j < currentPos.Length; j++) // he uses for instead of while to increment y, good.
            {
                int left = currentPos[j] * 3 - 1; 
                int right = currentPos[j] * 3 + 1;
                if (left >= 0 && line[left] == '-') // this is better than nesting conditionals 
                    currentPos[j] = currentPos[j] - 1;
                else if (right < W && line[right] == '-')   
                    currentPos[j] = currentPos[j] + 1;
            }
        }
        // manage bottom
        line = Console.ReadLine();
        for (int j = 0; j < currentPos.Length; j++)
        {
            bottom[j] = line[j*3];
        }
        // display result
        for (int i = 0; i < currentPos.Length; i++)
            Console.WriteLine($"{top[i]}{bottom[currentPos[i]]}");
    }
}