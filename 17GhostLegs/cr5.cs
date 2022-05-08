using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Graph
{
    List<string> topLabels, botLabels;
    List<List<char>> connections;
    List<int> connectedToIndexes;
    List<int> labelIndexes;
    int W, H, labelCount;
    
    public Graph(int W, int H, List<string> lines)
    {
        labelIndexes = new List<int>();
        for (int i = 0; i < lines[0].Length; i++)
            if (lines[0][i] != ' ')
                labelIndexes.Add(i);
        
        this.W = W;
        this.H = H;
        topLabels = lines[0].Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries).ToList();
        labelCount = topLabels.Count();
        botLabels = lines[H - 1].Split(new char[]{' '}, StringSplitOptions.RemoveEmptyEntries).ToList();
        connections = new List<List<char>>();
        foreach (var unused in topLabels)
        {
            List<char> connection = new List<char>();
            connections.Add(connection);
        }
        for (int i = 1; i < H - 1; i++)
        {
            string line = lines[i];
            int index = 0;
            
            if (line[1] == '-')
                connections[index].Add('R');
            else
                connections[index].Add('0');
            index++;
                
            for (int j = 1; j < W - 1; j++)
                if (line[j] == '|')
                {
                    if (line[j-1] == '-')
                        connections[index].Add('L');
                    else if (line[j+1] == '-')
                        connections[index].Add('R');
                    else
                        connections[index].Add('0');
                    index++;
                }
            
            if (line[W - 2] == '-')
                connections[index].Add('L');
            else
                connections[index].Add('0');
        }
    }
    
    public void SetConnections()
    {
        connectedToIndexes = new List<int>();
        for (int i = 0; i < labelCount; i++)
            connectedToIndexes.Add(GetConnection(i));
    }
    
    public void DisplayConnections()
    {
        for (int i = 0; i < labelCount; i++)
            Console.WriteLine(topLabels[i] + botLabels[connectedToIndexes[i]]);
    }
    
    private int GetConnection(int labelIndex)
    {
        for (int i = 0; i < connections[0].Count; i++)
        {
            if (connections[labelIndex][i] != '0')
            {
                if (connections[labelIndex][i] == 'R')
                    labelIndex++;
                else
                    labelIndex--;
            }
        }
        return labelIndex;
    }
}

class Solution
{
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        int W = int.Parse(inputs[0]);
        int H = int.Parse(inputs[1]);
        
        List<string> lines = new List<string>();
        
        for (int i = 0; i < H; i++)
            lines.Add(Console.ReadLine());

        Graph graph = new Graph(W, H, lines);
        graph.SetConnections();
        graph.DisplayConnections();
    }
}