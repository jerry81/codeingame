package main

import (
	"fmt"
	"os"
)

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

func main() {
    var width, height int

    fmt.Scan(&width, &height)
    var lines [][]rune // this is slice

    for i := 0; i < height; i++ {
        var line string
        fmt.Scan(&line)
				chars := []rune(line) // :- is declaration plus assignment
        lines = append(lines, chars)
    }
    for i := 0; i < height; i++ {
        fmt.Fprintln(os.Stderr, "i is ", i, "line[i] is ", lines[i])
        fmt.Println("#####")// Write action to stdout
    }
}