use std::io;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

fn verify(card: String) -> bool {
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
