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
    let l = parse_input!(input_line, i32);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let h = parse_input!(input_line, i32);
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let t = input_line.trim_matches('\n').to_string();
    let mut lookup = [(); 5].map(|_| String::new());
    for i in 0..h as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let row = input_line.trim_matches('\n').to_string();
        lookup[i] = row;
    }
    let mut answers = [(); 5].map(|_| String::new());
    let mut index: u32 = 0;
    for c in t.bytes() { 
        // do something with `c`
        eprintln!("{:?}", c);
        // convert byte to position
        // 65 - 90 A-Z
        // 97 - 122 a-z 
        if c >= 65 && c <= 90 {
          // slice out [((c - 65) * l), (c-64)*l] 
          continue;
        }
        if c >= 97 && c <= 122 {
          continue;
        }
        // use the ?

    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    eprintln!("lookup is {}", lookup[0]);
    eprintln!("lookup is {}", lookup[1]);
    eprintln!("lookup is {}", lookup[2]);
    eprintln!("lookup is {}", lookup[3]);
    eprintln!("lookup is {}", lookup[4]);
    println!("{}", answers[0]);
    println!("{}", answers[1]);
    println!("{}", answers[2]);
    println!("{}", answers[3]);
    println!("{}", answers[4]);
}
