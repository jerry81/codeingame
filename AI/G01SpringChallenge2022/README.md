
This is a league based challenge.

For this challenge, multiple leagues for the same game are available. Once you have proven yourself against the first Boss, you will access a higher league and extra rules will be available.

Starter AIs are available in the Starter Kit. They can help you get started with your own bot.

Introductory video by Mathis Hammel: https://youtu.be/MyHjWftmMfQ

 	The Goal
Protect your base from monster attacks and outlive your opponent.
 	Rules
Both players controls a team of 3 heroes. The teams start out at opposite corners of the map, near their base. Throughout the game monsters will appear regularly on the edges of the map. If a monster reaches your base, it will deal damage. If your base takes too much damage, you lose.

Thankfully, your heroes can kill monsters.

The map
The game is played on a rectangular map where the coordinate X=0, Y=0 is the top-left pixel and X=17630, Y=9000 is the bottom-right pixel.

Each base can take a maximum of 3 points of damage before being destroyed.

Heroes
Every turn, you must provide a command for each hero. They may perform any of the following commands:

WAIT, the hero remains where they are.

MOVE, followed by map coordinates will make the hero advance towards that point by a maximum of 800 units.

After a hero's move phase, any monsters within 800 units will suffer 2 points of damage.

Monsters
Every monster appears with a given amount of health. If at the end of a turn, a monster's health has dropped to zero or below, the monster is removed from the game.

Monsters will appear randomly, with a random moving direction.

Monsters will always advance in a straight line at a speed of 400 units per turn.

If a monster comes within 5000 units of a base at the end of a turn, it will target that base.

When targeting a base, a monster will move directly towards that base and can no longer leave the map.

If a monster comes within 300 units of a base at the end of a turn, as long as it has not been killed on this turn, it will disappear and deal the base 1 point of damage.

Victory Conditions
Your opponent's base health has dropped to zero.
You have more base health points than your opponent after 220 turns.
Defeat Conditions
Your base's health reaches zero.
Your program does not provide a valid command in time.

🐞 Debugging tips
Hover over an entity to see extra information about it
Append text after any command and that text will appear above your hero
Press the gear icon on the viewer to access extra display options
Use the keyboard to control the action: space to play/pause, arrows to step 1 frame at a time
 	Game Input/Output
Initialization Input
Line 1: two integers baseX and baseY for the coordinates of your base. The enemy base will be at the opposite side of the map.
Line 2: the integer heroesPerPlayer which is always 3.
Input for One Game Turn
First 2 lines: two integers baseHealth and mana for the remaining health and mana for both players. Your data is always given first. You may ignore the mana for this league.
Next line: entityCount for the amount of game entities currently in play.
Next entityCount lines: 11 integers to describe each entity:
id: entity's unique id.
type:
0: a monster
1: one of your heroes
2: one of your opponent's heroes
x & y: the entity's position.
shieldLife: ignore for this league.
isControlled: ignore for this league.
The next 5 integers only apply to monsters (will be -1 for heroes).
health: monster's remaining health points.
vx & vy: monster's current speed vector, they will add this to their position for their next movement.
nearBase: 1: if monster is targeting a base, 0 otherwise.
threatFor:
With the monster's current trajectory — if nearBase is 0:
0: it will never reach a base.
1: it will eventually reach your base.
2: it will eventually reach your opponent's base.
If nearBase is 1: 1 if this monster is targeting your base, 2 otherwise.
Output for One Game Turn
3 lines, one for each hero, containing one of the following actions:
WAIT: the hero does nothing.
MOVE followed by two integers (x,y): the hero moves 800 towards the given point.
You may append text to a command to have it displayed in the viewer above your hero.

Examples:
MOVE 8000 4500
WAIT nothing to do...
Constraints
Response time per turn ≤ 50ms
Response time for the first turn ≤ 1000ms

What is in store for me in the higher leagues?
Extra rules available in higher leagues are:
Heroes can cast spells
Fog of war


# wood 1 


Starter Kit

Starter AIs are available in the Starter Kit. They can help you get started with your own bot.

Introductory video by Mathis Hammel: https://youtu.be/MyHjWftmMfQ

 	The Goal
Protect your base from monster attacks and outlive your opponent.
 	Rules
Both players controls a team of 3 heroes. The teams start out at opposite corners of the map, near their base. Throughout the game monsters will appear regularly on the edges of the map. If a monster reaches your base, it will deal damage. If your base takes too much damage, you lose.

Thankfully, your heroes can kill monsters.

The map
The game is played on a rectangular map where the coordinate X=0, Y=0 is the top-left pixel and X=17630, Y=9000 is the bottom-right pixel.

Fog makes it impossible to know the positions of all monsters and rival heroes. You need to have them within 2200 units from one of your heroes or 6000 from your base.

Each base can take a maximum of 3 points of damage before being destroyed.

Multiple entities (heroes & monsters) can occupy the same coordinates, there is no collision.

Heroes
Every turn, you must provide a command for each hero. They may perform any of the following commands:

WAIT, the hero remains where they are.

MOVE, followed by map coordinates will make the hero advance towards that point by a maximum of 800 units.

SPELL, followed by a spell action, as detailed in the Spells section further below.

Heroes cannot be killed and cannot leave the map.

After a hero's move phase, any monsters within 800 units will suffer 2 points of damage.

Monsters
Every monster appears with a given amount of health. If at the end of a turn, a monster's health has dropped to zero or below, the monster is removed from the game.

Monsters will appear randomly, but symmetrically from the map edges outside of the player's bases. They appear with a random moving direction.

Monsters will always advance in a straight line at a speed of 400 units per turn.

If a monster comes within 5000 units of a base at the end of a turn, it will target that base.

When targeting a base, a monster will move directly towards that base and can no longer leave the map.

If a monster is pushed (with a WIND command) outside the radius of a targeted base, it will stop targeting and start moving in a randomly selected direction.

If a monster comes within 300 units of a base at the end of a turn, as long as it has not been killed on this turn, it will disappear and deal the base 1 point of damage.

Each subsequent monster may have slightly more starting health than any previous monster.

Spells
Your team will also acquire 1 point of mana per damage dealt to a monster, even from monsters with no health left.

Mana is shared across the team and heroes can spend 10 mana points to cast a spell.

A spell command has parameters, which you must separate with a space.

command	parameters	effect
WIND	<x> <y>	All entities (except your own heroes) within 1280 units are pushed 2200 units in the direction from the spellcaster to x,y.
 	WIND Example
A hero uses WIND at position (6000, 6000) towards (6000, 5000).

There are 2 monsters within 1280 units around the hero.

SPELL WIND 6000 5000
The vector (0,-1) describes the direction between the hero and the target point.

The monsters all move 2200 in the direction defined by the vector.
Victory Conditions
Your opponent's base health has dropped to zero.
You have more base health points than your opponent after 220 turns.
In case of a tie, you have gained the highest amount of wild mana: mana gained outside the radius of your base.
Defeat Conditions
Your base's health reaches zero.
Your program does not provide a valid command in time.

🐞 Debugging tips
Hover over an entity to see extra information about it
Append text after any command and that text will appear above your hero
Press the gear icon on the viewer to access extra display options
Use the keyboard to control the action: space to play/pause, arrows to step 1 frame at a time
 	Game Input/Output
Initialization Input
Line 1: two integers baseX and baseY for the coordinates of your base. The enemy base will be at the opposite side of the map.
Line 2: the integer heroesPerPlayer which is always 3.
Input for One Game Turn
First 2 lines: two integers baseHealth and mana for the remaining health and mana for both players. Your data is always given first.
Next line: entityCount for the amount of game entities currently visible to you.
Next entityCount lines: 11 integers to describe each entity:
id: entity's unique id.
type:
0: a monster
1: one of your heroes
2: one of your opponent's heroes
x & y: the entity's position.
shieldLife: ignore for this league.
isControlled: ignore for this league.
The next 5 integers only apply to monsters (will be -1 for heroes).
health: monster's remaining health points.
vx & vy: monster's current speed vector, they will add this to their position for their next movement.
nearBase: 1: if monster is targeting a base, 0 otherwise.
threatFor:
With the monster's current trajectory — if nearBase is 0:
0: it will never reach a base.
1: it will eventually reach your base.
2: it will eventually reach your opponent's base.
If nearBase is 1: 1 if this monster is targeting your base, 2 otherwise.
Output for One Game Turn
3 lines, one for each hero, containing one of the following actions:
WAIT: the hero does nothing.
MOVE followed by two integers (x,y): the hero moves 800 towards the given point.
SPELL followed by a spell command: the hero attempts to cast the given spell.
You may append text to a command to have it displayed in the viewer above your hero.

Examples:
MOVE 8000 4500
SPELL WIND 80 40 casting a wind spell!
WAIT nothing to do...
Constraints
Response time per turn ≤ 50ms
Response time for the first turn ≤ 1000ms

What is in store for me in the higher leagues?
Extra rules available in higher leagues are:
New spell: CONTROL
New spell: SHIELD

# bronze


 	The Goal
Protect your base from monster attacks and outlive your opponent.
 	Rules
Both players controls a team of 3 heroes. The teams start out at opposite corners of the map, near their base. Throughout the game monsters will appear regularly on the edges of the map. If a monster reaches your base, it will deal damage. If your base takes too much damage, you lose.

Thankfully, your heroes can kill monsters.

The map
The game is played on a rectangular map where the coordinate X=0, Y=0 is the top-left pixel and X=17630, Y=9000 is the bottom-right pixel.

Fog makes it impossible to know the positions of all monsters and rival heroes. You need to have them within 2200 units from one of your heroes or 6000 from your base.

Each base can take a maximum of 3 points of damage before being destroyed.

Multiple entities (heroes & monsters) can occupy the same coordinates, there is no collision.

Heroes
Every turn, you must provide a command for each hero. They may perform any of the following commands:

WAIT, the hero remains where they are.

MOVE, followed by map coordinates will make the hero advance towards that point by a maximum of 800 units.

SPELL, followed by a spell action, as detailed in the Spells section further below.

Heroes cannot be killed and cannot leave the map.

After a hero's move phase, any monsters within 800 units will suffer 2 points of damage.

Monsters
Every monster appears with a given amount of health. If at the end of a turn, a monster's health has dropped to zero or below, the monster is removed from the game.

Monsters will appear randomly, but symmetrically from the map edges outside of the player's bases. They appear with a random moving direction.

Monsters will always advance in a straight line at a speed of 400 units per turn.

If a monster comes within 5000 units of a base at the end of a turn, it will target that base.

When targeting a base, a monster will move directly towards that base and can no longer leave the map.

If a monster is pushed (with a WIND command) outside the radius of a targeted base, it will stop targeting and start moving in a randomly selected direction.

If a monster comes within 300 units of a base at the end of a turn, as long as it has not been killed on this turn, it will disappear and deal the base 1 point of damage.

Each subsequent monster may have slightly more starting health than any previous monster.

Spells
Your team will also acquire 1 point of mana per damage dealt to a monster, even from monsters with no health left.

Mana is shared across the team and heroes can spend 10 mana points to cast a spell.

A spell command has parameters, which you must separate with a space.

command	parameters	effect	range
WIND	<x> <y>	All entities (except your own heroes) within 1280 units are pushed 2200 units in the direction from the spellcaster to x,y.	1280
SHIELD	<entityId>	The target entity cannot be targeted by spells for the next 12 rounds.	2200
CONTROL	<entityId> <x> <y>	Override the target's next action with a step towards the given coordinates.	2200
A hero may only cast a spell on entities that are within the spell's range from the hero.
 	WIND Example
A hero uses WIND at position (6000, 6000) towards (6000, 5000).

There are 2 monsters within 1280 units around the hero.

SPELL WIND 6000 5000
The vector (0,-1) describes the direction between the hero and the target point.

The monsters all move 2200 in the direction defined by the vector.
Victory Conditions
Your opponent's base health has dropped to zero.
You have more base health points than your opponent after 220 turns.
In case of a tie, you have gained the highest amount of wild mana: mana gained outside the radius of your base.
Defeat Conditions
Your base's health reaches zero.
Your program does not provide a valid command in time.

🐞 Debugging tips
Hover over an entity to see extra information about it
Append text after any command and that text will appear above your hero
Press the gear icon on the viewer to access extra display options
Use the keyboard to control the action: space to play/pause, arrows to step 1 frame at a time
 	Technical Details
After an entity moves towards a point, its coordinates are truncated (when below halfway across the map) or rounded up (when above halfway across the map), only then are distance-based calculations performed (such as monster damage).

Spells are cast in the order of the received output. This means a spell may be cancelled if another hero spent the necessary mana earlier in the turn.

If an entity is being moved via a CONTROL from multiple sources at once, it will move to the average of all computed destinations.

If an entity is being moved via a WIND from multiple sources at once, it will move to the sum of all given directions.

SHIELD also protects entities from receiving a new SHIELD.

Using a spell against a shielded entity still costs mana.

Players are not given the coordinates of monsters outside the map and they cannot be targetted by spells.

A monster can be pushed outside of the map, unless it is within a base radius, in which case it will will be moved no further than the border.

In case of a tie, the player who gained the highest amount of mana outside the radius of their base will win. this is called wild mana.

The source code of this game is available on this GitHub repo.

 	Action order for one turn
Wait for both players to output 3 commands.
CONTROL spells are applied to the targets and will only be effective on the next turn, after the next batch of commands.
SHIELD spells are applied to the targets and will only be effective on the next turn, after the next batch of commands. Does not protect from a spell from this same turn.

MOVE all heroes.

Heroes attack monsters in range and produce mana for each hit.

WIND spells are applied to entities in range.

MOVE all monsters according to their current speed, unless they were pushed by a wind on this turn.

SHIELD countdowns are decremented.

New monsters appear. Dead monsters are removed.

 	Game Input/Output
Initialization Input
Line 1: two integers baseX and baseY for the coordinates of your base. The enemy base will be at the opposite side of the map.
Line 2: the integer heroesPerPlayer which is always 3.
Input for One Game Turn
First 2 lines: two integers baseHealth and mana for the remaining health and mana for both players. Your data is always given first.
Next line: entityCount for the amount of game entities currently visible to you.
Next entityCount lines: 11 integers to describe each entity:
id: entity's unique id.
type:
0: a monster
1: one of your heroes
2: one of your opponent's heroes
x & y: the entity's position.
shieldLife: the number of rounds left until entity's shield is no longer active. 0 when no shield is active.
isControlled: 1 if this entity is under a CONTROL spell, 0 otherwise.
The next 5 integers only apply to monsters (will be -1 for heroes).
health: monster's remaining health points.
vx & vy: monster's current speed vector, they will add this to their position for their next movement.
nearBase: 1: if monster is targeting a base, 0 otherwise.
threatFor:
With the monster's current trajectory — if nearBase is 0:
0: it will never reach a base.
1: it will eventually reach your base.
2: it will eventually reach your opponent's base.
If nearBase is 1: 1 if this monster is targeting your base, 2 otherwise.
Output for One Game Turn
3 lines, one for each hero, containing one of the following actions:
WAIT: the hero does nothing.
MOVE followed by two integers (x,y): the hero moves 800 towards the given point.
SPELL followed by a spell command: the hero attempts to cast the given spell.
You may append text to a command to have it displayed in the viewer above your hero.

Examples:
MOVE 8000 4500
SPELL WIND 80 40 casting a wind spell!
SPELL SHIELD 1
WAIT nothing to do...
You must provide a valid command to all heroes each turn, even if they are being controlled by your opponent.
Constraints
Response time per turn ≤ 50ms
Response time for the first turn ≤ 1000ms