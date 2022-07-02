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
    eprintln!("asi converted is {}", asi);
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
        eprintln!("times_over test {} ", times_over); 
        eprintln!("format test {} ", format!("{:03}", 42)); 
        new_num_str = format!("{:03}", remainder);
        // increment letters
        // do it times_over times 
        // first add to splitS2[1]
        let mut incr = spl_s_2[1] as u16 + times_over as u16;
        if incr > 90 {
            // handle char overflow
            let times = (incr-65)/26;
            let remain = (incr-65)%26;
            incr = 65 + remain as u16;
            eprintln!("incr test {} ", incr);
            eprintln!("times test {} ", times); 
            eprintln!("remain test {} ", remain); 
            if times > 26 {
              eprintln!("times is {} ", times); 
              eprintln!("orig is {} ", spl_s_1[1]);  
              let third_times = times / 26;
              let third_remain = times % 26;
              eprintln!("third_times test {} ", third_times); 
              eprintln!("third_remain test {} ", third_remain);
              spl_s_1[1] = (spl_s_1[1] as u16 + third_times) as u8;
              spl_s_2[0] += (third_remain) as u8;
            } else {
                spl_s_2[0] += times as u8;
            }
            
        }
        
        
        spl_s_2[1] = incr as u8;
        // a_char is 65
        // z is 90
    }
    let char_arr_1: Vec<char> = spl_s_1.iter().map(|x| *x as char).collect();
    let char_arr_2: Vec<char> = spl_s_2.iter().map(|x| *x as char).collect();
    eprintln!("new_num is {}", new_num);
    eprintln!("new_num_str is {}", new_num_str);
    // increment right chars
    // increment left chars 
    eprintln!("a_char is {}", a_char); // refresher on printing vars

    eprintln!("z is {}", z_char); // refresher on printing vars

    /*
    {} is for values that have a lossless, unambiguous representation as a string.,
     e.g. strings and integers. 
     
     {:?} is for debugging and other miscellaneous printing, so it displays quotes on strings.
    */
    let s2: String = char_arr_2.iter().collect();
    let s1: String = char_arr_1.iter().collect();
    println!("{}-{}-{}", s1, new_num_str, s2);
}
