use std::io;
use std::collections::HashSet;

fn main() {
    let mut hs = HashSet::new();
    hs.insert(15);
    println!("hs contains 15 {:?}", hs.contains(&15));
}
