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

 class SiblingSorter : IComparer<string>
   {
      private Dictionary<string, RTNode> family_lookup = new Dictionary<string, RTNode>();

      public SiblingSorter(Dictionary<string, RTNode> fl) {
        family_lookup=fl;
      }

      public int Compare(string x, string y)
      {
          RTNode rx = family_lookup[x];
          RTNode ry = family_lookup[y];
          if (rx.death != "-" && ry.death == "-") return 1;

          if (rx.death == "-" && ry.death != "-") return -1;

          if (rx.gender == "M" && ry.gender == "F")return -1;

          if (rx.gender == "F" && ry.gender == "M") return 1;

          if (rx.birth == ry.birth) return 0;

          return (rx.birth < ry.birth) ? -1 : 1;

      }
   }

  Dictionary<string, RTNode> family_lookup = new Dictionary<string, RTNode>();

  string root;

  public void SetLength(int length) {
    len = length;
  }

  private void traverseR(string cur) {
    RTNode curR = family_lookup[cur];
    if (curR.death == "-" && curR.religion != "Catholic") Console.WriteLine(cur);
    List<string> c = curR.children;
    foreach (var child in c) {
      traverseR(child);
    }
  }

  public void Traverse() {
    traverseR(root);
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
      SiblingSorter ss = new SiblingSorter(family_lookup);
      family_lookup[parent].children.Sort(ss);
    }
  }

  public void PrintTree() {
    foreach (var entry in family_lookup)
    {
       string key = entry.Key;
       RTNode value = entry.Value;
      Console.Error.WriteLine($"key: {key}, parent: {value.parent}");
        foreach (var child in value.children) {
           Console.Error.WriteLine($"child is: {child}");
        }
      // if (value.death == "-" && value.religion != "Catholic") Console.WriteLine(key);
    }
    Console.Error.WriteLine($"Root is {root}");
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
        // rt.PrintTree();
        rt.Traverse();
        // Write an answer using Console.WriteLine()
        // To debug: Console.Error.WriteLine("Debug messages...");

        // Console.WriteLine("orDeroFsucceSsion");
    }
}

/*

KingGeorgeVI - 1895 1952 Anglican M
QueenElizabethII KingGeorgeVI 1926 - Anglican F
CharlesPrinceofWales QueenElizabethII 1948 - Anglican M
PrinceWilliamDukeofCambridge CharlesPrinceofWales 1982 - Anglican M
PrinceGeorgeofCambridge PrinceWilliamDukeofCambridge 2013 - Anglican M
PrincessCharlotteofCambridge PrinceWilliamDukeofCambridge 2015 - Anglican F
PrinceHenryofWales CharlesPrinceofWales 1984 - Anglican M
PrinceEdwardEarlofWessex QueenElizabethII 1964 - Anglican M
PrinceAndrewDukeofYork QueenElizabethII 1960 - Anglican M
PrincessBeatriceofYork PrinceAndrewDukeofYork 1988 - Anglican F
PrincessEugenieofYork PrinceAndrewDukeofYork 1990 - Anglican F
JamesViscountSevern PrinceEdwardEarlofWessex 2007 - Anglican M
LadyLouiseWindsor PrinceEdwardEarlofWessex 2003 - Anglican F
AnnePrincessRoyal QueenElizabethII 1950 - Anglican F
PeterPhillips AnnePrincessRoyal 1977 - Anglican M
SavannahPhillips PeterPhillips 2010 - Anglican F
IslaPhillips PeterPhillips 2012 - Anglican F
ZaraTindall AnnePrincessRoyal 1981 - Anglican F
MiaTindall ZaraTindall 2014 - Anglican F
PrincessMargaretCountessofSnowdon KingGeorgeVI 1930 2002 Anglican F
DavidArmstrong-Jones2ndEarlofSnowdon PrincessMargaretCountessofSnowdon 1961 - Anglican M
CharlesArmstrong-JonesViscountLinley DavidArmstrong-Jones2ndEarlofSnowdon 1999 - Anglican M
LadyMargaritaArmstrong-Jones DavidArmstrong-Jones2ndEarlofSnowdon 2002 - Anglican F
LadySarahChatto PrincessMargaretCountessofSnowdon 1964 - Anglican F
SamuelChatto LadySarahChatto 1996 - Anglican M
ArthurChatto LadySarahChatto 1999 - Anglican M


QueenElizabethII
CharlesPrinceofWales
PrinceWilliamDukeofCambridge
PrinceGeorgeofCambridge
PrincessCharlotteofCambridge
PrinceHenryofWales
PrinceAndrewDukeofYork
PrincessBeatriceofYork
PrincessEugenieofYork
PrinceEdwardEarlofWessex
JamesViscountSevern
LadyLouiseWindsor
AnnePrincessRoyal
PeterPhillips
SavannahPhillips
IslaPhillips
ZaraTindall
MiaTindall
DavidArmstrong-Jones2ndEarlofSnowdon
CharlesArmstrong-JonesViscountLinley
LadyMargaritaArmstrong-Jones
LadySarahChatto
SamuelChatto
ArthurChatto
SEND TO IDE
04 Non anglican people

*/