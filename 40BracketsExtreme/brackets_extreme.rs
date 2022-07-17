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
    let expression = input_line.trim().to_string();
    
    let lookup = HashMap::new();
    let openers = HashSet::new();
    let closers = HashSet::new();
    openers.insert('[');
    openers.insert('(');
    openers.insert('{');
    closers.insert(']');
    closers.insert(')');
    closers.insert('}');
    lookup.insert(']', '[');
    lookup.insert(')', '(');
    lookup.insert('}', '{');
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("true/false");
}
