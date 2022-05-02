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
         let hid = h.id
         if (!inUL) {
           hid -= 3
         }
         for (const m of monsters) {
           const distToHero = dist(h, m)
           console.error('building table', calcTable)
           console.error('h.id is ', hid)
           calcTable["distToHeroes"][hid]["monsters"].push({monster:m, distToHero}) 
       }
       for (const o of opponents) {
           const distToHero = dist(h,o)
           calcTable["distToHeroes"][hid]["opponents"].push({opponent:o, distToHero})
       }
   }
   for (const m of monsters) {
       base = inUL ? { x: 0, y: 0 } : { x: 17630, y: 9000 }
       const distToBase = dist(base, m)
       calcTable["distToBase"].push({ monster: m, distToBase })
   }
 }
 let turnsSinceWind = 0;
 let turnsSinceWind2 = 0;
 let turnsSinceShield = 0;
 let turnsSinceControl = 0;
 let turnsSinceControl2 = 0;
 let turnsSinceControl3 = 0;
 function getClosestToHero(distsToHero) {
     if (!distsToHero) return false
     let closestD = Number.MAX_SAFE_INTEGER
     let closest
     for (let m of distsToHero) {
         if (m.distToHero < closestD) {
             closestD = m.distToHero
             closest = m.monster
         }
     }
     return closest ? { closest, closestD } : false 
 }
 function randomizeMovement(x,y) {
     const spread = Math.random() * 2000
     let randomizedX = Math.max(0, Math.min(17630, 
        Math.round((x / 1.5) + spread
         )))
     let randomizedY = Math.max(0, Math.min(9000, 
             Math.round((y / 1.5) + spread
              )))
     return `${randomizedX} ${randomizedY}`
 }
 
 let lookupControl = {}
 function heroDo(calcTable, heroId, closestThreat, curMana, masterTable) {
 // hero initialization 
 // hero 1 - defender
   // wander zone - base + 1000
 // hero 2 - midrange
   // wander zone - base + 3000
 // hero 3 - attacker 
   // wander zone - no bounds 
 // if threat on base, all heroes fall back to intercept 
 // 
   const hero1ThreshX = inUL ? 1000 : 17630 - 1000 
   const hero1ThreshY = inUL ? 1000 : 8000
   const hero2ThreshX = inUL ? 2500 : 17630 - 2500
   const hero2ThreshY = inUL ? 2500 : 5500
   
   if (heroId == 0) {
       // if enemy within range - 
       
       const distsToHero = calcTable.distToHeroes[0].monsters
       let closestObj = getClosestToHero(distsToHero)
       let closestD = closestObj.closestD
       let closest = closestObj.closest
       if (closestThreat) closest = closestThreat
       let midX, midY
       if (closest) {
       midX = Math.round((baseX + closest.x) / 2)
       midY = Math.round((baseY + closest.y) / 2)
       }
       // issue - wind is being cast with no monsters in range 
       let inThreshold1
       if (midX) {
           inThreshold1 = inUL ? (midX < hero1ThreshX && midY < hero1ThreshY) : (midX > hero1ThreshX && midY > hero1ThreshY)
       }
       if (closestD && curMana > 10 && closestD < 800 && turnsSinceWind2 > 3 && !closest.isControlled && !closest.shieldLife) {
         turnsSinceWind2 = 0
         console.log(`SPELL WIND ${inUL ? "17630 9000" : "0 0"}`)
       } else if (midX && inThreshold1) {
           console.log(`MOVE ${midX} ${midY}`)
       } else {
         console.log(`MOVE ${hero1ThreshX} ${hero1ThreshY}`)
       }
   }
   if (heroId == 1) {
     const distsToHero = calcTable.distToHeroes[1].monsters
     let closestObj = getClosestToHero(distsToHero)
       let closestD = closestObj.closestD
       let closest = closestObj.closest
     if (closestThreat) closest = closestThreat
     let midX, midY
     let furtherFromBaseThanHero 
     if (closest) {
     midX = Math.round((baseX + closest.x) / 2)
     midY = Math.round((baseY + closest.y) / 2)
       furtherFromBaseThanHero = inUL ? ((closest.x + closest.y) > (masterTable.heroes[1].y + masterTable.heroes[1].x)) : (((closest.x + closest.y) < (masterTable.heroes[1].y + masterTable.heroes[1].x)))
     } 
     if (midX) {
         inThreshold2 = inUL ? (midX < hero2ThreshX && midY < hero2ThreshY) : (midX > hero2ThreshX && midY > hero2ThreshY)
     }
     if (closest && curMana > 60 && closestD < 1500 && turnsSinceControl2 > 4) {
       turnsSinceControl2 = 0
       console.log(`SPELL CONTROL ${closest.id} ${inUL ? "17630 9000" : "0 0"}`)
     }
     else if (closestD && curMana > 50 && closestD < 800 && turnsSinceWind > 5) {
         turnsSinceWind = 0
         console.log(`SPELL WIND ${inUL ? "17630 9000" : "0 0"}`)
       }
     else if (closest && inThreshold2) {
         console.log(`MOVE ${midX} ${midY}`)
      
     } else {
        // console.log(`MOVE ${randomizeMovement(hero2ThreshX, hero2ThreshY)}`)
        console.log(`MOVE ${hero2ThreshX} ${hero2ThreshY}`)
     }
     
   } 
   if (heroId == 2) {
     const distsToHero = calcTable.distToHeroes[2].monsters
     let closestObj = getClosestToHero(distsToHero)
       let closestD = closestObj.closestD
       let closest = closestObj.closest
       let furtherFromBaseThanHero 
       if (closest) {
         furtherFromBaseThanHero = inUL ? ((closest.x + closest.y) > (masterTable.heroes[2].y + masterTable.heroes[2].x)) : (((closest.x + closest.y) < (masterTable.heroes[2].y + masterTable.heroes[2].x)))
       } 
       if (curMana > 20 && turnsSinceControl > 2 && closestD < 1800 && furtherFromBaseThanHero) {
         turnsSinceControl = 0
         console.log(`SPELL CONTROL ${closest.id} ${inUL ? "17630 9000" : "0 0"}`)
     }
     else if (closest) {
         console.log(`MOVE ${closest.x} ${closest.y}`)
     } else {
         console.log(`MOVE ${inUL? 5000 : 12500} ${inUL ? 3000: 6000}`)
     }
   }
 }
 
 
 
 function getClosestThreat(calcTable) {
     const monsters = calcTable.distToBase
     let closest, closestDist
     closestDist = Number.MAX_SAFE_INTEGER
     for (m of monsters) {
         if (closestDist > m.distToBase) {
             closest = m.monster
             closestDist = m.distToBase
         }
     }
     return closest ? closest : false
 }
 
 // game loop
 while (true) {
    let curMana
     for (let i = 0; i < 2; i++) {
         var inputs = readline().split(' ');
         const health = parseInt(inputs[0]); // Each player's base health
         const mana = parseInt(inputs[1]); // Ignore in the first league; Spend ten mana to cast a spell
         curMana = mana
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
     let closestThreat = false 
     closestThreat = getClosestThreat(calcTable) 
     turnsSinceWind++
     turnsSinceWind2++
     turnsSinceShield++
     turnsSinceControl++
     turnsSinceControl2++
     turnsSinceControl3++
     for (let i = 0; i < heroesPerPlayer; i++) {
         heroDo(calcTable, i, closestThreat, curMana, masterTable)
         // Write an action using console.log()
         // To debug: console.error('Debug messages...');
 
 
         // In the first league: MOVE <x> <y> | WAIT; In later leagues: | SPELL <spellParams>;
 
     }
 }
 