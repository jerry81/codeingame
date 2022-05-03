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
	var boosted bool = false
    for {
		
        // nextCheckpointX: x position of the next check point
        // nextCheckpointY: y position of the next check point
        // nextCheckpointDist: distance to the next checkpoint
        // nextCheckpointAngle: angle between your pod orientation and the direction of the next checkpoint
        var x, y, nextCheckpointX, nextCheckpointY, nextCheckpointDist, nextCheckpointAngle int
        fmt.Scan(&x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle)
        
        var opponentX, opponentY int
        fmt.Scan(&opponentX, &opponentY)
        
        
        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
		fmt.Fprintln(os.Stderr, "nextCheckpointDist is ", nextCheckpointDist)
        var thrust = "100";
        if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90) {
            thrust = "0"
        }
		if (nextCheckpointDist < 2000) {
			thrust = "75"
		}
		if (nextCheckpointDist < 1000) {
			thrust = "50"
		}
		if (nextCheckpointDist > 10000 && nextCheckpointAngle == 0 && !boosted) {
			thrust = "BOOST";
			boosted = true
		}
		// boost on last straightaway 
		
        fmt.Printf("%d %d %s\n", nextCheckpointX, nextCheckpointY, thrust)
    }
}