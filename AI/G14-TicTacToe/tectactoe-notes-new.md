# shit is getting messy. let's start over?

- currently i have
  - all moves on the board as a map
  - a primitive ranking system where i favor middle moves, then corner moves
  - a simple win or loss checker
  - an outer game and inner game class

- what is needed to simulate?
  - a way to clone the game
  - a way to pick a random move
  - a way to check for win lose or draw

- verify one simulation -
  - verified manually.  only plays up to a won large square - further refine.
  - changed code - i think there was a bug where the big move "win" would return the inner wins.
  - however now, there is an infinite loop.  seems like there is no result from the simulation coming in
    - on successful simulations, results are 1 (opponent), and 2 (me win) -
      - first verify one of each - verify X win case
      - skip verfy O win case (tediuous)
      - investigate timeout case
        - seems fixed for now- shit - simulations seem to suspiciously return lots of DRAWS
        - address the non-randomness

- next data struct
- Selection - select all available moves
- expand the move after those


## optimizations!!

- look through the code, currently we can only run 100 simulations total with a 3 simulation increment per turn
- IGame
- OGame


- right now there is a ghetto primitive MCTS where we just simplify selection to select points equally and not expand a tree (not even keeping a tree at all) - we don't back propogate because there is no nesting.

- try a non-struct approach

