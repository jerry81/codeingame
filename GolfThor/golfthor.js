/**
 * Solve this puzzle by writing the shortest code.
 * Whitespaces (spaces, new lines, tabs...) are counted in the total amount of chars.
 * These comments should be burnt after reading!
 **/

 var i = readline().split(' ');
 const LX = +i[0]; // the X position of the light of power
 const LY = +i[1]; // the Y position of the light of power
 const TX = +i[2]; // Thor's starting X position
 const TY = +i[3]; // Thor's starting Y position
 let w = TX - LX // thor to right - 21 - so we need 21 W's
 let h = TY - LY // thor in line - 0 
 let a,b
 // game loop
 while(1){
     if (!w) {
         a = ''
     } else if (w > 0) {
         a="W";w--
     } else { 
        a="E";w++
     }
     if (!h) {
         b=''
     } else if (h>0){
         b="N";h-- 
     } else {
         b="S";h++
     }
     console.log(`${b}${a}`)
  //   const remainingTurns = parseInt(readline()); // The level of Thor's remaining energy, representing the number of moves he can still make.
 
     // Write an action using console.log()
     // To debug: console.error('Debug messages...');
 
 
     // A single line providing the move to be made: N NE E SE S SW W or NW
 }
 