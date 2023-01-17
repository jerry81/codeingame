# done
- no pathfinding
  - add shortest path to point from target method (done)
  - level 2 units should hunt enemy level 1 units (done)
- no filtered data structures make for longer searches
  - refactor - more "specific" data structures (friendly units, level 1 units, mines, hqs)
    - friendly/enemy units  (done)
    - level 1/2/3 units (done, dont feel like it helps much)
    - mines/hqs (done)
    - unit counts and limits
      - counts helpers - done

- when enemies come to attack, we never attack them, we only try to grab unfriendly unoccupied squares (fixed)

- no mining
  - check if there are minable squares - done


- when the unit goes all the way right, it doesn't change direction (done)

 - rule update: mines built on if owned and not occupied!
    - build if owned (done)
    - move unit away if on friendly mine that hasn't been built

- new action: BUILD MINE x y
- build mines whenever friendly unit is on mine (done)

- the nested unordered_maps used as Point hash table are terrible
  - refactor it (done)

- we run out of money
  - only build lvl 3 units if enemy has level 2 or level 3 units. (done)


- shortest paths doesn't take into account obstacles.
  - canuseinpath helper (done)

  - level 3 units should kill enemy units and never walk to a square adjacent to a level 3 enemy unit
    - helper - is adjacent to level3 enemy unit (done)
    - kill priority (done)

- level 1 units - prioritize unexplored mines
  - helper: isUnexploredMine (done)
  - use the helper
# issues

- units just sit idly often
- units should always have a goal and not be idle
  - level 1 units, the scouts, should be grabbing the closest unoccupied square not targeted by another level 1)  need shortest paths to find the closest unoccupied square
    - use shortest paths for level 1 units?

  - level 3 units should defend mines and hq and defend against enemy level 3 units

- level 3 units not moving (fixed)
- units dont capture the enemyhq!

# wood 3 to wood 2

- can build level 2 and 3 units
- level 1 cannot kill any units, and have no upkeep
- level 2 can kill level 1, and costs 4 upkeep, 20 to recruit
- level 3 costs 30, costs 20 upkeep, and can kill any unit
- new action: TRAIN {2/3} x y

- build level 2 units - already have 5 level 1, have enough money, limit 3.
  - build level 2 and 3 (done)
  - level 2 units should find enemy level 1 units mostly


# wood 2 to wood 1

- can build mines
- built only on mines
  - provided by a seperate loop (not on the map)
- destroy enemy mines

# wood 1 to bronze

- new command BUILD TOWER x y
- towers only destroyed by lvl 3 units
- towers protect friendly cells adjacent (non-diagonal)
- towers cost 15 gold

# other improvements

- economy management
  - don't send unnecessary commands
    - if money limited, prioritize.
      - get unbuilt viable mines helper
      - top priority: build unbuilt viable mines
      - second priority: build level 1 units
      - third priority: build level 2 units
      - fourth priority: build level 3 units.


- on wood 1, we get overwhelmed by the number of l1 units that the "night boss" creates
  - our unit counts are limited
  - our units are idle

- tower tracking
  - store towers - done
  - if enemy has tower then allow l3 unit - done
  - l3 unit target towers priority - done
  - l1 and l2 units avoid tower protected squares
  - enemy towers and their controlled squares should not be considered for l1 and l2 units' paths

- tower building

- refactor anything that uses a point to use a point

- prioritize taking mines


# observations

- built towers on chokepoints
- running out of money still an issue
- when unit has no path it may block other possibly more useful units
- in a long game, the enemy built lots of towers