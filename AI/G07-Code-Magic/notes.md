# wood 3 to wood 2

- creatures now have abilities
- some cards increase HP
- some cards draw additional cards at beginning of next turn when played
- some cards start w/ certain abilities
- effect player's health opponents health or card draw
- abilities
  - breakthru - extra damage when they attack enemy creatures
  - charge - attack the turn they are summoned
  - guard - enemies forced to attack creatures with guard first

# wood 2 to wood 1

- item cards now unlocked
  - have effects and are removed after being played
    - buff/debuff
    - exstra draws
    - health effects
    - add or remove abilities
  - green, red, blue
    - green friendly buffs
    - red - debuffs
    - blue - wizard targeted
  - new command USE id1 id2
  - new command USE id -1
- input parsing - card loop - cardType
  - 0 creature
  - 1 green
  - 2 red
  - 3 blue
- must be able to distinguish item cards to not summon them in the attack phase