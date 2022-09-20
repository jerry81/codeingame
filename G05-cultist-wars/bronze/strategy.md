# strategy

## general

- cult leader must stay alive
- don't bother trying to convert enemy cultists unless they are next to you
- go towards neutral that are closest to leader but furthest from enemy cultists
- our cultists can start shooting the cult leader (top priority) or cultist with guns
## coding

- create an output helper - done
- represent the map - array of strings
- represent units - struct

- helper - calc manhattan distance between two objects
- be able to get closest neutral to your leader
- if Dist == 1 convert! - done

- move helper?  first check if there is an adjacent cultist - done

- sort by manhattan distances

- need optimization - not just manhattan distance, but sort by shortest path (including obstacles)

- improvement - no moves left or leader dead - use the pawns!
- helper to find if path has obstacle
- helper to find enemies in range

## TODO

- review A* pathfinding - add this later