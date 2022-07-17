use std::io;
use std::collections::HashMap;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

fn is_leap_year(year:int<i32>) -> bool {
    if (year % 4 != 0) {
        return false
    }
    return (year % 100 == 0 && year % 400 == 0)
}
fn main() {
    let mut lookup = HashMap::new();
    lookup.insert(1,31);
    lookup.insert(2,28);
    lookup.insert(3,31);
    lookup.insert(4,30);
    lookup.insert(5,31);
    lookup.insert(6,30);
    lookup.insert(7,31);
    lookup.insert(8,31);
    lookup.insert(9,30);
    lookup.insert(10,31);
    lookup.insert(11,31);
    lookup.insert(12,31);
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
    eprintln!("2000 isLeapyear is {:?}", is_leap_year(2000));
    eprintln!("2001 isLeapyear is {:?}", is_leap_year(2001));
    eprintln!("1900 isLeapyear is {:?}", is_leap_year(1900));
    println!("YY year[s], MM month[s], total NN days");
}
