use std::io;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
    for i in 0..8 as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let chess_row = input_line.trim_matches('\n').to_string();
        let chess_chars: Vec<char> = chess_row.chars().collect();
        for j in 0..8 as usize {
          let c = chess_chars[j];
          eprintln!("c is {}", c);
        }
    }

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("Check/No Check");
}
