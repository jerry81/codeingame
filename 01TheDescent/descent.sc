import math._
import scala.util._
import scala.io.StdIn._

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
object Player extends App {

    // game loop
    while(true) {
        var mx = 0
        var mi = -1
        for(i <- 0 until 8) {
            val mountainH = readLine.toInt // represents the height of one mountain.
            if (mountainH > mx) {
                mx = mountainH 
                mi = i
            }
        }
        
        // Write an action using println
        // To debug: Console.err.println("Debug messages...")
        
        println(mi) // The index of the mountain to fire on.
    }
}