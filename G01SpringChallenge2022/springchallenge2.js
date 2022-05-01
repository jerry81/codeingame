/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 var inputs = readline().split(' ');
 const baseX = parseInt(inputs[0]); // The corner of the map representing your base
 const baseY = parseInt(inputs[1]);
 const heroesPerPlayer = parseInt(readline()); // Always 3
 
 
 // game loop
 while (true) {
     let curMana = 0
     for (let i = 0; i < 2; i++) {
         var inputs = readline().split(' ');
         const health = parseInt(inputs[0]); // Each player's base health
         const mana = parseInt(inputs[1]); // Ignore in the first league; Spend ten mana to cast a spell
         curMana = mana
     }
     const entityCount = parseInt(readline()); // Amount of heros and monsters you can see
     let threats = []
     let hero1 = {}
     for (let i = 0; i < entityCount; i++) {
         var inputs = readline().split(' ');
         const id = parseInt(inputs[0]); // Unique identifier
         const type = parseInt(inputs[1]); // 0=monster, 1=your hero, 2=opponent hero
         const x = parseInt(inputs[2]); // Position of this entity
         const y = parseInt(inputs[3]);
         const shieldLife = parseInt(inputs[4]); // Ignore for this league; Count down until shield spell fades
         const isControlled = parseInt(inputs[5]); // Ignore for this league; Equals 1 when this entity is under a control spell
         const health = parseInt(inputs[6]); // Remaining health of this monster
         const vx = parseInt(inputs[7]); // Trajectory of this monster
         const vy = parseInt(inputs[8]);
         const nearBase = parseInt(inputs[9]); // 0=monster with no target yet, 1=monster targeting a base
         const threatFor = parseInt(inputs[10]); // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
         if (type == 0 && threatFor == 1 && nearBase == 1) {
             threats.push({
                 x,
                 y,
                 vx,
                 vy,
                 id
             })
         }
         if (type == 1 && id == 0) {
           hero1 = {
               x,
               y
           }
         }
     }
     console.error('hero 1 is ', hero1)
     let closestThreat = {}
     let closest = Number.MAX_SAFE_INTEGER
     for (let threat of threats) {
         console.error('threat is ', threat)
       let dist = (baseX - threat.x)^2 + (baseY - threat.y)^2
       console.error('dist is ', dist)
       console.error('closest is ', closest)
       if (dist < closest) {
           closest = dist
           closestThreat = threat
       }
     }
     console.error('closest is ', closestThreat.id)
     let midx = (baseX + closestThreat.x) / 2 
     let midy = (baseY + closestThreat.y) / 2 
     if (!midx) {
         if (baseX == 0) {
           midx = 500
         } else {
             midx = 17000
         }
     } 
     if (!midy) {
         if (baseX == 0) {
           midy = 500
         } else {
             midy = 8500
         }
     }
     let closestToHero = Math.sqrt((closestThreat.x - hero1.x)^2 + (closestThreat.y - hero1.y)^2)
     for (let i = 0; i < heroesPerPlayer; i++) {
         if (i == 0) {
             if (curMana > 10 && closestToHero < 1280) {
                 // always away from base
                 // when enemy is in range (1280 units)
                 // console.log('WIND ' )
                 const windCoordinates = baseX == 0 ? "17630 9000" : "0 0"
                 console.log('SPELL WIND ' + windCoordinates)
             } else {
                 console.log('MOVE ' + Math.round(midx) + " " + Math.round(midy))
             }
         } else if (i==1) {
             console.log('MOVE ' + Math.round(midx) + " " + Math.round(midy))
         } else {
             console.log('MOVE ' + Math.round(midx) + " " + Math.round(midy))
         }
         
         // 0 and 1 will be defenders, 2 will attack 
 
         // Write an action using console.log()
         // To debug: console.error('Debug messages...');
 
 
         // In the first league: MOVE <x> <y> | WAIT; In later leagues: | SPELL <spellParams>;
         // console.log('WAIT');
     }
 }
 