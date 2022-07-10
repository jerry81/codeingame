// use std::io;
use std::cmp;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut v = vec![87, 19, 72, 59, 22, 74, 89, 30, 33, 3, 66, 77, 15, 23, 58, 82, 56, 98, 1, 84];
    v.sort();
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    let rounded = (1.5f32).round();
    println!("v is {:?}", v);
    println!("rounded is {}", rounded);
    let mut ans = 0f32;
    let mid:f32 = 5f32 / 2f32;
    eprintln!("mid is {}", mid);
    ans += (cmp::max(0,5) as f32 - mid) as f32;
    ans += mid.max(3f32);
    println!("ans is {}",ans);
}

/* analysis
103 - length of pipe
20 - number of bots
87 19 72 59 22 74 89 30 33 3 66 77 15 23 58 82 56 98 1 84

expected answer 103

1 3 15 19 .... 98

20
7
1 2 20 7 6 10 14

1 2     6 7  10 14      20

ans 20 

midpoint 20+1 / 2 = 10.5

 1> 2> 6> 7>   10> <14  <20 2 sec
3>  5>     8>  9>    <12>    <18  1.5 sec
3.5>    5.5>   9.5>  <10.5>  13.5>   <16.5 .5 sec
4>     6>        <10> 11>  14> <16  .5 sec
5>   7>      <9   11.5>  12>   <15> 1 sec
6>     <8>   12.5>   13>  <14  16>  .5 
6.5>       <7.5  8.5>     13>     <13.5>  16.5> .25?
6.75>  <7.25 8.75>   <13.25>  13.75>  .25
    <7>  9>  <13  13.5>   2
     9>      <11>  1
         <10> 9.5 + 10 = 19.5

*/

