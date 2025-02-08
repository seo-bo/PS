#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tl;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>>visited(n + 1, vector<int>(n + 1, INT_MAX));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
		}
	}
	priority_queue<tl>pq;
	pq.push(make_tuple(0, 1, 1));
	visited[1][1] = 0;
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	while (!pq.empty())
	{
		auto [w, x, y] = pq.top();
		pq.pop();
		if (x == n && y == n)
		{
			cout << -w;
			break;
		}
		if (visited[x][y] < -w)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				int cost = max(visited[x][y], abs(v[nx][ny] - v[x][y]));
				if (visited[nx][ny] > cost)
				{
					visited[nx][ny] = cost;
					pq.push(make_tuple(-cost, nx, ny));
				}
			}
		}
	}
	return 0;
}