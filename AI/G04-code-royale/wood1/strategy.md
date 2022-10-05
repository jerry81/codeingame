# TODO strategy 

- observation - if the enemy rushes knights at the beginning, while building the first tower, i lose lots of health 

# NOTE NEW RULES

Can now build mines to gather gold quicker 
new structure_type 0 -> gold mine 
"BUILD {siteId} MINE" to build 
- mine upgraded by ussing same build command - limit to 5 
- the free 10 gold per turn is no more!


- trial run with existing code 

1.  incorporate mines - done 
  - setup the data structures - done 
  - build order - archer, 2 mines, knight, tower, 1 mine 
  - test how long it takes to upgrade a mine fully - fast
  - upgrade mine fully (the upgrades never deteriorate) before leaving - done 
2.  improve mine logic - done 
  - when the mine is exhausted and the queen goes back to build a mine, it automatically gets destroyed
  - don't build mine if the site's gold has been exhausted 
3.  fix issue - if the queen doesn't detect that the mine she just built is touching she skips away 


- lost to someone who spammed mines 