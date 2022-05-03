/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


// game loop
let checkpointsX = []
let checkpointsY = []
let curCX, curCY
while (true) {
    var inputs = readline().split(' ');
    const x = parseInt(inputs[0]);
    const y = parseInt(inputs[1]);
    const nextCheckpointX = parseInt(inputs[2]); // x position of the next check point
    const nextCheckpointY = parseInt(inputs[3]); // y position of the next check point
    if (checkpointsX.length == 0) {
        checkpointsX.push(nextCheckpointX)
        checkpointsY.push(nextCheckpointY)
        curCX = nextCheckpointX
        curCY = nextCheckpointY
    }
    let iX = checkpointsX.indexOf(nextCheckpointX) 
    console.error('nextCheckpointX', nextCheckpointX)
    console.error('checkpointsX', checkpointsX)
    if (iX < 0) {
        checkpointsX.push(nextCheckpointX)
        checkpointsY.push(nextCheckpointY)
    }
    if (iX == 0 && checkpointsY.indexOf(nextCheckpointY) == 0) {
        console.error('lapped')
    }
    const nextCheckpointDist = parseInt(inputs[4]); // distance to the next checkpoint
    const nextCheckpointAngle = parseInt(inputs[5]); // angle between your pod orientation and the direction of the next checkpoint
    var inputs = readline().split(' ');
    const opponentX = parseInt(inputs[0]);
    const opponentY = parseInt(inputs[1]);

    // Write an action using console.log()
    // To debug: console.error('Debug messages...');
    let thrust = '100'
    if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90) {
        thrust = "0"
    }
    // You have to output the target position
    // followed by the power (0 <= thrust <= 100) or "BOOST"
    // i.e.: "x y thrust"
    console.log(nextCheckpointX + ' ' + nextCheckpointY + ' ' + thrust);
}
