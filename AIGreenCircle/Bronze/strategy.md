# leftovers
- just started playing skill card logic 

# new feature
- applications may be bigger
- 2 skills lost each time you "pass go" (7 to 0)
- MOVE now has new option MOVE {place} {card to take} 
  - if your reach has increased 

# new strategy
- minimize number of times you pass go - just grab the next available desk that doesn't "disturb"

- delayed release (build draw/discard with architecture farming)

- PLAY_CARD phase
- Prioritize the play_cards (descending) - done

- further optimize continuous integration and task prioritization 
  - continuous integration - prioritize most in-demand requirements - done 
    - list all continuous integration possibilities - done 
      - pm is ('CONTINUOUS_INTEGRATION 8', True) 
      - pm is ('CONTINUOUS_INTEGRATION 3', True) 
    - get map of requirements - already automated  - done
  - task prioritization - if possible trade bonus for skills (giving priority to best skills)
    - possible moves parsing - done 
    - add up the "effective" cards 
      - DRAW + DISCARD + AUTOMATED
    - make map of required
    - prioritize trading bonus card for most required 


- minimize damage from THROW - done 

# fixes

- first add the missing enums - card locations - done 