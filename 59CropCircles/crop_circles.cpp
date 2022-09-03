/*
You are an intern on an Alien spacecraft, and your job is to create "Crop-Circles".

You are assigned a Farming-Field that is planted with a crop of {}
The Farming-Field is 25 high and 19 wide. The naming convention is:
The columns are a to s
The rows are a to y

The way you are told what Crop-Circle to make is notation in the format of xyd or xydd
where:
x tells you the x coordinate of the center
y tells you the y coordinate of the center
d or dd tells you the diameter (always an integer)
For example bc13 tells you center of the circle is 2nd column, 3rd row; and the diameter is 13.
NOTE: Some Crop-Circles will not be fully in the Farming-Field, but all centers will be.
(To be clear, a circle includes its circumference.)

Mostly, Crop-Circles are made by mowing; so if no other instructions are given that's what you'll do.

However, your spacecraft is equipped with the latest technological advances in Crop-Circle creation, so you can also PLANT or PLANTMOW. Here's what that means:

PLANT = add back the {} crop to the entire circle. In other words, plant back {} as needed, so the entire area of the circle is fully planted, including spots that have already been mowed.

PLANTMOW = within a circle if a spot is planted, then mow it; if a spot is mowed, then plant it. In other words reverse it.

If you are to do either of these, the key word will be before the other part of the notation. For example: PLANTgg7 or PLANTMOWjm13

Now, go do your job, before you are transferred to the Human Probing Department or the Cattle Mutilation Division.
Input
A single string describing what Crop-Circles to make
Output
The 19-wide x 25-high Farming-Field after it has been Crop-Circled.
The only characters allowed are {} and spaces
Constraints
There will be one or more Crop-Circles
Example
Input
fg9 ls11 oe7
Output
{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
{}{}{}{}{}{}{}{}{}{}{}{}{}      {}{}{}
{}{}{}          {}{}{}{}          {}{}
{}{}              {}{}              {}
{}                  {}              {}
{}                  {}              {}
{}                  {}{}          {}{}
{}                  {}{}{}      {}{}{}
{}                  {}{}{}{}{}{}{}{}{}
{}{}              {}{}{}{}{}{}{}{}{}{}
{}{}{}          {}{}{}{}{}{}{}{}{}{}{}
{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
{}{}{}{}{}{}{}{}{}          {}{}{}{}{}
{}{}{}{}{}{}{}{}              {}{}{}{}
{}{}{}{}{}{}{}                  {}{}{}
{}{}{}{}{}{}                      {}{}
{}{}{}{}{}{}                      {}{}
{}{}{}{}{}{}                      {}{}
{}{}{}{}{}{}                      {}{}
{}{}{}{}{}{}                      {}{}
{}{}{}{}{}{}{}                  {}{}{}
{}{}{}{}{}{}{}{}              {}{}{}{}
{}{}{}{}{}{}{}{}{}          {}{}{}{}{}
{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool grid[25][19];
const string hit = "{}";
const string miss = "  ";

typedef struct p_in {
  int row;
  int col;
  int dia;
} p_in;

p_in process_input(string instruction)
{
  p_in ret;
  ret.row = instruction[0] - 97;
  ret.col = instruction[1] - 97;

  cerr <<"row is "<<ret.row<<" and col is "<<ret.col<<endl;
  return ret;
}

void print_grid()
{
  for (int i=0; i<25;++i)
  {
    for (int j=0; j<19;++j)
    {
      cerr << (grid[i][j] ? miss : hit);
    }
    cerr << endl;
  }
}

int main()
{
    string instructions;
    getline(cin, instructions);

    char *ptr; // declare a ptr pointer
    char c_s[instructions.length()+1];
    strcpy(c_s, instructions.c_str());
    ptr = strtok(c_s, " "); // use strtok() function to separate string using comma (,) delimiter.
    cout << " Split string using strtok() function: " << endl;
    while (ptr != NULL)
    {
        cout << ptr  << endl; // print the string token
        ptr = strtok (NULL, " , ");
    }
    p_in p = process_input(instructions);
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    cout << "Farming-Field with Crop-Circles" << endl;
}


/*
Strategy
representation - 0s and 1s
output with small conversion
translate input
*/