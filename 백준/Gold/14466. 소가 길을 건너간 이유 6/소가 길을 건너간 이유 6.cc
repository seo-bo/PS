#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0, r = 0;
	cin >> n >> k >> r;
	vector<vector<vector<bool>>>mm(n + 1, vector<vector<bool>>(n + 1, vector<bool>(4, false)));
	vector<vector<bool>>visited(n + 1, vector<bool>(n + 1, false));
	vector<vector<int>>dir = { {-1,0},{0,1},{1,0},{0,-1} };
	vector<pii>cow;
	auto ip = [&](int aa, int bb, int cc, int dd)
		{
			for (int i = 0; i < 4; ++i)
			{
				int nx = aa + dir[i][0];
				int ny = bb + dir[i][1];
				if (nx == cc && ny == dd)
				{
					mm[aa][bb][i] = true;
					mm[cc][dd][(i + 2) % 4] = true;
					break;
				}
			}
		};
	for (int i = 0; i < r; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		ip(a, b, c, d);
	}
	for (int i = 0; i < k; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cow.push_back(make_pair(a, b));
	}
	auto bfs = [&](int x, int y)
		{
			queue<pii>q;
			q.push(make_pair(x, y));
			visited[x][y] = true;
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					if (mm[a][b][i])
					{
						continue;
					}
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && !visited[nx][ny] && !mm[nx][ny][(i + 2) % 4])
					{
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		};
	ll ans = 0;
	for (int i = 0; i < k; ++i)
	{
		auto [a, b] = cow[i];
		bfs(a, b);
		for (int j = i + 1; j < k; ++j)
		{
			auto [c, d] = cow[j];
			if (!visited[c][d])
			{
				ans++;
			}
		}
		vector<vector<bool>>(n + 1, vector<bool>(n + 1, false)).swap(visited);
	}
	cout << ans;
	return 0;
}