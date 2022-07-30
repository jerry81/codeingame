use std::io;
use rand::Rng;
use std::collections::HashSet;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn filter_uniq(vec: Vec<u8>) -> Vec<u8> {
    vec.into_iter()
        .collect::<HashSet<_>>()
        .into_iter()
        .collect()
}
fn main() {
    eprintln!("test filter uniq {:?}", filter_uniq(vec![1,2,3,3]));
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
    let u = filter_uniq(v);
    eprintln!("u is {:?}", u);
    println!("probability");
}
