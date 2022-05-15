
Summary of new rules

Queens now start with less health.
See the updated statement for details.
This is the last rule change.
 	The Goal
Build structures and train troops in order to destroy the enemy Queen.
 	Rules
Field

The game is played by two players on a semi-open two-dimensional field 1920 units wide and 1000 units high, littered with circular building sites of varying radius. The top-left corner is 0,0. The field is generated randomly every game, with the sites being symmetrically laid out (rotationally around the map's center).

 
Queens

Each player controls a single Queen character, who can establish different structures on those sites. The Queen is the player’s only way to directly interact with the field.

The Queen is modeled as a circle with radius 30 units, and moves up to 60 units every turn (using the MOVE command).

Each Queen starts with a random amount of HP between 25 and 100 (both Queens start with the same HP). A Queen will be destroyed if her HP drops to zero -- if this happens, the player will lose the game. If both Queens are destroyed on the same turn, the game will end in a draw.

 
Structures

Structures can be built at no cost. A Queen character can build a structure (using the BUILD command) on a building site that she is in contact with. The variable touchedSite indicates the identifier of the building site that she is in contact with, -1 if not.

There are three types of structures:
 

BARRACKS-{type}: A player needs to build a barracks with their Queen in order to train creeps ({type} can be KNIGHT, ARCHER or GIANT). Every barracks is built with the ability to train a single creep type. Barracks are available for use on the turn immediately following their construction. A barracks is destroyed if it is touched by the enemy Queen.
TOWER: The Queen can also build static defensive structures called Towers as defenses against enemy creeps. Towers begin working the turn they are built, and can be grown over time. Every turn, towers automatically fire upon the nearest enemy creep inside their firing radius. They deal 3 base damage at the edge of their firing range. The closer the creep is to the tower, the more damage will be dealt (+1 for every 200 units closer) If there are no creeps in range, but the enemy Queen is in range, a tower will fire upon her instead, dealing 1 base damage +1 for every 200 units of distance closer. Once built, towers start to degrade slowly. A tower will eventually degrade completely and be destroyed. The Queen can grow a tower and increase its range by issuing the same command as to build it (BUILD {siteId} TOWER).
MINE: Each player begins with 100 gold. A player can increase the amount of gold collected per turn by building goldmines on building sites. Once a mine is built, it produces 1 gold per turn. The mining rate of a mine can be increased by 1 by issuing the same command as to build it (BUILD {siteId} MINE). However, each mine has a maximum mining rate (between +1 and +5). Each building site has a limited amount of gold. A mine then slowly runs out of gold until it's completely destroyed. A mine is also destroyed if it is touched by an enemy creep or the enemy Queen. Sites near the middle of the field have higher gold available, and higher maximum mining rates. Gold totals and mining rates are not given for all sites, they must be discovered by the Queen. These numbers will be available for any site whose center is within 300 units from the Queen.
If she so chooses, a Queen can replace an existing friendly building simply by building another structure in its place (unless it's a barracks which is currently training).

 
Creeps

In order to destroy the enemy Queen, a player will need to build creeps. Once built, creeps follow very simple behaviours (see below), and cannot be controlled by the player. Creeps will eventually age and die on their own, losing 1 HP every turn.

There are three different creep types that can be built. (The Queen is listed here for comparison.)

Type	KNIGHT	ARCHER	GIANT	Queen
Cost	80	100	140	N/A
Number	4	2	1	N/A
Speed	100	75	50	60
Damage per turn	1 to Queen	10 to Giants
2 to other creeps	80 to tower	N/A
Range	0	200	0	N/A
HP	25	45	200	200
Training Time (turns)	5	8	10	N/A
Radius	20	25	40	30
KNIGHT units are light, fast units which attack the enemy Queen, dealing 1 damage every turn they end in contact with the enemy Queen.
ARCHER units are slower, ranged units which move toward and attack nearby enemy creeps from a short distance. They deal 2 damage to the their nearest enemy creep every turn they end within range of that creep. If they attack a GIANT, they deal 10 damage instead. (Note: they can shoot past building sites).
GIANT units do not attack the enemy Queen or enemy creeps, but instead attack nearby enemy towers and break them down over time.
 
Training Creeps

A player trains creeps (using the TRAIN command) by indicating the IDs of which sites containing a barracks that player wishes to train creeps at. A barracks that is already in the middle of training cannot begin training again until the current creep set is built. Also, such a barracks cannot be replaced by another structure. Examples:

TRAIN 13 6 19 - Three barracks begin training creeps
TRAIN 14 - One barracks begins training creeps
When the train commands are sent, the player pays the total cost in gold, and indicated barracks will begin training the appropriate set of units. After the appointed number of turns elapses, a set of creeps emerges from the barracks and begins acting by themselves on the following turn.

The training of creeps represents an extra mandatory command every turn. For barracks not to begin training new units, a player has to use the TRAIN command with no identifier.

 
Victory Conditions
Destroy the enemy Queen.
After 250 turns, your Queen has more HP than the enemy Queen.
 
Lose Conditions
Output an invalid command.
 	Expert Rules
Turn sequence

Game state sent to players
Player inputs received and processed:
New trainees started
Queens move
New structures built
Creeps move, collisions resolved
Creeps attack and destroy enemy mines
Queens destroy enemy mines and barracks
Remaining structures act (including ones built this turn):
Towers shoot, dead creeps removed
Barracks that are in progress advance; new creeps spawned
Mines collect gold for Queens
Creeps age, dead creeps removed
End game condition checked
 
Collisions

Units cannot share space. All building sites, Queens and creeps are modeled as circles.

Unit movement is done by simply moving toward the desired target. However, at the end of every turn, a series of collision checks are performed. While there are any collisions, the offending units are simply translated away from each other (except for sites, they stay put.) Hence it is possible for a Queen to be "shoved" out of her way by a swarm of creeps.

For this purpose, units are assigned a weight as follows:

Site: infinite (unmovable)
Queen: 100
Giant: 20
Archer: 9
Knight: 4
In case of collisions, a lower-weight unit will be displaced more than a higher-weight unit.

 
Unit Contact

Two entities are considered "touching" by comparing the distance between their centers, thus: isTouching = distance - radius1 - radius2 < 5 . This applies to:

KNIGHT - Queen (damage)
Queen - Site (construction, and tearing down enemy structures)
Creep - Mine
GIANT - Tower
 
Concurrent builds

If both Queens try simultaneously to build a structure on the same building site, then only one will be built:

On even-numbered turns (this includes the first turn: turn 0), player 2 gets to build
On odd-numbered turns, player 1 gets to build
Site gold

All building sites are randomized in pairs: attributes that apply to mirroring sites are always the same at the game's start. Each site-pair gets assigned a random gold amount between 200 and 250, a maximum mining rate between +1 and +3, and a radius between 60 and 110 units.

Sites whose center is located within 500 units of the map's center are given a bonus of 50 gold and +1 to maximum mining rate. Sites whose center is located within 200 units of the map's center are given a further bonus of 50 gold and +1 to maximum mining rate.

 
Tower HP

Each tower has a number of HP (param1) that determines its effective attack radius (param2). Each HP allows the tower to cover 1000 square-units (a square unit is not very much!), not including the area of the site on which it sits.

The attack radius is calculated every turn according to the tower's HP according to the formula: attackRadius = sqrt((hp * 1000 + siteArea) / PI) -- this is measured from the site's center. This is so that PI * attackRadius^2 = hp * 1000 + siteArea. When a tower is first built, it receives 200 HP. This corresponds to a variable attack range: longer attack range for a smaller radius site.

When an existing tower is grown, it receives 100 additional HP. The maximum amount of HP for towers is 800. Every tower loses 4 HP per turn due to exposure to the elements. Each GIANT that ends its turn next to a tower reduces its HP by 80. Hence a Queen can slightly outpace a single GIANT by building at the same time.

 
Draws

The game will end in a draw if after 250 turns both Queens have the same HP, or both Queens are destroyed on the same turn.

 
Referee

The referee can be viewed here.

 	Game Input
Initialization input
Line 1: an integer numSites, indicating the number of building sites on the map.
Next numSites lines: 4 integers siteId x y radius
siteId: The numeric identifier of the site
x y: The numeric coordinates of the site's center
radius: The radius of the site
Input for one game turn
Line 1 and 2: Two integers gold touchedSite
gold: the current amount of gold available to be spent
touchedSite: the id of the site your Queen is touching, or -1 if none
Next numSites lines: Seven integers siteId gold maxMineSize structureType owner param1 param2
siteId: The numeric identifier of the site
gold: The total number of gold remaining to be mined from this site (-1 if unknown)
maxMineSize: The maximum rate that a mine can extract gold from this site (-1 if unknown)
structureType:
-1: No structure
0: Goldmine
1: Tower
2: Barracks
owner:
-1: No structure
0: Friendly
1: Enemy
param1:
When no structure: -1
When goldmine: the income rate ranging from 1 to 5 (or -1 if enemy)
When tower: the remaining HP
When barracks, the number of turns before a new set of creeps can be trained (if 0, then training may be started this turn)
param2
When no structure: -1
When goldmine: -1
When tower: the attack radius measured from its center
When barracks: the creep type: 0 for KNIGHT, 1 for ARCHER, 2 for GIANT

Next Line: numUnits: Number of total active units, including Queens
Next numUnits lines: 5 integers x y owner unitType health
x y: Coordinates of the unit
owner: 0 = Friendly; 1 = Enemy
unitType: The unit type: -1 for Queen, 0 for KNIGHT, 1 for ARCHER, 2 for GIANT
health: Current HP of the unit
Output for one game turn
First line: One of the following
WAIT Do nothing
MOVE x y Will attempt to move towards the provided coordinates (x,y given as integers)
BUILD {siteId} TOWER Will attempt to build or repair a tower at the indicated site. If too far away, the Queen will instead move towards the site.
BUILD {siteId} MINE Will attempt to build or repair a mine at the indicated site. If too far away, the Queen will instead move towards the site.
BUILD {siteId} BARRACKS-{type} Will attempt to build a barracks at the indicated site. If too far away, the Queen will instead move towards the site. The type must be given as KNIGHT, ARCHER, or GIANT.
Second line: TRAIN optionally followed by a list of siteId integers to start training at.
Constraints
Response time for first turn ≤ 1000ms
Response time for one turn ≤ 50ms