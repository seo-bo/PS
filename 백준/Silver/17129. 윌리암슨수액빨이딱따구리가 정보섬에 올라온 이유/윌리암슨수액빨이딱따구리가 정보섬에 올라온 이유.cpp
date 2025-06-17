#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	queue<pii>q;
	vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j] - '0';
			if (v[i][j] == 2)
			{
				q.push(make_pair(i, j));
				visited[i][j] = 0;
			}
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (v[x][y] >= 3)
		{
			cout << "TAK\n" << visited[x][y];
			return 0;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != 1)
			{
				if (visited[nx][ny] > visited[x][y] + 1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << "NIE";
	return 0;
}