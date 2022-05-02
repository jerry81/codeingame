/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 const N = parseInt(readline());
 let sum = 0
 for (let i = 0; i < N; i++) {
 
     for (let j = 0; j < N; j++) {
         const value = parseInt(readline());
         if (j > i)  {
           sum += value
         }
     }
 }
 
 // Write an answer using console.log()
 // To debug: console.error('Debug messages...');
 
 console.log(sum);
 