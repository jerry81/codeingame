- NOTE  new additions are tower type and giant unit type - giants break down towers 

1.  still must implement production strategy for picking knights/archers - done 
  - if no enemy knights on board - build knight - done 
  - if enemy knights on board, build archer - done 

2.  limit the buildings to one of each type - first build knight rax then archer rax then tower 
  - refactor - build seperate arrays for each building type - done
  - change game loop logic - build archer tower if it doesn't exist
  - build knight tower if it doesn't exist 

3.  when idle, have the queen stay behind towers 
