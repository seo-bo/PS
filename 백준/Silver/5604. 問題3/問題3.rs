use std::io::{self, Read};
use std::fmt::Write;
fn main() 
{
    let mut input = String::new();
    let mut output = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut v = vec![];
    let mut current = vec![];
    dfs(&mut v, &mut current, n, n);
    for k in v {
        let line = k
            .iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ");
        writeln!(output,"{}",line).unwrap();
    }
    println!("{}", output);
}

fn dfs(v: &mut Vec<Vec<usize>>, current: &mut Vec<usize>, n: usize, start: usize) 
{
    if n == 0 
    {
        v.push(current.clone());
        return;
    }
    for i in (1..=start).rev() 
    {
        if i <= n {
            current.push(i);
            dfs(v, current, n - i, i);
            current.pop();
        }
    }
}