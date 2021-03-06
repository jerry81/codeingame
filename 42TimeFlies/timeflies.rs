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
    lookup.insert(11,30);
    lookup.insert(12,31);


    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let begin = input_line.trim().to_string();
    let mut input_line = String::new();
    io::stdin().read_line(&mut input_line).unwrap();
    let end = input_line.trim().to_string();
    let bs:Vec<&str> = begin.split('.').collect();
    let es:Vec<&str>= end.split('.').collect();
    let endyear = es[2].parse::<i32>().unwrap();
    let startyear = bs[2].parse::<i32>().unwrap();
    let endmonth = es[1].parse::<i32>().unwrap();
    let startmonth = bs[1].parse::<i32>().unwrap();
    let endday = es[0].parse::<i32>().unwrap();
    let startday = bs[0].parse::<i32>().unwrap();
    let yeardiff = endyear - startyear;
    let monthdiff = endmonth - startmonth;
    let daydiff = endday - startday;
    let mut totalDays = 0;
    let mut totalYears = yeardiff;
    let mut totalMonths = monthdiff;
    if daydiff < 0 {
      totalMonths -= 1;
    }
    if monthdiff < 0 {
      totalYears -= 1;
      totalMonths += 12;
    }

    // calculate total days
    for year in startyear..endyear+1 {
      eprintln!("iterating year {}", year);
      let sm = if year == startyear { startmonth } else { 1 };
      let em = if year == endyear { endmonth+1 } else { 13 };
      for m in sm..em {
        eprintln!("iterating month {}", m);
        let sd = if year == startyear && m == startmonth { startday } else { 0 };
        let mut ed = if year == endyear && m == endmonth { endday } else { *lookup.get(&m).unwrap() };
        if is_leap_year(year) && m == 2 && ed == 28 {
            ed = 29;
        }
        eprintln!("sd and ed are {} and {}", sd, ed);
        totalDays += ed - sd;
      }
    }

    let yearstr = if totalYears > 0 { format!("{} year{}, ",totalYears, if totalYears > 1 { "s" } else { "" }).to_string() } else { "".to_string() };
    let monthstr = if totalMonths == 0 { "".to_string() } else { format!("{} month{}, ", totalMonths, if totalMonths > 1 { "s" } else { "" }).to_string() };
    println!("{}{}total {} days", yearstr,monthstr,totalDays);
}
