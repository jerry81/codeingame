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

    let aChar = 'A' as i32;
    let zChar = 'Z' as i32;
    // split the input
    // increment the number
    let let1 = spl[0];
    let num = spl[1];
    let let2 = spl[2];
    // convert 
    let splS1: Vec<i32> = let1.chars()
    .map(|x| x as i32).collect();
    let splS2: Vec<i32> = let2.chars()
    .map(|x| x as i32).collect();; // first time using rust filter?
    eprintln!("num pre converted is {:?}", num);
    let asi = num.parse::<i32>().unwrap();
    eprintln!("splS1 is {:?}", splS1);
    eprintln!("splS2 is {:?}", splS2);
    eprintln!("asi converted is {:?}", asi);
    // increment right chars
    // increment left chars 
    eprintln!("achar is {:?}", aChar); // refresher on printing vars

    eprintln!("z is {:?}", zChar); // refresher on printing vars

    println!("AA-000-AA");
}
