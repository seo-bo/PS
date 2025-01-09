#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = a[j] - '0';
		}
	}
	auto bfs = [&](int x, int y)
		{
			vector<vector<bool>>visited(n, vector<bool>(m, false));
			visited[x][y] = true;
			queue<pii>q;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				auto [xx, yy] = q.front();
				q.pop();
				if (xx == n - 1)
				{
					return true;
				}
				for (int i = 0; i < 4; ++i)
				{
					int nx = xx + dir[i][0];
					int ny = yy + dir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && !v[nx][ny])
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
			return false;
		};
	for (int i = 0; i <= 0; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!v[i][j])
			{
				if (bfs(i, j))
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;

}