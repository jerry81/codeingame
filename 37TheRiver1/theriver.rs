use std::io;
use std::collections::HashSet;


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
    return x + sum
}

fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let mut r_1 = parse_input!(input_line, i64);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let mut r_2 = parse_input!(input_line, i64);
    let mut river1 = HashSet::new();
    let mut river2 = HashSet::new();
    river1.insert(r_1);
    river2.insert(r_2);
    let ans;
    loop {
      let r1 = next_river(r_1);
      let r2 = next_river(r_2);
      if river1.contains(&r2) {
          eprintln!("hashmap is {:?}", river1);
          eprintln!("river contains {}", r2);
          ans = r2;
          break
      }
      if river2.contains(&r1) {
          eprintln!("hashmap is {:?}", river2);
          ans = r1;
          eprintln!("river contains {}", r1);
          break
      }
      r_1 = r1;
      r_2 = r2;
      river1.insert(r1);
      river2.insert(r2);
    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    println!("{}", ans);
}
