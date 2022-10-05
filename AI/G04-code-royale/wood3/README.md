	The Goal
Build structures and train troops in order to destroy the enemy Queen.
 	Rules
Field

The game is played by two players on a field 1920 units wide and 1000 units high, littered with circular building sites. The top-left corner is 0,0.

 
Queens

Each player controls a single Queen character, who can establish different structures on those sites. The Queen is the player’s only way to directly interact with the field.

The Queen is modeled as a circle with radius 30 units, and moves up to 60 units every turn (using the MOVE command). Each Queen starts with 100 HP, and will be destroyed if this drops to zero -- if this happens, the player will lose the game. If both Queens are destroyed on the same turn, the game will end in a draw.

 
Structures

Structures can be built at no cost. A Queen character can build a structure (using the BUILD command) on a building site that she is in contact with. The variable touchedSite indicates the identifier of the building site that she is in contact with, -1 if not.

There is one type of structure:

BARRACKS-{type}: A player needs to build a BARRACKS with their Queen in order to train creeps ({type} can be KNIGHT or ARCHER). Every barracks is built with the ability to train a single creep type. Barracks are available for use on the turn immediately following their construction. A barracks is destroyed if it is touched by the enemy Queen.
If she so chooses, a Queen can replace an existing friendly structure simply by building another one in its place (unless it is a Barracks that is currently training).

 
Gold

Each player begins with 100 gold and will gain 10 gold at the end of each turn.

 
Creeps

In order to destroy the enemy Queen, a player will need to build creeps. Once built, creeps follow very simple behaviours (see below), and cannot be controlled by the player. Creeps will eventually age and die on their own, losing 1 HP every turn.

There are two different creep types that can be built.

KNIGHT units are light, fast units which attack the enemy Queen. They cost 80 gold to train a group of 4.
ARCHER units are slower, ranged units which move toward and attack nearby enemy creeps from a short distance. They cost 100 gold to train a group of 2. Note: ARCHER units do not attack the enemy Queen!
 
Training Creeps

A player trains creeps (using the TRAIN command) by indicating the identifiers of which sites containing a barracks they wish to train creeps at. A barracks that is already in the middle of training cannot begin training again until the current creep set is built. Also, such a barracks cannot be replaced by another structure. Examples:

TRAIN 13 6 19 - Three barracks begin training creeps
TRAIN 14 - One barracks begins training creeps
When the train commands are sent, the player pays the total cost in gold, and indicated barracks will begin training the appropriate set of units. After the appointed number of turns elapses, a set of creeps emerges from the barracks and begins acting by themselves on the following turn.

The training of creeps represent an extra mandatory command every turn. For barracks not to begin training new units, a player has to use the TRAIN command with no identifier.

 

 
Victory Conditions
Destroy the enemy Queen.
After 250 turns, your Queen has more HP than the enemy Queen.
 
Lose Conditions
Output an invalid command.
 	Expert Rules
An expanded statement with full simulation details will be available in Bronze league.
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
Next numSites lines: Seven integers siteId ignore1 ignore2 structureType owner param1 param2
siteId: The numeric identifier of the site
ignore1: Reserved for future leagues.
ignore2: Reserved for future leagues.
structureType:
-1: No structure
2: Barracks
owner:
-1: No structure
0: Friendly
1: Enemy
param1:
When no structure: -1
When barracks, the number of turns before a new set of creeps can be trained (if 0, then training may be started this turn)
param2
When no structure: -1
When barracks: the creep type: 0 for KNIGHT, 1 for ARCHER

Next Line: numUnits: Number of total active units, including Queens
Next numUnits lines: 5 integers x y owner unitType health
x y: Coordinates of the unit
owner: 0 = Friendly; 1 = Enemy
unitType: The unit type: -1 for Queen, 0 for KNIGHT, 1 for ARCHER
health: Current HP of the unit
Output for one game turn
First line: One of the following
WAIT Do nothing
MOVE x y Will attempt to move towards the provided coordinates (x,y given as integers)
BUILD {siteId} BARRACKS-{type} Will attempt to build a barracks at the indicated site. If too far away, the Queen will instead move towards the site. The type must be given as either KNIGHT or ARCHER.
Second line: TRAIN optionally followed by a list of siteId integers to start training at.
Constraints
Response time for first turn ≤ 1000ms
Response time for one turn ≤ 50ms

What is in store for me in the higher leagues?

The extra rules available in higher leagues are:
You will be able to build TOWER structures to defend against enemy creeps, and GIANT creeps to attack enemy towers.
You will need to build MINE structures in order to generate gold.
Queens will start with less health.