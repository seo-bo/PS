#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> m >> n;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<int>>dir = { {1,0},{0,1} };
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	queue<pii>q;
	q.push(make_pair(0, 0));
	vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
	visited[0][0] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1)
		{
			cout << "Yes";
			return 0;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny])
			{
				if (visited[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << "No";
	return 0;
}