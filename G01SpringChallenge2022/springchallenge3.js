/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 var inputs = readline().split(' ');
 const baseX = parseInt(inputs[0]); // The corner of the map representing your base
 const baseY = parseInt(inputs[1]);
 const heroesPerPlayer = parseInt(readline()); // Always 3
 
 const inUL = baseX == 0
 function buildTable(id,type,x,y,shieldLife,isControlled,health,vx,vy,nearBase,threatFor, masterTable) {
   if (type == 0) {
       masterTable["monsters"].push({
           id,type,x,y,shieldLife,threatFor,nearBase,vx,vy,isControlled,health
       })
       if (threatFor == 1 && nearBase == 1) {
         masterTable["threats"].push({
             id,type,x,y,shieldLife,threatFor,nearBase,vx,vy,isControlled,health
         })
       }
   }
   if (type == 1) {
       masterTable["heroes"].push({
         id,type,x,y,shieldLife,threatFor,nearBase,vx,vy,isControlled,health
       })
   }
   if (type == 2) {
       masterTable["opponents"].push({
         id,type,x,y,shieldLife,threatFor,nearBase,vx,vy,isControlled,health
       })
   }
 }
 
 function dist(obj1, obj2) {
     return Math.sqrt((obj2.x - obj1.x) ^ 2 + (obj2.y - obj1.y) ^ 2)
 }
 function buildCalcTable(masterTable, calcTable) {
   const monsters = masterTable.monsters
   const heroes = masterTable.heroes
   const opponents = masterTable.opponents
 
   for (const h of heroes) {
         for (const m of monsters) {
           const distToHero = dist(h, m)
           calcTable["distToHeroes"][h.id]["monsters"].push({monster:m, distToHero}) 
       }
       for (const o of opponents) {
           const distToHero = dist(h,o)
           calcTable["distToHeroes"][h.id]["opponents"].push(opponent:o, distToHero)
       }
   }
 }
 // game loop
 while (true) {
     for (let i = 0; i < 2; i++) {
         var inputs = readline().split(' ');
         const health = parseInt(inputs[0]); // Each player's base health
         const mana = parseInt(inputs[1]); // Ignore in the first league; Spend ten mana to cast a spell
     }
     const entityCount = parseInt(readline()); // Amount of heros and monsters you can see
     let masterTable = {
         monsters: [],
         heroes: [],
         opponents: [],
         threats: []
     }
     let calcTable = {
         distToHeroes: {
             0: {
               monsters: [],
               opponents: []
             },
             1: {
                 monsters: [],
                 opponents: []
             },
             2: {
                 monsters: [],
                 opponents: []
             }
         },
         distToBase: []
     }
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
         buildTable(id,type,x,y,shieldLife,isControlled,health,vx,vy,nearBase,threatFor, masterTable)
     }
     buildCalcTable(masterTable, calcTable)
     console.error('masterTable is ', masterTable)
     for (let i = 0; i < heroesPerPlayer; i++) {
 
         // Write an action using console.log()
         // To debug: console.error('Debug messages...');
 
 
         // In the first league: MOVE <x> <y> | WAIT; In later leagues: | SPELL <spellParams>;
         console.log('MOVE 500 500');
     }
 }
 