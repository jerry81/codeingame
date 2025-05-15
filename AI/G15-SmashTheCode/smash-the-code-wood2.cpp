#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>  // For random number generation

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    // Create a random device
    random_device rd;
    // Create a Mersenne Twister random number generator
    mt19937 gen(rd());
    // Create a uniform distribution
    uniform_int_distribution<> distrib(min, max);
    // Generate and return the random number
    return distrib(gen);
}

int main()
{

    // game loop
    while (1) {
        for (int i = 0; i < 8; i++) {
            int color_a; // color of the first block
            int color_b; // color of the attached block
            cin >> color_a >> color_b; cin.ignore();
        }
        int score_1;
        cin >> score_1; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row; // One line of the map ('.' = empty, '0' = skull block, '1' to '5' = colored block)
            cin >> row; cin.ignore();
        }
        int score_2;
        cin >> score_2; cin.ignore();
        for (int i = 0; i < 12; i++) {
            string row;
            cin >> row; cin.ignore();
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << getRandomNumber(0,5) << endl; // "x": the column in which to drop your blocks
    }
}