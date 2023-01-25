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
- input parsing - card loop - cardType - done
  - 0 creature
  - 1 green
  - 2 red
  - 3 blue
- necessary logic:
  - item to add or remove ability
  - match to ability
- must be able to distinguish item cards to not summon them in the attack phase

# wood1 to bronze

- 3 new abilities
  - drain - heal player according to damage dealt
  - lethal - kill creatures instantly
    - my lethals should target enemy with highest Defense
  - ward - one-time shield

- runes that can impact card draw
  - automatic

# improvements
  - wasting mana
  - no strategy
  - attack creatures and if creatures all dead, then attack mage
    - attack enemy with highest attack
  - items seem to not be being used
  - summon best candidate
    - highest possible cost given mana
  - favor drafting lowcost units

  - attacks are not balanced, everyone focuses on an enemy even if overkill

# refactor

- battle() getting a little too big.