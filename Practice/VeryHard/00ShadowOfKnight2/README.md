# trilateration

- using distances from 3 known points to a point to calculate point's location.

- doesn't help us greatly because distances are not known.

# idea

- if a jump to b gives warmer
- we can eliminate points closer to a than to b
- to flesh out: what are points closer to a than to b?
- brute force: we can plug in each possible point into the distance equation
- how do we eliminate the most amount of points at each step?

# big hint given in example

- blue squares are the possible squares
- white squares are eliminated

# picking the best square

- get average x of all unvisited squares
- get avg y of all unvisited squares
- mid x = (curx + tgtx) / 2
- tgtx = midx * 2 - curx
