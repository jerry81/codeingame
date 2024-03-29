/*
	Goal
Given a string S of length N find the minimum number of characters that you need to add to the end in order to make S a palindrome.
Example:
N=4 and S='ABCB' we can add 'A' to the end of S making it a valid palindrome (ABCBA). Thus, the answer is 1.
Input
Line 1: N an integer denoting the length of the string.
Line 2: S the string.
Output
An integer denoting the minimum number of charcters to add at the end to transform the string into a palindrome
Constraints
1<N<10000
S contains only uppercase characters.
Example
Input
4
ABCB
Output
1
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
    class Palindrome {
      string palindrome;
      int len;
      public Palindrome(string s, int len) {
        this.palindrome = s;
        this.len = len;
      }

      string curForward = "";
      string curBackwards = "";

      public bool IsPalindrome(char c) {
        curForward = curForward+c;
        curBackwards=c+curBackwards;
        return curForward==curBackwards;
      }

      private int GetLongestPalindrome() {
        int longest = 0;
        for (int i = this.len-1; i >= 0; --i) {
          char c = this.palindrome[i];
          if (IsPalindrome(c)) {
            longest = this.len-i;
          }
        }
        return longest;
      }

      public int GetSolution() {
        return len - this.GetLongestPalindrome();
      }
    }

    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();
        Palindrome p = new Palindrome(s, n);
        int ans = p.GetSolution();
        Console.WriteLine(ans);
    }
}