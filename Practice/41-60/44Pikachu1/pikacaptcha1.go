package main

import (
	"fmt"
	// "os"
    "strconv"
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
		var newarr = make([][]rune, height)
		for i := 0; i < height; i++ {
			newarr[i] = make([]rune, width)
	  }


    for i := 0; i < height; i++ {
        for j := 0; j < width; j++ {
					up := i - 1
                    down := i + 1
					left := j - 1
					right := j + 1
					cnt := 0
					// ch := string(lines[i][j])
					if up >= 0 {
						if string(lines[up][j]) == "0" {
							// fmt.Fprintln(os.Stderr, "up detected")
							cnt += 1
						}
					}
					if down < height {
						if string(lines[down][j]) == "0" {
							cnt += 1
						}
					}
					if left >= 0 {
						if string(lines[i][left]) == "0" {
						  cnt += 1
						}
					}
					if right < width {
						if string(lines[i][right]) == "0" {
						  cnt += 1
						}
					}
                    // fmt.Fprintln(os.Stderr, "cnt is ", cnt)
					if string(lines[i][j]) == "#" {
					  newarr[i][j] = rune('#')
					} else {
                        asStr := strconv.Itoa(cnt)

					    newarr[i][j] = []rune(asStr)[0]
                        // fmt.Fprintln(os.Stderr, "newarr is now ", newarr)
				  }
				}

    }
                for i := 0; i < height; i++ {
					fmt.Println(string(newarr[i]))
				}  // Write action to stdout
}