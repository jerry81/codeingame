/*

 	The Goal
You need to help the clones reach the exit in order to help them escape the inside of the Improbability Drive.
 	Rules
The drive has a rectangular shape of variable size. It is composed of several floors (0 = lower floor) and each floor has several possible positions that the clones can occupy (0 = leftmost position, width - 1 = rightmost position).

The goal is to save at least one clone in a limited amount of rounds.

The details:
Clones appear from a unique generator at regular intervals, every three game turns. The generator is located on floor 0. Clones exit the generator heading towards the right.

Clones move one position per turn in a straight line, moving in their current direction.

A clone is destroyed by a laser if it is goes below position 0 or beyond position width - 1.

Elevators are scattered throughout the drive and can be used to move from one floor to the one above. When a clone arrives on the location of an elevator, it moves up one floor. Moving up one floor takes one game turn. On the next turn, the clone continues to move in the direction it had before moving upward.

On each game turn you can either block the leading clone - meaning the one that got out the earliest - or do nothing.

Once a clone is blocked, you can no longer act on it. The next clone in line takes the role of "leading clone" and can be blocked at a later time.

When a clone moves towards a blocked clone, it changes direction from left to right or right to left. It also changes direction when getting out of the generator directly on a blocked clone or when going up an elevator onto a blocked clone.

If a clone is blocked in front of an elevator, the elevator can no longer be used.

When a clone reaches the location of the exit, it is saved and disappears from the area.

Note: For this puzzle there is at most one elevator per floor.


Victory Conditions
You win if at least one clone reaches the exit location in a limited amount of game rounds
 	Note
Don’t forget to run the tests by launching them from the “Test cases” window.

The tests provided are similar to the validation tests used to compute the final score but are slightly different.
 	Game Input
The program must first read the initialization data from standard input. Then, within an infinite loop, read the contextual data (location of leading clone) from the standard input and provide the next instruction to standard output.
Initialization input
Line 1: 8 integers:
nbFloors : number of floors in the area. A clone can move between floor 0 and floor nbFloors - 1
width : the width of the area. The clone can move without being destroyed between position 0 and position width - 1
nbRounds : maximum number of rounds before the end of the game
exitFloor : the floor on which the exit is located
exitPos : the position of the exit on its floor
nbTotalClones : the number of clones that will come out of the generator during the game
nbAdditionalElevators : not used for this first question, value is always 0
nbElevators : number of elevators in the area
nbElevators next lines: 2 integers elevatorFloor elevatorPos providing the floor and position of an elevator.
Input for one game turn
Line 1: 2 integers cloneFloor clonePos and one string direction. cloneFloor and clonePos are the coordinates of the leading unblocked clone. direction indicates the current direction of the leading clone:
LEFT the clone is moving towards the left
RIGHT the clone moving towards the right
If there is no leading clone, the line values are: -1 -1 NONE. This can happen only when the clones which are already outside are all blocked and the next clone is not out yet. In this case, you may output action WAIT.
Output for one game turn
A single line (including newline character) to indicate which action to take:
Either the keyword WAIT to do nothing.
or the keyword BLOCK to block the leading clone.
Constraints
1 ≤ nbFloors ≤ 15
5 ≤ width ≤ 100
10 ≤ nbRounds ≤ 200
0 ≤ exitFloor, elevatorFloor < nbFloors
0 ≤ exitPos , elevatorPos < width
-1 ≤ cloneFloor < nbFloors
-1 ≤ clonePos < width
2 ≤ nbTotalClones ≤ 50
0 ≤ nbElevators ≤ 100
Duration of one game turn: 100 ms

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int nb_floors; // number of floors
    int width; // width of the area
    int nb_rounds; // maximum number of rounds
    int exit_floor; // floor on which the exit is found
    int exit_pos; // position of the exit on its floor
    int nb_total_clones; // number of generated clones
    int nb_additional_elevators; // ignore (always zero)
    int nb_elevators; // number of elevators
    unordered_map<int, int> elevators_map;

    cin >> nb_floors >> width >> nb_rounds >> exit_floor >> exit_pos >> nb_total_clones >> nb_additional_elevators >> nb_elevators; cin.ignore();
    for (int i = 0; i < nb_elevators; i++) {
        int elevator_floor; // floor on which this elevator is found
        int elevator_pos; // position of the elevator on its floor
        cin >> elevator_floor >> elevator_pos; cin.ignore();
        elevators_map[elevator_floor] = elevator_pos;
    }

    // game loop
    while (1) {
        int clone_floor; // floor of the leading clone
        int clone_pos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> clone_floor >> clone_pos >> direction; cin.ignore();

        // special case: exit floor

        int c_elevator_position = elevators_map[clone_floor];
        if (clone_floor == exit_floor) {
          c_elevator_position = exit_pos;
        }
        if (direction == "RIGHT") {
          // handle right
          if (clone_pos > c_elevator_position) {
            cout << "BLOCK" << endl;
            continue;
          }
        } else {
          // handle left
          if (clone_pos < c_elevator_position) {
            cout << "BLOCK" << endl;
            continue;
          }
        }
        cout << "WAIT" << endl; // action: WAIT or BLOCK
    }
}