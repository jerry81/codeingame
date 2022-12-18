use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Horse {
    v: i32,
    e: i32,
    s: i32
}
fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    let mut horses = Vec::new();
    for i in 0..n as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        let v = parse_input!(inputs[0], i32);
        let e = parse_input!(inputs[1], i32);
        let s = v+e;
        let h = Horse {
          v: v,
          e: e,
          s: s
        };
        horses.push(h);
    }
    horses.sort_by(|a, b| b.s.cmp(&a.s));
    eprintln!("horses len is {}", horses.len());
    let mut min = std::i32::MAX;
    for i in 0..horses.len()-1 {
      let horse1 = &horses[i];
      for j in i..horses.len() {
        let horse2 = &horses[j];
        let diff = (horse1.v - horse2.v).abs() + (horse1.e - horse2.e).abs();
        if diff < min {
            min = diff;
        }
      }
      
    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("{}", min);
}


// 147615