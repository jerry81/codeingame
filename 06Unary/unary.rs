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
    let message = input_line.trim_matches('\n').to_string();
    eprintln!("{}", message);
    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");
    let mut name_in_binary = "".to_string();

    for character in message.clone().into_bytes() {
        name_in_binary += &format!("0{:b} ", character);
    }

    //  name_in_binary.retain(|c| !c.is_whitespace());
    
    let st_ar = name_in_binary.split(" ");
   
    
    let mut answer = String::new();
    let mut cur: i8 = 2; // 2 unset, 1 if currently 1, 0 if currently 0
    for st in st_ar {
        let mut first: bool = true;
        if st.len() == 7 {
            first = false;
        }
        for c in st.chars() {
            if first {
                first = false;
                continue;
            }
            if cur == 2 {
              // print a "first" block
              // set cur 
              // start the count 
              if c == '1' {
                  answer += "0 0";
                  cur = 1;
              } else {
                  answer += "00 0";
                  cur = 0;
              }
            } else if cur == 1 {
                if c == '1' {
                  answer += "0"
                } else {
                  cur = 0;
                  answer += " 00 0"
                }
            } else {
                if c == '0' {
                  answer += "0"
                } else {
                  cur = 1;
                  answer += " 0 0"
                }
            }
        }
    }
   
    eprintln!("in binary {}", name_in_binary);
    println!("{}", answer);
}
