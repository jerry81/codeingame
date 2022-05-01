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
    let message = input_line.trim_matches('\n').to_string();

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    let mut name_in_binary = "".to_string();

    for character in message.clone().into_bytes() {
        name_in_binary += &format!("0{:b} ", character);
    }
    name_in_binary.retain(|c| !c.is_whitespace());
    
    eprintln!("in binary {}", name_in_binary);
    println!("answer");
}
