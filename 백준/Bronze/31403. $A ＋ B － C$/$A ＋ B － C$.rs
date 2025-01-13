use std::io::{stdin, Read};
use std::fmt::Write;

fn main() 
{
    let mut out = String::new();
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let v: Vec<i64> = input.split_ascii_whitespace().flat_map(str::parse).collect();
    let mut ans = 0;
    for i in 0..2
    {
        ans += v[i];
    }
    ans -= v[2];
    writeln!(out, "{ans}").unwrap();
    let ab = format!("{}{}",v[0],v[1]);
    let abb: i64 = ab.parse().unwrap();
    writeln!(out,"{}", abb - v[2]).unwrap();
    println!("{out}")
}