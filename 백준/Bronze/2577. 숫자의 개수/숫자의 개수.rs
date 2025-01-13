use std::io::{stdin, Read};
use std::fmt::Write;

fn main() 
{
    let mut out = String::new();
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let v: Vec<i64> = input.split_ascii_whitespace().flat_map(str::parse).collect();
    let mut pivot = 1;
    for i in v
    {
        pivot *= i;
    }
    let mut ans = [0;10];
    let s = format!("{}",pivot);
    for ch in s.chars()
    {
        let idx = ch.to_digit(10).unwrap() as usize;
        ans[idx] += 1;
    }
    for i in &ans
    {
        writeln!(out,"{}",i).unwrap();
    }
    println!("{}",out)
}