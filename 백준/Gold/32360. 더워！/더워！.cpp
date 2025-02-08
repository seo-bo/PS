#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, k = 0, c = 0;
	cin >> n >> m >> k >> c;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<vector<bool>>>visited(n, vector<vector<bool>>(m, vector<bool>(101, false)));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<ti>q;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == 'S')
			{
				visited[i][j][0] = true;
				q.push(make_tuple(i, j, 0, 0));
			}
		}
	}
	while (!q.empty())
	{
		auto [x, y, cost, bad] = q.front();
		q.pop();
		if (v[x][y] == 'E')
		{
			cout << cost;
			return 0;
		}
		if (v[x][y] == 'S' || v[x][y] == 'H')
		{
			int pivot = max(0, bad - k);
			if (!visited[x][y][pivot])
			{
				visited[x][y][pivot] = true;
				q.push(make_tuple(x, y, cost + 1, pivot));
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#')
			{
				if (v[nx][ny] == '.' || v[nx][ny] == 'E')
				{
					int pivot = min(100, bad + c);
					if (pivot == 100)
					{
						continue;
					}
					if (!visited[nx][ny][pivot])
					{
						visited[nx][ny][pivot] = true;
						q.push(make_tuple(nx, ny, cost + 1, pivot));
					}
				}
				else if (v[nx][ny] == 'H')
				{
					int pivot = max(0, bad - k);
					if (!visited[nx][ny][pivot])
					{
						visited[nx][ny][pivot] = true;
						q.push(make_tuple(nx, ny, cost + 1, pivot));
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}