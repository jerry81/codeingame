use std::io;
use rand::Rng;

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
    // pick m uniques out of n tries
    let mut v:Vec<u8> = Vec::new();
    let mut rng = rand::thread_rng();
    for _ in 0..n {
        let random = rng.gen_range(0..38);
        v.push(random);
    }
    println!("probability");
}
