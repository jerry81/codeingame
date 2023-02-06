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

- timing for bombs - don't poop before you get to the pot.
- don't wait around for bomb to explode before moving to next ideal spot .

# issues

# jumped from wood 3 to bronze

- bombs kill players
- up to 4 players
- multiple bombs can be placed.
- after all boxes destroyed, play continues

# new improvements

- don't get killed by bombs