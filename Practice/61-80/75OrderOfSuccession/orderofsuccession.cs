/*

	Goal
You have to output the order of succession to the British throne of a list of given people.
The order is simple:
From a descendant A, the next in the order is A’s first child B.
Then, the next one is B’s first child C if any and so on.
If C has no child, then the next one is B’s second child D.
Then D’s children if any. Then B’s third child E… then A’s second child F…

Let’s draw it with a tree:

      A1
    ┌─┴─┐
    B2  F6
 ┌──┼──┐
 C3 D4 E5


You see the order of succession: begin on the left of the tree, walk to the next level whenever possible otherwise continue to the right. Repeat until the whole tree is covered.
Thus, the order is A-B-C-D-E-F.

In fact, in siblings of the same person, the male descendants are ordered before the female descendants. For example, if the order of birth of the children (M for male, F for female) is Fa Ma Me Fe then the order of succession in these siblings is Ma Me Fa Fe.

Ordering rules
(a) in order of generation
(b) in order of gender
(c) in order of age (year of birth)

Outputting rules
(a) exclude dead people (but include siblings of dead people)
(b) exclude people who are catholic (but include siblings of catholic people)

Note that this puzzle has been written in June, 2017 (some people might have died since this date).
Input
Line 1: The number of people n
Next n lines: Name Parent Year of birth Year of death Religion Gender

If the people is not dead then the year of death is replaced by the hyphen -.
Output
One name per line, in the order of succession to the throne: first the Queen, then all her descendants.
Constraints
Exactly one people does not have a parent (the parent’s name is replaced by the hyphen -).
No two siblings of the same gender of a person have the same year of birth.
1 ≤ n ≤ 100
Example
Input
6
Elizabeth - 1926 - Anglican F
Charles Elizabeth 1948 - Anglican M
William Charles 1982 - Anglican M
George William 2013 - Anglican M
Charlotte William 2015 - Anglican F
Henry Charles 1984 - Anglican M
Output
Elizabeth
Charles
William
George
Charlotte
Henry

*/

using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

// can we assume first item is alwasy the root?
class RoyalTree {
  private int len;

  private struct RTNode {
    public string name;
    public string parent;
    public int birth;
    public string death;
    public string religion;
    public string gender;

    public List<string> children;
  };

  Dictionary<string, RTNode> family_lookup = new Dictionary<string, RTNode>();

  string root;

  public void SetLength(int length) {
    len = length;
  }

  public void AddPerson(
    string name,
    string parent,
    int birth,
    string death,
    string religion,
    string gender) {
    RTNode person;
    person.children=new List<string>();
    person.name = name;
    person.parent = parent;
    person.birth = birth;
    person.death = death;
    person.religion = religion;
    person.gender = gender;
    family_lookup[name] = person;
    if (parent == "-") {
      root = name;
    } else {
      family_lookup[parent].children.Add(name);
    }
  }

  public void PrintTree() {
    foreach (var entry in family_lookup)
 {
 string key = entry.Key;
 RTNode value = entry.Value;
 // Do something here
   Console.Error.WriteLine($"key: {key}, parent: {value.parent}");
 }
  }
}
class Solution
{
    static void Main(string[] args)
    {
        RoyalTree rt = new RoyalTree();
        int n = int.Parse(Console.ReadLine());
        rt.SetLength(n);
        for (int i = 0; i < n; i++)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            string name = inputs[0];
            string parent = inputs[1];
            int birth = int.Parse(inputs[2]);
            string death = inputs[3];
            string religion = inputs[4];
            string gender = inputs[5];
            rt.AddPerson(name,parent,birth,death,religion,gender);
        }
        rt.PrintTree();

        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        Console.WriteLine("orDeroFsucceSsion");
    }
}