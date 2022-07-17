use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

fn verify(card: String) -> bool {
  let trimmed = card.replace(" ", "");
  
  let chs = trimmed.chars(); // chars() returns iterator
  // let ints = chs.iter().map(|x| x as i8).collect::<Vec<i8>>(); WRONG, this gets the char code
  let ints: Vec<u32> = chs.flat_map(|ch| ch.to_digit(10)).collect(); // flat_map combination of  map() and flatten() 
  // collect turns iter into collection (vector)
  let filtered: Vec<(usize,u32)> = ints.into_iter().enumerate().filter(|(i, _)| i%2 == 0).collect();
  let reversed: Vec<(usize,u32)> = filtered.into_iter().rev().collect();
  for i in reversed {
    eprintln!("i is {:?}", i);
  }
  return true;
}

fn main() {
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    for i in 0..n as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let card = input_line.trim_matches('\n').to_string();
        let res = verify(card);
        eprintln!("res is {}", res);
    }

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("YES or NO");
}
