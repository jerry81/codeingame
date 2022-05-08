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
        List<string> result = new List<string>(); // list instead of array 
        char[,] map; // ooh new syntax - this means two dimensional array 
        
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        
        map = new char[H,W];
        
        for (int i = 0; i < H; i++)
        {
            string line = Console.ReadLine();
            
            for(int j = 0; j < W; j++)
            {
                map[i,j] = line[j]; // more 2d array magic 
            }
        }

        //Traitement  // me, what?
        for(int j = 0; j < W; j++)
        {
            int currentIndex = j;
            
            if(map[0,j] == ' ')
                continue;
              
            for(int i = 0; i < H; i++) // nested for, no good 
            {
                if(i == 0)
                    continue;                
            
                if(i == H-1)
                {
                    result.Add(string.Format("{0}{1}",map[0,currentIndex],map[i,j]));
                    j = currentIndex;
                }

                if(j != 0 && map[i,j-1] == '-')   // cool, no curly brackets           
                    j-=3;                
                else if(j != W-1 && map[i,j+1] == '-')                      
                    j+=3;
            }
        }
        
        foreach(string s in result)
            Console.WriteLine(s); // could have just printed it inside the above loop
    }
}