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
- don't place the item if it has no crowns.