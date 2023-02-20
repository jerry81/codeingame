# rules

- 4 players

- each turn has 4 actions
  - recruitment
  - pay
  - development
  - sales

- recruitment
  - types of employees
    - developers, sellers, managers
  - limitations
    - hire/fire 1 manager
    - more managers means more devs/sellers that can be recruited in a turn
    - total employee count under 10*total managers
    - try to stay under 4emps/1manager

- pay - keep in the green

- development
  - assign developers to
    - features
    - bugs

- sales
  - can only sell if at least 10 features


# strategy

## first phase

- hire devs first (4 to 1)
- cap the hiring
- assign half to maintenence
- when features > 10
- start hiring sellers/manager
- cap the hiring

- observing AI:
  1. first turn, 2 devs, 1 mgr, 1 dev to maintenence
  2. 4 devs, 1 mgr, 3 to maintenence
  3. 6 devs, 1 mgr, 6 to maintenence
  4. 8 sellers, 1 mgr, 6 maintenence, 4 competitiveSellers
  5.  0 hires, 8 maintenence, 4 competitive sellers

- now our reputation is up, but unlike the AI we don't keep expanding the business.

- market:
  - market share can be stolen by higher rep competitor from lower rep
  - income dependent on marketshare and later the game turn, the bigger the multiplier
  - feature count, reputation, and competitive market share affect market share (# of sellers on competitive market)
  - unfilfilled market share depends on reputation and features and unfilledMarketSellers (# of sellers not on competitive market)
  - lower the bugs, the better the reputation.