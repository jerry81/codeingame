- step 1: get your own location simple case - 1 starting point 
- step 2: find multiple locations - done 
- step 3: keep track of towers built 
- goal: build a map like the following
- towers = { 0 => { 0 => true }, 3 => { 1 => true, 12 => true } } 
- this means (0,0) (3,1) and (3,12) all have towers 
- step 4: add helper - find paths in a given column - done


- fix - towers update the map itself from the towers game loop - done
- step 5: change the first step to saturate the center column with towers
- 5a.  helper to check if a column is saturated
- b.  helper to build a string to output 
- c.  helper to build output array saturate a column (or just convert isSaturated)
- d.  replace first step with saturating the middle 


-  fix - the map updating code is not correct



- new strat - centralize y when building in center 
- start mixing in glue towers- 
- introduce upgrade logic
- if no more no more items to saturate, then upgrade

- unfortunately a path that is very high or low y on the map performs terribly as i will always try to
- place from the top down - fixed this by centralizing building priority 


- on first step - 
- grab the squares with 6+ surrounding paths first and put fire towers there.


- limit to 1 glue tower 

- build a heatmap of all canyons (#) and the number of adjacent paths each has 
- while the current heat map makes it easy to lookup by location, it is not suited to sort.
- flatten the heat map to store x and y as props 

- test first step logic - build fire tower at hottest spots

- next, adapt the first step into general strategy
  - on every step - try to grab the hottest spots and put guntowers there

- for very hot spots, build flame towers 
- tower counting on each turn 

- when attack towers double glue towers, add a glue, limit 2

- put more limits on tower building and 
- also let's limit our total tower count to - 
- currently, a lot of money is wasted because we stopped building towers at some point
- find out when we stop building towers 


- now we need a strategy to optimally stick some glue towers in
- right now, in an infinite loop, we build flames and guns
- we can count number of towers of each type

-  upgrade logic goes here 

-  upgrade priority goes by the sfil list 

-  focus on the top 3 towers 

-  we need to find id by location 

- lost to a player who just spammed gun towers everywhere 
- i ended up with no firetowers 

- lost to another guntower spammer 
- he spams, never upgrades, and tries to centralize a bit 
- we could filter out the ends of the map 

- played the top ranked opponent 
- he starts with a flame, glue, and 2 guns at my base 
- his towers are much more consolidated - 3 towers for the entire game

- on first turn he tries to build firetower on the hottest square on my side since it fails,
- next turn he builds fire tower on my side in the next hottest square 
- he then builds a glue tower next to the fire tower
- then he builds a gun tower next to it
- he then upgrades damage on the firetower 
- he then spams upgrade on the top two towers 

- in a different run
- he builds the fire+glue combo upgrading the fire
- it seems like he patches guns whenever an attacker leaks thru in order to never miss gold 

- reintroduce the starting position logic 
- build from enemy base 
- build off of existing towers 
- can have a strategy for specific towers
  - first tower - fire, hottest spot near enemy base 


- now we have a sorted list of spots for the first tower based on neighbors and distance from the enemy
- next build the first fire tower 

- major weakness found with my plan
  - if there is a split path, i may end up building on one of the split paths 

- thought i fixed the weakness but then encountered another bad case: 
- the convergence was never found 

- convergence logic wrong
- instead should follow each path and look for the fork 
- fork happens when a path nsew neighbors > 2 

- another big issue, when the convergence is in the center of the board, it doesn't build anything at all 

- money not being spent because the upgrade candidates list is too filtered 