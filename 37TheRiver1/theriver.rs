use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn next_river(x:i64) -> i64 {
    let as_str = x.to_string();
    let mut sum = 0;
    for c in as_str.chars() {
        sum+=(c.to_string()).parse::<i64>().unwrap();
        
    }
    eprintln!("sum {}", sum);
    return 55
}

fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let r_1 = parse_input!(input_line, i64);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let r_2 = parse_input!(input_line, i64);
    next_river(r_1);
    next_river(r_2);
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("42");
}
