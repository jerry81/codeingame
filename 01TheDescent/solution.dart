import 'dart:io';
import 'dart:math';

String readLineSync() {
  String? s = stdin.readLineSync();
  return s == null ? '' : s;
}

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
void main() {

    // game loop
    while (true) {
        int max = 0;
        int maxi = -1;
        for (int i = 0; i < 8; i++) {
            int mountainH = int.parse(readLineSync()); // represents the height of one mountain.
            if (mountainH > max) {
              max = mountainH;
              maxi = i;
            }
        }

        // Write an action using print()
        // To debug: stderr.writeln('Debug messages...');

        print(maxi); // The index of the mountain to fire on.
    }
}