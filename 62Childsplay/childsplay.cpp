/*
Goal
For several years now, in elementary schools, we have seen the emergence of a new educational model, playful programming. The students must program a small robot using assembly blocks. This allows them to get familiar with programming from an early age while exercising their logic and perception of space.

You are a student at one such school. The purpose of the exercise is simple: your teacher has crafted a circuit for your robot, told you how many moves n the robot may make, and you must find out the final position of the robot at end of execution.

To do this you need to know some principles of robot operation.
– When the robot encounters an obstacle (represented by #) it turns right (on same operation) until there's no obstacle ahead anymore. Otherwise on an empty area (represented by .) it moves straight ahead.
– The robot initially moves upwards.
– The robot stops after n moves.
– The top left corner represents the coordinates (0,0)
– The robot's environment is represented as follows, where O is the robot's initial position:
...#........
...........#
............
............
..#O........
..........#.
Input
¤ Width w and height h of the map.
¤ Number n of operations to be performed by the robot
¤ The map where the robot moves with . representing a free space, # an obstacle and O the starting position.
Output
¤ The final position x y (separated by a space) of the robot at end of execution, where x is the horizontal position and y is the vertical position.
Constraints
¤ 0 < w <= 20
¤ 0 < h <= 10
¤ The obstacles are placed in such a way that the robot will never leave the map
¤ The robot will never be blocked between obstacles
¤ n < 2^53
Example
Input
12 6
987
...#........
...........#
............
............
..#O........
..........#.
Output
7 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Point {
  int x;
  int y;
};
int main()
{
    int w;
    int h;

    cin >> w >> h; cin.ignore();
    // init grid
    string grid[h];
    Point start;
    long long n;
    cin >> n; cin.ignore();
    for (int i = 0; i < h; i++) {
        string line;
        getline(cin, line);
        grid[i] = line;
        for (int j = 0; j < w; j++) {
          if (line[j] == 'O') {
            cerr << "start found " << endl;
            start.x = j;
            start.y = i;
          }
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}