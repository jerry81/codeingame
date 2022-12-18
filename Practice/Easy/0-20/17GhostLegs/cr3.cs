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
        List<string> inputs = Console.ReadLine().Split(' ').ToList();
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        
        inputs = Console.ReadLine().Split("  ").ToList();
        
        List<int> inputIndices = inputs.Select( (v, i) => i ).ToList();
        
        Console.Error.WriteLine( inputs.Aggregate( "", (current, next) => current += next + "  " ) );
        
        for (int i = 1; i < H-1; i++)
        {   
            string line = Console.ReadLine();
            
            Console.Error.WriteLine(line);
            
            string[] connections = line.Remove(0, 1).Remove(line.Length-2).Replace(" ", "").Split('|');
            
            //Console.Error.WriteLine( connections.Aggregate("Connections: ", (current, next) => current += next + ", " ) );
            
            for (int j=0 ; j<connections.Length ; j++)
            {
                if ( connections[j] == "--" )
                {
                    int tmpInput = inputIndices[j];
                    inputIndices[j] = inputIndices[j+1];
                    inputIndices[j+1] = tmpInput;
                }
            }
            Console.Error.WriteLine( inputIndices.Aggregate("", (current, next) => current += inputs[next]+"  " ) );
        }
        
        List<string> outputs = Console.ReadLine().Split("  ").ToList();
        Console.Error.WriteLine( outputs.Aggregate( "", (current, next) => current += next + "  " ) ); // usage of a lambda, aggregate on list

        // this is c#'s accumulator function like reduce  

        // Write an action using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");
        
        for (int i=0 ; i<outputs.Count ; i++)
        {
            Console.WriteLine( inputs[i]+outputs[inputIndices.IndexOf(i)] );
        }
    }
}