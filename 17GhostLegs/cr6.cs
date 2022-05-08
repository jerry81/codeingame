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
        string labels = Console.ReadLine().Replace(" ", string.Empty);
        var outputs = labels.Select((x, y) => new { x, y }).ToDictionary(x => x.x, y => y.y);
        for (int i = 0; i < H - 2; i++)
        {
            string line = Console.ReadLine().Replace("|", string.Empty);
            var numberOfConnections = (int)(line.Length / 2);
            for (int j = 0; j < numberOfConnections; j++)
            {
                if (line.Substring(j * 2, 2) == "--")
                {
                    var el = outputs.First(x => x.Value == j);
                    var el2 = outputs.First(x => x.Value == j + 1);
                    var t = el.Value;
                    outputs[el.Key] = el2.Value;
                    outputs[el2.Key] = t;
                }
            }
        }

        var numbers = Console.ReadLine().Replace(" ", string.Empty);
        foreach (var str in outputs)
        {
            Console.WriteLine(str.Key + "" + numbers[str.Value]);
        }
    }
}