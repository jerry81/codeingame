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

    let a_char = 'A' as u8;
    let z_char = 'Z' as u8;
    // split the input
    // increment the number
    let let1 = spl[0];
    let num = spl[1];
    let let2 = spl[2];
    // convert 
    let mut spl_s_1: Vec<u8> = let1.chars()
    .map(|x| x as u8).collect();
    let mut spl_s_2: Vec<u8> = let2.chars()
    .map(|x| x as u8).collect();; // first time using rust filter?
    let asi = num.parse::<i32>().unwrap();
    eprintln!("spl_s_1 is {:?}", spl_s_1);
    eprintln!("spl_s_2 is {:?}", spl_s_2);
    let new_num = n + asi;
    let mut new_num_str: String = new_num.to_string();
    if new_num >= 999 {
        eprintln!("newNum test {} ", new_num_str); 
        let times_over = new_num / 999;
        /* 
        notes on division: rust does flooring int division by default
        You can declare the number type like so:
        for more precision, work with floats 
        let x = 7f64;
        let y = 3f64;
        
        println!("{} / {} = {}", x, y, x/y);
        You could probably also use let x = 7.0 in this case.
        */
        let remainder = new_num % 999;
        new_num_str = format!("{:03}", remainder);
        // increment letters
        // do it times_over times 
        // first add to splitS2[1]
        let incr = (spl_s_2[1] - 65) as u32 + times_over as u32;
        if incr > 26 {
            eprintln!("incr overflow is {} ", incr); 
            // handle char overflow
            let times = incr/26;
            let remain = incr%26;
            spl_s_2[1] = (remain + 65) as u8;
            let incr2 = (spl_s_2[0] - 65) as u16 + times as u16; // TODO: DRY
            if incr2 > 26 {
              eprintln!("incr2 overflow is {} ", incr2); 
              let third_times = incr2 / 26;
              let third_remain = incr2 % 26;
              spl_s_2[0] = 65 + third_remain as u8; 
              let incr3 = (spl_s_1[1] - 65) as u16 + third_times as u16;
              if incr3 > 26 {
                let fourth_times = incr3 / 26;
                let fourth_remain = incr3 % 26;
                spl_s_1[1] = 65 + fourth_remain as u8;
                spl_s_1[0] = spl_s_1[0] as u8 + fourth_times as u8;
                
              } else {
                spl_s_1[1] = (65+incr3) as u8;
              }
              // spl_s_1[1] = (spl_s_1[1] as u16 + third_times) as u8;
            } else {
                eprintln!("setting the wrong item {} ", incr2); 
                spl_s_2[0] = (65 + incr2) as u8;
            }
            
        } else {
            spl_s_2[1] = (65 + incr) as u8;
        }
        
        
        
        // a_char is 65
        // z is 90
    }
    let char_arr_1: Vec<char> = spl_s_1.iter().map(|x| *x as char).collect();
    let char_arr_2: Vec<char> = spl_s_2.iter().map(|x| *x as char).collect();
   
    // increment right chars
    // increment left chars 

    /*
    {} is for values that have a lossless, unambiguous representation as a string.,
     e.g. strings and integers. 
     
     {:?} is for debugging and other miscellaneous printing, so it displays quotes on strings.
    */
    let s2: String = char_arr_2.iter().collect();
    let s1: String = char_arr_1.iter().collect();
    println!("{}-{}-{}", s1, new_num_str, s2);
}
