using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        
        byte[] letters = null; // bytes and chars, interchangable?
        string[] numbers = null; // good variable names 
        string[] lines = new string[H - 2];
        
        string lettersLine = Console.ReadLine().Replace(" ", ""); // simplification, nice. 
        letters = new byte[lettersLine.Length];
        for (int i = 0; i < letters.Length; i++)
        {
            letters[i] = (byte)lettersLine[i]; // casts char to byte 
        }
        
        for (int i = 1; i < H - 1; i++)
        {
            lines[i - 1] = Console.ReadLine();
        }
        
        string numbersLine = Console.ReadLine().Replace(" ", "");
        numbers = new string[numbersLine.Length];
        for (int i = 0; i < numbers.Length; i++)
        {
            numbers[i] = numbersLine[i].ToString();
        }

        int evolution = 0; // what 
        int targetCheck = 0;
        int numberIndex = 0;
        
        for (int i = 0; i < letters.Length; i++)
        {
            targetCheck = i * 3;
            evolution = targetCheck / 3;
            numberIndex = evolution;
            if (numberIndex > 0) numberIndex--;
            
            for (int j = 0; j < lines.Length; j++)
            {
                char checker = lines[j][targetCheck];
                
                if (targetCheck - 1 > 0 && lines[j][targetCheck - 1] == '-')
                {
                    targetCheck -= 3;
                    evolution = targetCheck / 3;
                }
                else if (targetCheck + 1 < lines[j].Length && lines[j][targetCheck + 1] == '-')
                {
                    targetCheck += 3;
                    evolution = targetCheck / 3;
                }
            }
            
            string result = ((char)letters[i]).ToString() + numbers[evolution];
            Console.WriteLine(result);
        }
    }
}