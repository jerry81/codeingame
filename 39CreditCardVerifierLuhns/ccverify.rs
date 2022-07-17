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
  let filtered: Vec<(usize,u32)> = ints.clone().into_iter().enumerate().filter(|(i, _)| i%2 == 0).collect();
  let filtered2: Vec<(usize,u32)> = ints.clone().into_iter().enumerate().filter(|(i, _)| i%2 != 0).collect();
  let indexdrop: Vec<u32> = filtered.iter().map(|(_,x)| *x).collect();
  let indexdrop2: Vec<u32> = filtered2.iter().map(|(_,x)| *x).collect();
  let reversed: Vec<u32> = indexdrop.into_iter().rev().collect();
  let doubled: Vec<u32> = reversed.into_iter().map(|x| x*2).collect();
  // let normalized: Vec<(usize,u32)> = doubled.into_iter().map(|(i,x)| (i,x >= 10 ? x-9 : x)).collect(); RUST DOESNT have ternary
  let normalized: Vec<u32> = doubled.into_iter().map(|x| if x >= 10 {x-9}  else {x}).collect();
  let _sum: u32 = normalized.iter().sum();
  let _sum2: u32 = indexdrop2.iter().sum();
  for i in normalized {
    eprintln!("i is {:?}", i);
  }
  eprintln!("_sum is {:?}", _sum);
  eprintln!("_sum2 is {:?}", _sum2);
  return ((_sum + _sum2) % 10) == 0 ;
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
        println!("{}", if res {"YES"} else {"NO"});
    }

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    
}
