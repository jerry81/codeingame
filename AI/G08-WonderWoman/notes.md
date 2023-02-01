# general

- when enemy is adjacent to level 3, and i can build on it, build on it so it gets removed from play
- will need shortest paths to find shortest path to a 3
- may need some "turns to win" logic
- possible to get trapped.

# wood 3 to wood 2

- game continues after one "win"

# improvements

- current logic: random move if no move to a 3 height
- better logic - dont build on a 3 - build on a 2 - move close to a 3

1.  find best move, find best build - if no hit, then use current logic

# issues

- i don't even always grab the nearest 3 - perhaps because it was occupied and not provided as a legal move
- or b/c i could only step up 1 level
-