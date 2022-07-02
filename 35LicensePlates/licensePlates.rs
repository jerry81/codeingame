use std::io;
use std::fmt;

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
    let x = input_line.trim_matches('\n').to_string();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let n = parse_input!(input_line, i32);
    eprintln!("input is {:?}", x); // refresher on printing vars
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    // experiments
    let spl: Vec<&str>  = x.split("-").collect();

    let aChar = 'A' as u8;
    let zChar = 'Z' as u8;
    // split the input
    // increment the number
    let let1 = spl[0];
    let num = spl[1];
    let let2 = spl[2];
    // convert 
    let splS1: Vec<u8> = let1.chars()
    .map(|x| x as u8).collect();
    let splS2: Vec<u8> = let2.chars()
    .map(|x| x as u8).collect();; // first time using rust filter?
    let asi = num.parse::<i32>().unwrap();
    eprintln!("splS1 is {:?}", splS1);
    eprintln!("splS2 is {:?}", splS2);
    eprintln!("asi converted is {}", asi);
    let newNum = n + asi;
    let mut newNumStr: String = newNum.to_string();
    let mut incrStr: char = 'X';
    if newNum > 999 {
        let timesOver = newNum / 999;
        /* 
        notes on division: rust does flooring int division by default
        You can declare the number type like so:
        for more precision, work with floats 
        let x = 7f64;
        let y = 3f64;
        
        println!("{} / {} = {}", x, y, x/y);
        You could probably also use let x = 7.0 in this case.
        */
        let remainder = newNum % 999;
        eprintln!("timesOver test {} ", timesOver); 
        eprintln!("format test {} ", format!("{:03}", 42)); 
        newNumStr = format!("{:03}", remainder);
        // increment letters
        // do it timesover times 
        // first add to splitS2[1]
        let incr = splS2[1] + timesOver as u8;
        if incr > 90 {
            // handle char overflow
        }
        eprintln!("incr test {} ", incr); 
        incrStr = incr as char;
        eprintln!("incrStr test {} ", incrStr); 
        // achar is 65
        // z is 90
    }
    let charArr2: Vec<char> = splS2.iter().map(|x| *x as char).collect();
    eprintln!("newNum is {}", newNum);
    eprintln!("newNumStr is {}", newNumStr);
    // increment right chars
    // increment left chars 
    eprintln!("achar is {}", aChar); // refresher on printing vars

    eprintln!("z is {}", zChar); // refresher on printing vars

    /*
    {} is for values that have a lossless, unambiguous representation as a string.,
     e.g. strings and integers. 
     
     {:?} is for debugging and other miscellaneous printing, so it displays quotes on strings.
    */
    let s2: String = charArr2.iter().collect();
    println!("{}-{}-{}", spl[0], newNumStr, s2);
}
