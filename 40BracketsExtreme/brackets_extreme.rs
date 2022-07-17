use std::io;
use std::collections::HashMap;
use std::collections::HashSet;

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
    let expression = input_line.trim().to_string();
    
    let mut lookup = HashMap::new();
    let mut openers = HashSet::new();
    let mut closers = HashSet::new();
    openers.insert('[');
    openers.insert('(');
    openers.insert('{');
    closers.insert(']');
    closers.insert(')');
    closers.insert('}');
    lookup.insert(']', '[');
    lookup.insert(')', '(');
    lookup.insert('}', '{');

    for i in expression.chars() {
        eprintln!("i is {}", i);
    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("true/false");
}
