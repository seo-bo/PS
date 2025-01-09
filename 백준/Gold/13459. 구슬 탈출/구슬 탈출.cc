#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

struct biz
{
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};

int row = 0, col = 0;
int dr[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int visited[11][11][11][11] = { 0, };
string grid[10];

biz move(int x, int y, int dir)
{
	int dis = 0;
	while (grid[x + dr[dir][0]][y + dr[dir][1]] != '#' && grid[x][y] != 'O') // 구멍에 도달하면 끝이 나야하므로
	{
		x += dr[dir][0];
		y += dr[dir][1];
		dis++;
	}
	return { x,y,0,0, dis };
}

int bfs(int rx, int ry, int bx, int by)
{
	queue<biz>q;
	q.push({ rx,ry,bx,by,0 });
	visited[rx][ry][bx][by] = 1;
	while (!q.empty())
	{
		biz cur = q.front();
		q.pop();
		if (cur.cnt >= 10) // 이미 여기 왔는데 10인거 자체가 11번째 구슬을 체크하려는 목적
		{
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			biz red = move(cur.rx, cur.ry, i); // 매번 조건 분기로 검사하지말고, 만약 움직였을때 같이 있는거면 더 많이 움직인놈이 우선되야하는거잖아
			biz blue = move(cur.bx, cur.by, i);
			if (grid[blue.rx][blue.ry] == 'O')
			{
				continue;
			}
			if (grid[red.rx][red.ry] == 'O')
			{
				return 1;
			}
			if (red.rx == blue.rx && red.ry == blue.ry)
			{
				if (red.cnt > blue.cnt)
				{
					red.rx -= dr[i][0];
					red.ry -= dr[i][1];
				}
				else
				{
					blue.rx -= dr[i][0];
					blue.ry -= dr[i][1];
				}
			}
			if (!visited[red.rx][red.ry][blue.rx][blue.ry]) // 같은곳을 재방문 하진 않을거고
			{
				q.push({ red.rx, red.ry,blue.rx, blue.ry, cur.cnt + 1 });
				visited[red.rx][red.ry][blue.rx][blue.ry] = 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int rx = 0, ry = 0, bx = 0, by = 0;
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		cin >> grid[i];
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == 'R')
			{
				rx = i; ry = j;
			}
			else if (grid[i][j] == 'B')
			{
				bx = i; by = j;
			}
		}
	}
	cout << bfs(rx, ry, bx, by);
	return 0;
}