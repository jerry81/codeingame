use std::io;
use std::collections::HashMap;

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
    let n = parse_input!(input_line, i32); // Number of elements which make up the association table.
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let q = parse_input!(input_line, i32); // Number Q of file names to be analyzed.
    let mut lookup: HashMap<String, String> = HashMap::new();
    for i in 0..n as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let inputs = input_line.split(" ").collect::<Vec<_>>();
        let ext = inputs[0].trim().to_string(); // file extension
        let mt = inputs[1].trim().to_string(); // MIME type.
        lookup.insert(ext, mt);
    }
    let mut answers = [(); 10000].map(|_| String::new());
    for i in 0..q as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let fname = input_line.trim_matches('\n').to_string(); // One file name per line.
        let iter = fname.split(".");
        let mut ext = "";
        let mut flag = true;
        for i in iter {
         if flag {
             flag = false;
             continue;
         }
         ext = i;
        }
        
        eprintln!("fname is {}", ext);
        if lookup.contains_key(ext) {
          eprintln!("answer {}", lookup[ext].to_string());
          answers[i] = lookup[ext].to_string();
        } else {
            eprintln!("UNKNOWN");
            answers[i] = "UNKNOWN".to_string();
        }
    }
    for i in 0..q {
        println!("{}", answers[i as usize])
    }
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    // println!("UNKNOWN");
}
