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
public class Helper {
    public void PrintDict(Dictionary<string, int> dictionary) {
        foreach (KeyValuePair<string, int> kvp in dictionary) {
            //textBox3.Text += ("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            Console.Error.WriteLine("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
        }
    }

    public void PrintArr(string[] arr) {
        foreach (string i in arr) {
            //textBox3.Text += ("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            Console.Error.WriteLine("item is {0}", i);
        }
    }
}
class Solution
{

    
    static void Main(string[] args)
    {
        // make dict of circuits 
        // Create a new dictionary of strings, with string keys.
        Dictionary<string, int> resistance =
          new Dictionary<string, int>();

        // Add some elements to the dictionary. There are no
         // duplicate keys, but some of the values are duplicates.
        // resistance.Add("txt", "notepad.exe");
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            string name = inputs[0];
            int R = int.Parse(inputs[1]);
            resistance.Add(name, R);
        }
        Helper h = new Helper();
        h.PrintDict(resistance);
        string circuit = Console.ReadLine();
        string[] arr = circuit.Split(' ');
        h.PrintArr(arr);
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