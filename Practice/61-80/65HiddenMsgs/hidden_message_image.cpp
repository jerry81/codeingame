/*
Goal
Steganography in images is to hide information in pixels of images imperceptibly to the human eye. In this problem there are ASCII messages hidden in the image pixels. More specifically, the least significant bit of each pixel represents a piece of the ASCII message.

Every 8 consecutive bits we have a byte, convert that byte into an ASCII value. To make your life easier, images will always have a number of pixels multiple of 8. Print all ASCII characters extracted from the image.

Example
Given an input image with width = 4 and height = 4
106 19 134 22
161 192 98 184
52 51 97 88
208 63 58 25

106 => 01101010 => less significant bit => 0
19 => 00010011 => less significant bit => 1
134 => 10000110 => less significant bit => 0
22 => 00010110 => less significant bit => 0
161 => 10100001 => less significant bit => 1
192 => 11000000 => less significant bit => 0
98 => 01100010 => less significant bit => 0
184 => 10111000 => less significant bit => 0
52 => 00110100 => less significant bit => 0
51 => 00110011 => less significant bit => 1
97 => 01100001 => less significant bit => 1
88 => 01011000 => less significant bit => 0
208 => 11010000 => less significant bit => 0
63 => 00111111 => less significant bit => 1
58 => 00111010 => less significant bit => 0
25 => 00011001 => less significant bit => 1

Extracted bits => 0100100001100101
Split binary information into bytes => [ "01001000", "01100101"]
Map bytes to ASCII => ["H", "e"]

Output => He
Input
Line 1: Two integers w, h for the dimensions of the image.
Next h lines: w space separated integers for the pixels of the image.
Output
ASCII message extracted from the image
Constraints
8 ≤ w,h ≤ 50
w*h % 8 == 0
Example
Input
8 12
220 251 30 182 233 122 150 30
132 101 135 212 246 201 128 203
62 33 39 70 73 175 218 140
44 165 9 140 83 67 34 100
142 75 125 242 49 175 209 37
252 26 123 6 186 72 230 94
218 85 228 205 146 67 219 187
194 159 81 190 51 235 41 121
208 33 245 71 172 218 97 130
122 31 135 198 135 249 174 28
162 109 149 216 156 195 140 10
100 252 1 164 150 22 144 109
Output
Hello World!
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

string int_to_bin_string(int i) {
}

int least_sig(string bin_string) {
}

vector<string> bin_str_to_byte_strs(string bin_string) {
}

char byte_str_to_ascii(string byte) {
}

void test_helpers() {
  string res1 = int_to_bin_string(5);
  cerr << "expect 101 " << res1 << endl;
  int res2 = least_sig("101");
  cerr << "expect 1 " << res2 << endl;
  vector<string> res3 = bin_str_to_byte_strs("0100100001100101");
  cerr << "expect 01001000 " <<  res3.at(0) << endl;
  cerr << "expect 01100101 " <<  res3.at(1) << endl;
  char res4 = byte_str_to_ascii("01001000");
  cerr << "expect H " << res4 << endl;
}

int main()
{
    test_helpers();
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int pixel;
            cin >> pixel; cin.ignore();
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "answer" << endl;
}

/*
  int to binary string helper
  least sig bit helper
  split to byte helper
  byte to ascii helper
*/