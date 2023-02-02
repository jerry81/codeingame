# general

- inspired by bomberman
- 11x13 grid (y,x)
- floor '.', box '0'
- players can occupy same square
- moves - move with coordinate - moves towards that position
- bomb with coordinates - place bomb immediately then move towards that cell.
- bomb - 8 round timer
- 1 bomb on grid at a time.

# improvements

- round 1
  - find squares nearby where a bomb explosion would break the most boxes
    - find highest number within 5 moves

  - bombs don't go through other boxes, so max is 4


# issues