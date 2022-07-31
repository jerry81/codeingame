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
		newarr := lines
    for i := 0; i < height; i++ {
        for j := 0; j < width; j++ {
					up := i - 1
          down := i + 1
					left := j - 1
					right := j + 1
					cnt := 0
					ch := string(lines[i][j])
					if up >= 0 {
						if string(lines[up][j]) == '0' {
							cnt += 1
						}
					}
					if down < height {
						if string(lines[down][j]) == '0' {
							cnt += 1
						}
					}
					if left >= 0 {
						if string(lines[i][left]) == '0' {
						  cnt += 1
						}
					}
					if right < width {
						if string(lines[i][right]) == '0' {
						  cnt += 1
						}
					}
					if string(lines[i][j]) == '#' {
					  newarr[i][j] = '#'
					} else {
						newarr[i][j] = string(cnt)
				  }
				}
        fmt.Println("#####")// Write action to stdout
    }
}