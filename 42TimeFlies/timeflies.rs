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
    let mut totalYears = 0;
    let mut totalMonths = 0;

    // days remainder
    // same month case
    if endmonth == startmonth {
      if startday < endday {
        totalDays += endday - startday;
      } else {
        // it's a wraparound  i.e. 3/20/2000 - 3/19/2001
        //
      }
    }

    // year diff > 1 i.e. 2015 to 2017
    // just count 2016 as a full year
    if yeardiff > 1 {
      for i in (startyear+1..endyear).rev() {
        if is_leap_year(i) {
            totalDays+=366;
        } else {
            totalDays+=365;
        }
        totalYears +=1;
      }
    }
    if monthdiff == 0 && daydiff == 0 {
      if is_leap_year(bs[2].parse::<i32>().unwrap()) {
        totalDays+=366;
      } else {
        totalDays+=365;
      }
      totalYears+=1;
    }
    eprintln!("total days is now {}", totalDays);
    if monthdiff < 0 {
        // this means start month > end month
        let mut months: Vec<i32> = Vec::new();
        totalMonths += es[1].parse::<i32>().unwrap() - 1;
        for m in (1..es[1].parse::<i32>().unwrap()).rev() {
            months.push(m);
            totalDays += lookup.get(&m).unwrap();
            if m == 2 && is_leap_year(es[2].parse::<i32>().unwrap()) {
                eprintln!("adding leap");
                totalDays+=1;
            }
        }
        totalDays += es[0].parse::<i32>().unwrap() - 1;
        totalMonths += 12 - bs[1].parse::<i32>().unwrap();
        if bs[0].parse::<i32>().unwrap() == 1 {
          totalMonths += 1;
        }
        for m in (bs[1].parse::<i32>().unwrap()+1)..13 {
            months.push(m);
            totalDays += lookup.get(&m).unwrap();
            if m == 2 && is_leap_year(es[2].parse::<i32>().unwrap()) {
                totalDays+=1;
            }
        }
        let remaining_days = lookup.get(&bs[1].parse::<i32>().unwrap()).unwrap() - bs[0].parse::<i32>().unwrap();
        totalDays+=remaining_days;

        eprintln!("months is {:?}", months);
    } else {
        let mut months: Vec<i32> = Vec::new();
        totalMonths = monthdiff;
        for m in (bs[1].parse::<i32>().unwrap()..es[1].parse::<i32>().unwrap()).rev() {
            months.push(m);
        }
        for m in months {
            totalDays += lookup.get(&m).unwrap();
            if m == 2 && is_leap_year(es[2].parse::<i32>().unwrap()) {
                totalDays+=1;
            }
        }
    }
    let yearstr = if totalYears > 0 { format!("{} year{}, ",totalYears, if totalYears > 1 { "s" } else { "" }).to_string() } else { "".to_string() };
    let monthstr = if totalMonths == 0 { "".to_string() } else { format!("{} month{}, ", totalMonths, if totalMonths > 1 { "s" } else { "" }).to_string() };
    println!("{}{}total {} days", yearstr,monthstr,totalDays);
}

/*
analysex
28.02.2015
13.04.2018
3 years, 1 month, total 1140 days

begin date > end date so
count up to end of month
1 day from feb
13 days in april = 14 dangling days

march is a full month

then add 3 full years
*/