use std::io;
use std::collections::HashMap;
use std::fmt;

macro_rules! parse_input {
    ($x:expr, $t:ident) => ($x.trim().parse::<$t>().unwrap())
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

fn is_leap_year(year:i32) -> bool {
    if year % 4 != 0 {
        return false
    } 
    if year % 100 == 0 {
        return year % 400 == 0
    } 
    return true
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
    let mut totalDays = 0;
    let mut totalYears = 0;
    let mut totalMonths = 0;
    for i in (bs[2].parse::<i32>().unwrap()+1..es[2].parse::<i32>().unwrap()).rev() {
        if is_leap_year(i) {
            totalDays+=366;
        } else {
            totalDays+=365;
        }
        totalYears +=1;
    }
    eprintln!("monthdiff {} daydiff {}", monthdiff, daydiff);
    if monthdiff == 0 && daydiff == 0 {
      if is_leap_year(bs[2].parse::<i32>().unwrap()) {
        totalDays+=366;
      } else {
        totalDays+=365;
      }
      totalYears+=1;
    }
    totalMonths = monthdiff.abs();
    let yearstr = if totalYears > 0 { format!("{} year{}, ",totalYears, if totalYears > 1 { "s" } else { "" }).to_string() } else { "".to_string() };
    let monthstr = if monthdiff == 0 { "".to_string() } else { format!("{} month{}, ", totalMonths, if totalMonths > 1 { "s" } else { "" }).to_string() };
    println!("{}{}total {} days", yearstr,monthstr,totalDays);
}
