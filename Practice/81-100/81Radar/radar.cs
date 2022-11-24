/*
	Goal
The NGR company experiments next generation radars.
They plan to place some plate readers on the road and calculate speed by elapsed time between two points.
For testing, they put two plate readers on the A21. One at km 42 called A21-42 and One at km 55 called A21-55.
The distance between them is 13km.

Find and report all cars over 130km/h with their plate sorted alphabetically.

Timestamp is the number of milliseconds elapsed since January 1, 1970.
All speed value will be truncated to integer. ( 137.89 -> 137 )
Input
Line 1: Integer N: Scanned Plate Count
Next N lines: Plate Radarname Timestamp separated by space
Output
Plate Speed separated by space, ordered alphabetically by Plate.
Constraints
10 < N < 1000
Example
Input
20
FH-790-HH A21-42 1620040132000
ET-318-NQ A21-42 1620040623000
BV-670-GV A21-42 1620040665000
FH-790-HH A21-55 1620040747000
DV-046-YY A21-42 1620040839000
ET-318-NQ A21-55 1620041044000
BV-670-GV A21-55 1620041071000
FZ-792-EC A21-42 1620041284000
DV-046-YY A21-55 1620041326000
FZ-792-EC A21-55 1620041633000
BP-301-UL A21-42 1620041863000
BV-047-TT A21-42 1620042133000
BP-301-UL A21-55 1620042487000
BV-047-TT A21-55 1620042570000
FT-918-CZ A21-42 1620042842000
DZ-507-JZ A21-42 1620043072000
DF-857-ZR A21-42 1620043398000
FT-918-CZ A21-55 1620043609000
DZ-507-JZ A21-55 1620043803000
DF-857-ZR A21-55 1620043835000
Output
FZ-792-EC 134
*/

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
        class Radar {
          private const int DIST = 13;
          private const int SPEED_LIMIT = 130;
          private const long MS_IN_HOUR = 1000*60*60;
          private int numberOfPlates;
          public Radar(int number) {
            this.numberOfPlates = number;
          }
          public void AddReading(string plate, string radar, long timestamp) {
          }
          public string FindTickets() {
            return "";
          }
        }

        int N = int.Parse(Console.ReadLine());
        Radar r = new Radar(N);
        for (int i = 0; i < N; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            string plate = inputs[0];
            string radarname = inputs[1];
            long timestamp = long.Parse(inputs[2]);

        }

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("ticket");
    }
}