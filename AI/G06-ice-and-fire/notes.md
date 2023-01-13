# issues

- when the unit goes all the way right, it doesn't change direction
- rotate the direction order for new units (don't all start with right)
- units just sit idly often
- when enemies come to attack, we never attack them, we only try to grab unfriendly unoccupied squares
- no mining
  - check if there are minable squares
- no filtered data structures make for longer searches
  - refactor - more "specific" data structures (friendly units, level 1 units, mines, hqs)
    - friendly/enemy units  (done)
    - level 1/2/3 units (done, dont feel like it helps much)
    - mines/hqs (done)
    - unit counts and limits
      - counts helpers - done

- no pathfinding
  - add shortest path to point from target method
- units should always have a goal and not be idle
  - level 1 units, the scouts, should be grabbing the closest unoccupied square not targeted by another level 1)  need shortest paths to find the closest unoccupied square
  - level 2 units should hunt enemy level 1 units
  - level 3 units should defend mines and hq and defend against enemy level 3 units

# wood 3 to wood 2

- can build level 2 and 3 units
- level 1 cannot kill any units, and have no upkeep
- level 2 can kill level 1, and costs 4 upkeep, 20 to recruit
- level 3 costs 30, costs 20 upkeep, and can kill any unit
- new action: TRAIN {2/3} x y

# wood 2 to wood 1

- can build mines
- built only on mines
  - provided by a seperate loop (not on the map)
- new action: BUILD MINE x y
- build mines whenever friendly unit is on mine (done)
- destroy enemy mines
