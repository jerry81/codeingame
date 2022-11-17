/*

Goal
In this simplified version of "Card Counting", you are playing Blackjack at a casino table that uses only one standard deck of 52 cards.

Fortunately, you have an amazing memory and incredible math skills.
Unfortunately, you are easily distracted and there's a lot going on.

Your streamOfConsciousness is what you observe intermingled with your thoughts.
Each thought or observation (separated by a period .) might be a series of cards or something else. It is a series of cards if it consists solely of valid cards; see abbreviations used below.

With your knowledge of all the observed cards, calculate the percentageChance (rounded to the nearest whole number) that the value of the next card will be less than the bustThreshold.
(The bustThreshold is what would make your hand "go-bust"/lose by going over 21. It isn't anything you need to calculate; it is provided.)

Abbreviations used, and values:
• K = King
• Q = Queen
• J = Jack
• T = Ten
(each of the above has a value of 10)
• A = Ace (has a value of 1)
• Each number card (2 through 9, inclusive) has its own face value

Examples:
• JT7A44 means: a Jack, a Ten, a 7, an Ace, and two 4s
• JAKE might be your buddy, but it's not a series of cards, since "E" isn't a valid abbreviation
• AT&T might be your cell-service provider, but it's not a series of cards, since "&" isn't a valid abbreviation
• T1 might be a data/telecom line, but it's not a series of cards, since "1" isn't a valid abbreviation
Input
Line 1: a string streamOfConsciousness
Line 2: an integer bustThreshold
Output
Line 1: an integer percentageChance%
Constraints
2 ≤ bustThreshold ≤ 10
Example
Input
222.333.444.some distraction.555.5.678.678.678.678.another distraction.9999.TTTT.JJJJ.QQQQ.KKKK.AAAA
4
Output
67%

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
    class Deck {
      int over;
      int under;
      int thresh;

      public Deck(int thresh) {
        this.under = (thresh-1) * 4;
        this.over = 52 - this.under;
        this.thresh = thresh;
      }

      public int ParseStream(string stream) {
        foreach (char c in stream) {
          Console.Error.WriteLine($"c is {c}");
          if (c == 'A') {
            --this.under;
            continue;
          }
          if (c == 'K') {
            --this.over;
            continue;
          }
          if (c == 'Q') {
            --this.over;
            continue;
          }
          if (c == 'J') {
            --this.over;
            continue;
          }
          if (c == 'T') {
            --this.over;
            continue;
          }
          int as_i = c - '0';
          if ((as_i > 1) && (as_i < 10)) {
            if (as_i < this.thresh) {
              --this.under;
            } else {
              --this.over;
            }
          }
        }
        Console.Error.WriteLine($"before division under: {this.under} over: {this.over}");
        float prob = (this.under / (this.under+this.over));
        Console.Error.WriteLine($"after division {prob}");
        return 0;
      }
    }

    static void Main(string[] args)
    {
        string streamOfConsciousness = Console.ReadLine();
        int bustThreshold = int.Parse(Console.ReadLine());
        Deck d = new Deck(bustThreshold);
        d.ParseStream(streamOfConsciousness);
        Console.Error.WriteLine($"testAscii 2 is {'2' - '0'} 9 is {'9' - '0'}");
        Console.WriteLine("percentageChance%");
    }
}
