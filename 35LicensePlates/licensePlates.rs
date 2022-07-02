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
    let x = input_line.trim_matches('\n').to_string();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    eprintln!("input is {:?}", x); // refresher on printing vars
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    // experiments
    let spl: Vec<&str>  = x.split("-").collect();
    eprintln!("spl is {:?}", spl); 
    let aChar = 'A' as u32;
    let zChar = 'Z' as u32;
    // split the input
    // increment the number
    // increment right chars
    // increment left chars 
    eprintln!("achar is {:?}", aChar); // refresher on printing vars

    eprintln!("z is {:?}", zChar); // refresher on printing vars

    println!("AA-000-AA");
}
