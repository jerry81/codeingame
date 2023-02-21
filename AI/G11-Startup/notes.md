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

# observing other players

- one guy super aggressively goes devs
- reputation gets up to 1200
- then fires his devs and goes all in on market
- turns analysis
  1.  1 0 1 0 0 (1 manager, 1 dev)
  2.  2 0 1 3 0 (1 mgr, 2 devs, all to maintenence)
  3.  3 0 1 4 0 (1 mgr, 3 devs, 4 to maintenence, 2 to features)
  4.  4 0 1 8 0 (1 mgr) (4 managers, 10 devs, 8 to maintenence)
  5.  5 0 1 12 0 (5 mgrs, 15 devs, 12 to maintenence)
  6.  5 1 1 16 0 (6 mgrs, 20 devs, 1 sales, 16 maintainers)
  7.  -7 7 1 13 0 (7 mgrs, 13 devs, 8 sales, 13 maintainers)
  8.  -8 0 0 4 3 2 (no hires) 5 devs, 4 maintainers 3 competitive


# actual strategy
- keep hiring devs/managers until 3 managers (12 devs)
- wait until 10 features
- hire sellers/managers until 6 managers