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
    let r_1 = parse_input!(input_line, i64);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let r_2 = parse_input!(input_line, i64);

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("42");
}
