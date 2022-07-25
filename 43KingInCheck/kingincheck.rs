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
          "Q"=>{
            let dx = king.x as i8 - enemy.x as i8;
            let dy = king.y as i8 - enemy.y as i8;
            let no_diag = dx.abs() != dy.abs();
            let no_line = enemy.x != king.x && enemy.y != king.x;
            if no_diag && no_line {
              returned = "No Check";
            }
          },
          "R"=>{
            if enemy.x != king.x && enemy.y != king.x {
              returned = "No Check";
            }
          },
          "B"=>{
            let dx = king.x as i8 - enemy.x as i8;
            let dy = king.y as i8 - enemy.y as i8;
            if dx.abs() != dy.abs() {
              returned = "No Check";
            }
          },
          _=> unreachable!()
        }

    // Write an answer using println!("message...");
    // To debug: eprintln!("Debug message...");

    println!("{}", returned);
}


/*

bishop analysis:

0,0                     0,8
   1,1               1,7
      2,2         2,6
         3,3   3,5
            4,4
         5,3   5,5
      6,2         6,6
   7,1
8,0

dx, dy
-1,-1
1,-1
-1,1
*/

