// use std::io;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut v = vec![87, 19, 72, 59, 22, 74, 89, 30, 33, 3, 66, 77, 15, 23, 58, 82, 56, 98, 1, 84];
    v.sort();
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("v is {:?}", v);
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

 1> 2> 6> 7>   10> <14  <20
     2>  4>     8>  9>    <12>    <18
        3>    5>       9> 10>  <10.5>  <17
next state?


*/

