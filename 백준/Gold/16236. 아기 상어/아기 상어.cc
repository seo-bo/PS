#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int space[21][21] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N = 0, answer = 0, temp = 0;

typedef struct
{
	int x;
	int y;
	int size;
	int eat;
}Shark;

Shark baby;

class Fish
{
public:
	int x, y, dist;

	bool operator<(const Fish& o) const
	{
		if (dist == o.dist)
		{
			if (x == o.x)
			{
				return y > o.y;
			}
			return x > o.x;
		}
		return dist > o.dist;
	}
};

int bfs()
{
	queue<pair<int, int>>Q;
	vector<vector<int>>visited(N, vector<int>(N, 0));
	Q.push(make_pair(baby.x, baby.y));
	visited[baby.x][baby.y] = 1;
	priority_queue<Fish> fish;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && space[nx][ny] <= baby.size)
			{
				visited[nx][ny] = visited[x][y] + 1;
				Q.push(make_pair(nx, ny));
				if (space[nx][ny] > 0 && space[nx][ny] < baby.size)
				{
					fish.push({ nx,ny,visited[nx][ny] - 1 });
				}
			}
		}
	}
	if (fish.empty())
	{
		return -1;
	}
	int fx = fish.top().x;
	int fy = fish.top().y;
	int fd = fish.top().dist;
	space[fx][fy] = 0;
	baby.x = fx;
	baby.y = fy;
	baby.eat++;
	if (baby.eat == baby.size)
	{
		baby.size++;
		baby.eat = 0;
	}
	return fd;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				baby = { i,j,2,0 };
				space[i][j] = 0;
			}
		}
	}
	while ((temp = bfs()) != -1)
	{
		answer += temp;
	}
	cout << answer;
	return 0;
}
