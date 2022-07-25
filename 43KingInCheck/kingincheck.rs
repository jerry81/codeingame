use std::io;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
fn main() {
  struct Enemy {
    x: usize,
    y: usize,
    piece: String
  }

  struct King {
    x: usize,
    y: usize
  }

  let mut king = King {
    x: 0,
    y: 0
  };

  let mut enemy = Enemy {
    x: 0,
    y: 0,
    piece: "".to_string()
  };
    for i in 0..8 as usize {
        let mut input_line = String::new();
        io::stdin().read_line(&mut input_line).unwrap();
        let chess_row = input_line.trim_matches('\n').to_string();
        let chess_chars: Vec<&str> = chess_row.split(" ").collect();


        for j in 0..8 as usize {
          let c = chess_chars[j];
          if c == "K" {
            king.x = j;
            king.y = i;
          }
          else if c != "_" {
            enemy.x = j;
            enemy.y = i;
            enemy.piece = c.to_string();
          }
        }


    }
    let p = enemy.piece;
        let mut returned = "Check";
        // one of B, N, R, Q
        match p.as_str() {
          "N"=>eprintln!("knight"),
          "Q"=>eprintln!("queen"),
          "R"=>{
            if enemy.x != king.x && enemy.y != king.x {
              returned = "No Check";
            }
          },
          "B"=>eprintln!("bishop"),
          _=> unreachable!()
        }

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("{}", returned);
}
