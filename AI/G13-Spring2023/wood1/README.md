Each cell has a type, which indicates what the cell contains:
0 if it does not contain a resource.
1 if it contains the egg resource.
2 if it contains the crystal resource.

The harvesting chains work the same way for the egg resource.

Harvesting an egg cell will spawn as many ants as resources havested. The ants will spawn on the player’s base on the start of next turn.

6 neigh variables, one for each direction, containing the index of a neighboring cell or -1 if there is no neighbor.