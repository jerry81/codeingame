# instructions

## wood 4

- tiles are dominos with two squares
  - corn, forest, grassland, lake, wetland, mine
  - square may have crown
  - tile has ID
    - larger ID usually means better value

- actions:
  - PUT a tile on territory
  - PICK a tile they will play next turn

- grid 13x13
  - ours is the first
- 13 sets of 2 chars char 1 - terrain type
    - _ empty
    - * castle
    - c corn field
    - f forest
    - g grassland
    - l lake
    - w wetland
    - m mine
  - char 2 - crown number (0 to 3)

- input line: tileId, firstSquare, secondSquare, playerId, curent

- each turn write PUT x y rotation
  - rotation: 0,1,2,3 - right, below, left, above
and then PICK tileId

# immediate easy improvements

- fill in the remaining vertical line
- pick items with more total crowns. - done
- don't place the item if it has no crowns. - this was not a good strategy due to the "connected land mass" multiplier
  - reverted to always keep building but with optimized picks.

# harder improvements
- the multiplier works by connecting same exact land type and ensuring there are crowns on at least one of the squares in the land mass
- finally understand:  must go for bigger "areas"

- picking
  - favor pure "terrain type" tiles.
  - favor terrain that we have most of
  - easy beginnings - can focus on one terrain type.
    - decision at each turn: extend the terrain or discard the tile.

- build larger "islands"
  - find islands of a land type
  - find possible tiles to place that would extend the land type.
# wood 3

- new stipulations?
  - cannot put a tile on top of another..
- same code should work as well .
  - only 4 people in this league lol