use std::io;
use std::cmp;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut ans:f32 = 0f32;
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let l = parse_input!(input_line, i32);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    let mut inputs = String::new();
    io::stdin().read_line(&mut inputs).unwrap();
    let mut balls:Vec<i32> = Vec::new();
    for i in inputs.split_whitespace() {
        let b = parse_input!(i, i32);
        balls.push(b);
    }
    if n == 1 {
        ans = cmp::max(balls[0], l-balls[0]) as f32;
    }
    if n == 2 {
        let mid = balls[0] + balls[1] / 2;
        ans += (cmp::max(balls[0],balls[1]) - mid) as f32;
        ans += cmp::max(l-mid, mid) as f32;
    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("{}",ans.round());
}

/* analysis
103 - length of pipe
20 - number of bots
87 19 72 59 22 74 89 30 33 3 66 77 15 23 58 82 56 98 1 84

expected answer 103

1 3 
*/

