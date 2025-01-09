#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, ans = 0;
		cin >> n >> m;
		vector<vector<char>>v(n, vector<char>(m));
		vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				cin >> j;
			}
		}
		string str;
		cin >> str;
		set<char>key;
		for (auto& i : str)
		{
			key.insert(i);
		}
		vector<vector<bool>>visited(n, vector<bool>(m, false));
		queue<pii>q;
		map<char, set<pii>>memo;
		for (int i = 0; i < n; ++i)
		{
			for (auto j : { 0, m - 1 })
			{
				if (v[i][j] != '*' && !visited[i][j])
				{
					visited[i][j] = true;
					q.push(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (auto j : { 0, n - 1 })
			{
				if (v[j][i] != '*' && !visited[j][i])
				{
					visited[j][i] = true;
					q.push(make_pair(j, i));
				}
			}
		}
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			if (v[x][y] == '$')
			{
				ans++;
			}
			else if ('a' <= v[x][y] && v[x][y] <= 'z')
			{
				key.insert(v[x][y]);
				for (auto& [a, b] : memo[v[x][y]])
				{
					visited[a][b] = true;
					q.push(make_pair(a, b));
				}
				memo[v[x][y]].clear();
			}
			else if ('A' <= v[x][y] && v[x][y] <= 'Z')
			{
				char p = tolower(v[x][y]);
				if (key.find(p) == key.end())
				{
					memo[p].insert(make_pair(x, y));
					continue;
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && v[nx][ny] != '*')
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}