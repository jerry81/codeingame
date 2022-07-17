use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let m = parse_input!(input_line, i32);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    // probability of m uniques + prob of m+1 uniques to n uniques 
    // 6 out of 7 
    // 38 * 37 * 36 * 35 * 34 * 33 * 6
    // over
    // 38^6
    // 7 out of 7 
    // 38*37*36*35*34*33*32
    // 38^7
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("probability");
}
