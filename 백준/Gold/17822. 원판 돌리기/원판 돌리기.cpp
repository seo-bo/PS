#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, T = 0;
	cin >> n >> m >> T;
	vector<deque<int>>v(n, deque<int>(m, 0));
	int cnt = 0, sum = 0;
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
			sum += j;
			cnt++;
		}
	}
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	auto bfs = [&](int xx, int yy, int p)
		{
			queue<pii>q;
			q.push(make_pair(xx, yy));
			v[xx][yy] = -1;
			sum -= p, cnt--;
			int nc = 0;
			while (!q.empty())
			{
				auto [ax, ay] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = ax + dir[i][0];
					int ny = (ay + dir[i][1] + m) % m;
					if (nx >= 0 && nx < n && v[nx][ny] == p)
					{
						v[nx][ny] = -1;
						sum -= p, nc++, cnt--;
						q.push(make_pair(nx, ny));
					}
				}
			}
			if (!nc)
			{
				sum += p, cnt++, v[xx][yy] = p;
				return false;
			}
			return true;
		};
	for (int i = 1; i <= T && cnt; ++i)
	{
		int x = 0, d = 0, k = 0;
		cin >> x >> d >> k;
		for (int j = 0; j < n; ++j)
		{
			if ((j + 1) % x == 0)
			{
				for (int z = 0; z < k; ++z)
				{
					if (!d)
					{
						v[j].push_front(v[j].back());
						v[j].pop_back();
					}
					else
					{
						v[j].push_back(v[j].front());
						v[j].pop_front();
					}
				}
			}
		}
		bool check = false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (v[i][j] != -1)
				{
					check |= bfs(i, j, v[i][j]);
				}
			}
		}
		if (!check)
		{
			int ts = sum;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (v[i][j] != -1)
					{
						if (v[i][j] * cnt > ts)
						{
							v[i][j]--;
							sum--;
						}
						else if (v[i][j] * cnt < ts)
						{
							v[i][j]++;
							sum++;
						}
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}