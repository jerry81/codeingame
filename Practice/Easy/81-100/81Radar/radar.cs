

using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    class Radar {
          const int DIST = 13;
          const int SPEED_LIMIT = 130;
          const long MS_IN_HOUR = 1000*60*60;
          const string R1 = "A21-42";
          const string R2 = "A21-55";
          int numberOfPlates;
          SortedDictionary<string, long> R1Lookup = new SortedDictionary<string,long>();
          SortedDictionary<string, long> R2Lookup = new SortedDictionary<string,long>();

          public Radar(int number) {
            this.numberOfPlates = number;
          }

          public void AddReading(string plate, string radar, long timestamp) {
            if (radar == R1) {
              R1Lookup.Add(plate, timestamp);
            } else {
              R2Lookup.Add(plate, timestamp);
            }
          }

          private int getSpeed(string plate) {
            long time1 = R1Lookup[plate];
            long time2 = R2Lookup[plate];
            long diff = time2 - time1;
            double hours = (double)diff/(double)MS_IN_HOUR;
            int speed = (int)((double)DIST/hours);
            return speed;
          }

          public List<string> FindTickets() {
            List<string> tickets = new List<string>();
            foreach (var v in R1Lookup) {
              int speed = getSpeed(v.Key);
              if (speed > SPEED_LIMIT) {
                tickets.Add($"{v.Key} {speed}");
              }
            }
            return tickets;
          }
        }

    static void Main(string[] args)
    {


        int N = int.Parse(Console.ReadLine());
        Radar r = new Radar(N);
        for (int i = 0; i < N; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            string plate = inputs[0];
            string radarname = inputs[1];
            long timestamp = long.Parse(inputs[2]);
            r.AddReading(plate, radarname, timestamp);
        }
        List<string> answer = r.FindTickets();

        foreach (var a in answer) {
          Console.WriteLine(a);
        }

    }
}