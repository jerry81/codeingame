- NOTE  new additions are tower type and giant unit type - giants break down towers 

1.  still must implement production strategy for picking knights/archers - done 
  - if no enemy knights on board - build knight - done 
  - if enemy knights on board, build archer - done 

2.  limit the buildings to one of each type - first build knight rax then archer rax then tower  - done 
  - refactor - build seperate arrays for each building type - done
  - change game loop logic - build archer tower if it doesn't exist
  - build knight tower if it doesn't exist 

3.  when idle, have the queen stay behind towers - done

- new strategy works great but did lose to one person 
  - he agressively built barracks everywhere including into my base 
  - make the archer threshold higher - allow archers to outnumber enemy knights 

- observation - if the enemy rushes knights at the beginning, while building the first tower, i lose lots of health 