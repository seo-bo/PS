use std::io::{self, BufRead, BufReader, Write, BufWriter};
use std::collections::VecDeque;

fn main() 
{
    let stdin = io::stdin();
    let stdout = io::stdout();
    let mut reader = BufReader::new(stdin.lock());
    let mut writer = BufWriter::new(stdout.lock());

    let mut input = String::new();
    reader.read_line(&mut input).unwrap();
    let mut parts = input.split_whitespace().flat_map(str::parse::<isize>);
    let n: isize = parts.next().unwrap();
    let k: isize = parts.next().unwrap();

    let mut grid = vec![Vec::new(); 2];
    for i in 0..2 
    {
        input.clear();
        reader.read_line(&mut input).unwrap();
        grid[i] = input.trim().chars().collect::<Vec<_>>();
    }

    let directions = [(0, 1), (0, -1), (1, 0)];
    let mut visited = vec![vec![false; n as usize]; 2];
    let mut check = false;

    let mut bfs = || 
    {
        let mut q: VecDeque<(isize, isize, isize)> = VecDeque::new();
        visited[0][0] = true;
        q.push_back((0, 0, 0));

        while let Some((pos, lane, time)) = q.pop_front()
         {
            if pos >= n 
            {
                check = true;
                return;
            }

            for &(dx, dy) in &directions 
            {
                let new_lane = if dx == 1 { 1 - lane } else { lane };
                let new_pos = pos + dy + if dx == 1 { k } else { 0 };

                if new_pos >= n 
                {
                    check = true;
                    return;
                }

                if new_pos > time && new_pos >= 0 && new_pos < n && !visited[new_lane as usize][new_pos as usize] && grid[new_lane as usize][new_pos as usize] == '1' 
                {
                    visited[new_lane as usize][new_pos as usize] = true;
                    q.push_back((new_pos, new_lane, time + 1));
                }
            }
        }
    };

    bfs();
    writeln!(writer, "{}", if check { 1 } else { 0 }).unwrap();
}