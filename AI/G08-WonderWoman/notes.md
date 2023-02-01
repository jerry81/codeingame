# general

- when enemy is adjacent to level 3, and i can build on it, build on it so it gets removed from play
- will need shortest paths to find shortest path to a 3
- may need some "turns to win" logic
- possible to get trapped.

# wood 3 to wood 2

- game continues after one "win"

# improvements

- current logic: random move if no move to a 3 height - done
- better logic - dont build on a 3 - build on a 2 - move close to a 3 - done

1.  find best move, find best build - if no hit, then use current logic

- detect trap and don't walk into it
  - snapshot of grid
  - temp: grid state after move and build
  - count movable squares
- detect trap for opponent and trap him!

- easiest way to do this is put a failsafe in the "random move" code
  - don't make a move that traps me
  - don't make a build on a 3 height
  - make the least bad move

# issues

- i don't even always grab the nearest 3 - perhaps because it was occupied and not provided as a legal move
- or b/c i could only step up 1 level

- big:  logic issue - the build calculation should be considering the position after the move

- getting better, but still building on 3 squares