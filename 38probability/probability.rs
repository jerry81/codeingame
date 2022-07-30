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

    let mut successes = 0;
    for i in 0..1000000 {
        let mut v:Vec<u8> = Vec::new();
        let mut rng = rand::thread_rng();
        for _ in 0..n {
            let random = rng.gen_range(0..38);
            v.push(random);
        }
        let u = filter_uniq(v);
        if u.len() as i32 >= m {
            successes += 1;
        }
    }
    eprintln!("succ is {}", successes);
    format!("{:.2}", 1.2399);
    let prob = (100.00 * (successes as f32 / 1000000 as f32)).round();
    eprintln!("prob is {}", prob);
    println!("{}%", prob);
}
