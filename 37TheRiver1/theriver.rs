use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn nextRiver(x:i64) -> i64 {
    let as_str = x.to_string();
    eprintln!("as_str {}", as_str);
    return 55
}

fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let r_1 = parse_input!(input_line, i64);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let r_2 = parse_input!(input_line, i64);
    nextRiver(r_1);
    nextRiver(r_2);
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("42");
}
