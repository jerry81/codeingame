# readme


This is a league based challenge.

For this challenge, multiple versions of the same game are available. Once you have proven your skills on this first version, you will access a higher league and extra rules will be unlocked.
 	The Goal
Tic-tac-toe is a turn-based game, where the objective is to get three in a row.
 	Rules
The game is played on a 3x3 grid. You must output the coordinate of the cell you want to mark. The first player to get 3 of their mark in a row (vertically, horizontally or diagonally) wins.

You can download the source code of this game on GitHub. You can create your own game using the CodinGame SDK!

 	Game Input
Input for one game turn
Line 1: 2 space separated integers opponentRow and opponentCol, the opponent's last action (-1 -1 for the first turn).
Line 2: the number of valid actions for this turn, validActionCount.
Next validActionCount lines: 2 space separated integers row and col, the coordinates you're allowed to play at.
Output for one game turn
Line 1: 2 space separated integers row and col.
Constraints
Response time for first turn ≤ 1000ms
Response time for one turn ≤ 100ms

What is in store for me in the higher leagues?

The extra rules available in higher leagues are:
Next game will be played on 9 tic-tac-toe boards!

## montecarlo tree search

- got its name from casino, therefore expect gambling themes
- used by deepmind's alphago!
- make a tree
- root node of tree is current state of game
- leaf node - node haven't explored all possible moves yet

- four steps
1.  selection
  - select child of root that is most promising
  - balance
    - explore new moves
    - exploit known good moves
2.  expansion
  - at leaf node, add more child nodes (more possible moves)
3.  simulation
  - after the exapansion simulate a game that took those moves
4.  back propagation
  - update "stats" of nodes based on results of simulation

- repeated on a limited time frame or number of iterations
- tree gradually grows, nodes have stats - choose child with highest "stats"

- in tic tac toe, the game tree is the possible moves at a turn, then the next possible moves at the next turn

## minimax

## Terms

- UCB1 - upper confidence bound for node Vi + 2 * sqrt(ln(N) / ni)
  - Vi - avg reward/value  of all nodes beneath node
  - N - number of times the parent node has been visited
  - ni - times child node visited
  - (very confusing)

- Rollout - randomly choosing actions at each step until leaf node reached.
```
while true
  if Si is leaf
    return value(Si)
  Ai = random(available_actions(Si))
  Si = Simulate(Si,Ai)
```

- algorithm
  - current node NOT leaf node then
    - calc ucb1 and choose node that maximizes UCB
    - recurse
  - current node is leaf node then
    - keep track of # of times sampled.
    - never sampled before -> rollout
    - sampled before -> add new state to tree for each action (expansion)
      - rollout frmo this new node

- example
- tree, no stats
- a
- b c

1.  selection - pick b or c (both have infinite UCB), take b
- at b
2.  expansion? - b not visited, skip
3.  simulation - rollout to terminal state - get a "value", 20
4.  back propagation - go back up tree to root(inclusive), update values for nodes (value (success) and times visited)

iteration 2

- a (20,1)
- b (20,1) c (0,0)

1.  selection - c has infinite UCB take c
2.  expansion skip
3.  Simulate -> find value 10
4.  back prop - go up tree - root now 30?  so additive?

- a (30,2)
- b (20,1) c(10,1)

iteration 3

1. b higher than c
2. expansion applies because b has been visited
  - each possible move from here becomes node
- a (30,2)
- b (20,1) c(10,1)
- d, e
  - pick d (not visited, inf val, equal to e)
3. simulate
  - lets say it gets value 0
4. back prop

- a (30,3)
- b (20,2) c(10,1)
- d(), e


## TODO

1.  random moves - done
  - wth, this gets me to bronze lol
2.  bronze league updates
  - update struct, win, and move
  - new struct, OGame, IGame - done
  - IGame basically same as before - done
    - new state to determine whose square it is. - done
    - IGame may update its status after each move
  - OGame has nested IGames - done
    - move - get a val y,x where y is 0..8 and x is 0..8 - done
    - 0-2 -> 0 3-5 -> 1 6-8 -> 2
    - win -> check states - done
2a.  some "smart" functions
  - add a "winning move" checker
    - but there is a big board win and small board win
    - small board win easy - done
    - big board win - easy done
    - big board preview small board win? - done
      - need a preview move function? - done
    - tested, this doesn't work.  debug.
      - print shit out!  print inner grid - done
      - fixed and ranking went up - done
      - wow did not expect silver!
3.  code to simulate a game
  - start with a single iteration!
  - we see "death moves" where we make a move on one board that loses another board.
  - how do we detect this?
    - look ahead one move
      - but to do this we should clone a game state for "experimentation"
  - include a timer function
  - we have vec of remaining moves we can makes - this will be shared between players

## Promotion to bronze

- now it is 9x9 board
- your move determines which board can be played on next (unless board already completed)