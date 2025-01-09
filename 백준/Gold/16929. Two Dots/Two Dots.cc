#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(n, vector<char>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = a[j];
		}
	}
	function<bool(int, int, int, int, char)> dfs = [&](int x, int y, int xx, int yy, char p)
		{
			visited[x][y] = true;
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (nx == xx && ny == yy)
					{
						continue;
					}
					if (v[nx][ny] == p)
					{
						if (visited[nx][ny] || (dfs(nx, ny, x, y, p)))
						{
							return true;
						}
					}
				}
			}
			return false;
		};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j])
			{
				if (dfs(i, j, -1, -1, v[i][j]))
				{
					cout << yes;
					return 0;
				}
			}
		}
	}
	cout << no;
	return 0;
}