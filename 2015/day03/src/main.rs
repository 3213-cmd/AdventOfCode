use std::fs;
use std::collections::HashSet;
// IDEA use a vector and a hashmap?

fn main() {
    // Our location on the "map", starts at x = 0, y = 0
    let mut position_santa :[i32;2] = [0,0];
    let mut position_robo_santa :[i32;2] = [0,0];
    let mut visited_houses = HashSet::new();
    let mut visited_houses_next_year = HashSet::new();
    // Insert the starting position
    visited_houses.insert([0, 0]);
    visited_houses_next_year.insert([0,0]);
    // read chars from input.txt line by line
    // File needs to be at root level.
    let contents = fs::read_to_string("input.txt")
        .expect("Should have been able to read the file");
    // Some interesting insights that do not apply here,though. https://stackoverflow.com/questions/22118221/how-do-you-iterate-over-a-string-by-character
    for c in contents.chars() {
        if c == '>' {position_santa[0] += 1};
        if c == '<' {position_santa[0] -= 1};
        if c == '^' {position_santa[1] += 1};
        if c == 'v' {position_santa[1] -= 1};
        visited_houses.insert([position_santa[0], position_santa[1]]);
    }

    // Part Two
    let mut santas_turn = true;
    position_santa = [0,0];
    for c in contents.chars() {
        if c == '>' && santas_turn {position_santa[0] += 1};
        if c == '>' && !santas_turn {position_robo_santa[0] += 1};
        if c == '<' && santas_turn {position_santa[0] -= 1};
        if c == '^' && !santas_turn {position_robo_santa[1] += 1};
        if c == 'v' && santas_turn {position_santa[1] -= 1};
        if c == '<' && !santas_turn {position_robo_santa[0] -= 1};
        if c == '^' && santas_turn {position_santa[1] += 1};
        if c == 'v' && !santas_turn {position_robo_santa[1] -= 1};
        if santas_turn {
            visited_houses_next_year.insert([position_santa[0], position_santa[1]]);
            santas_turn = false;}
        else {
            visited_houses_next_year.insert([position_robo_santa[0], position_robo_santa[1]]);
            santas_turn = true;
        }
    }


    // Works as intended.
    println!("Visited Houses: { }", visited_houses.len());
    println!("Visited Houses The Year After: { }", visited_houses_next_year.len());
}
