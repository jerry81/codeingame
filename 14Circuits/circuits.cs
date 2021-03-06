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
    public void PrintDict(Dictionary<string, float> dictionary) {
        foreach (KeyValuePair<string, float> kvp in dictionary) {
            //textBox3.Text += ("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            Console.Error.WriteLine("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
        }
    }

    public void PrintArr(string[] arr) {
        foreach (string i in arr) {
            //textBox3.Text += ("Key = {0}, Value = {1}", kvp.Key, kvp.Value);
            Console.Error.WriteLine("item in arr is {0}", i);
        }
    }

    public void PrintStack( IEnumerable myCollection )  {
      foreach ( Object obj in myCollection )
         Console.Error.WriteLine( "item in stack is {0}", obj );
    }
}

class Solution
{

    
    static void Main(string[] args)
    {
        // make dict of circuits 
        // Create a new dictionary of strings, with string keys.
        Dictionary<string, float> resistance =
          new Dictionary<string, float>();

        // Add some elements to the dictionary. There are no
         // duplicate keys, but some of the values are duplicates.
        // resistance.Add("txt", "notepad.exe");
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            string name = inputs[0];
            int R = int.Parse(inputs[1]);
            resistance.Add(name, (float)R);
        }
        Helper h = new Helper();
        h.PrintDict(resistance);
        string circuit = Console.ReadLine();
        string[] arr = circuit.Split(' ');
        h.PrintArr(arr);
        Stack stack = new Stack();
        foreach (string item in arr) {
            string[] keywords = {"[", "("};
            if (keywords.Contains(item)) {
                stack.Push(item);
            } else if (item == ")") {
                List<float> operands = new List<float>();
                while (true) {
                    var popped = stack.Pop();
                    if (popped is string && popped as string == "(") {
                        Console.Error.WriteLine("end condition");
                        float sum = 0.0F;
                        foreach (float j in operands) {
                            sum += j;
                        }
                         Console.Error.WriteLine("sum is {0:0.0}", sum);
                         stack.Push(sum);
                        break;
                    } else if (popped is float asFloat) {
                        operands.Add(asFloat);
                    }
                }
            } else if (item == "]") {
                List<float> operands = new List<float>();
                while (true) {
                    var popped = stack.Pop();
                    if (popped is string asStr && asStr == "[") {
                      float psum = 0.0F;
                      foreach (float k in operands) {
                          float res = 1/k;
                          psum += res;
                      }
                      float quo = 1/psum;
                      stack.Push(quo);
                      break;
                    } else if (popped is float asFloat) {
                        operands.Add(asFloat);
                    }
                }
            } else {
                stack.Push(resistance[item]);
            }
        }
        h.PrintStack(stack);

        // identify series and parallels
        // simple nesting example
        // [ ( A B ) [ C A ] ]
        // split " " 
        // stacks
        /*
         [
         [,(
         [,(,AV,
         [,(,AV,BV
         [,(,AV,BV
         ) so pop until ( 
         [,AV+BV
          [,AV+BV,(
          etc..
        */

        /* complex case
( Alfa [ Charlie Delta ( Bravo [ Echo ( Foxtrot Golf ) ] ) ] )
(, Alfa, [, Charlie, Delta, (, Bravo, [, Echo, (, Foxtrot, Golf
) - pop until ( 
(, Alfa, [, Charlie, Delta, (, Bravo, [, Echo, Foxtrot+Golf
], - pop until [     -> foxtrot+golf, echo - evaluates into 1/((1/Echo)+(1/(Foxtrot+Golf))

super complex case

        */
        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");
  /* TODO: convert ints to floats when working on stack */
  /* also print the float rounded to 1 decimal pt */
        Console.WriteLine("{0:0.0}", stack.Pop());
    }
}