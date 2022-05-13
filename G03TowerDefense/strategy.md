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