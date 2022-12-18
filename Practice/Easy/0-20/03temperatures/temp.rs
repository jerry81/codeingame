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
    let n = parse_input!(input_line, i32); // the number of temperatures to analyse
    let mut inputs = String::new();
    io::stdin().read_line(&mut inputs).unwrap();
    let mut min:i32 = 100000;
    for i in inputs.split_whitespace() {
        let t = parse_input!(i, i32);
        let abs = t.abs();
        let minabs = min.abs();
        if abs < minabs {
            min = t;
        } else if abs == minabs {
            if t > 0 {
                min = t
            }
        }
    }
    if min > 10000 {
        min = 0
    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    println!("{}", min)
}
