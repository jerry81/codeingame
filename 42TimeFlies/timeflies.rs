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
    let begin = input_line.trim().to_string();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let end = input_line.trim().to_string();
    let bs:Vec<&str> = begin.split('.').collect();
    let es:Vec<&str>= end.split('.').collect();
    let yeardiff = es[2].parse::<i32>().unwrap() - bs[2].parse::<i32>().unwrap();
    let monthdiff = es[1].parse::<i32>().unwrap() - bs[1].parse::<i32>().unwrap();
    let daydiff = es[0].parse::<i32>().unwrap() - bs[0].parse::<i32>().unwrap();
    eprintln!("bs is {:?}", bs);
    eprintln!("es is {:?}", es);
    eprintln!("yeardiff is {:?}", yeardiff);
    eprintln!("monthdiff is {:?}", monthdiff);
    eprintln!("daydiff is {:?}", daydiff);
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("YY year[s], MM month[s], total NN days");
}
