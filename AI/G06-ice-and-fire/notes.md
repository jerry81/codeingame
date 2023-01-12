# issues

- when the unit goes all the way right, it doesn't change direction
- rotate the direction order for new units (don't all start with right)
- units just sit idly often
- when enemies come to attack, we never attack them, we only try to grab unfriendly unoccupied squares

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
