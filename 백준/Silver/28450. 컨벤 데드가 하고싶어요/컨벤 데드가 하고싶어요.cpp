#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	ll k = 0;
	cin >> k;
	if (v[0][0] > k)
	{
		cout << "NO";
		return 0;
	}
	vector<vector<ll>>dist(n, vector<ll>(m, LLONG_MAX));
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(make_tuple(v[0][0], 0, 0));
	dist[0][0] = v[0][0];
	vector<vector<int>>dir = { {1,0},{0,1} };
	while (!pq.empty())
	{
		auto [cost, x, y] = pq.top();
		pq.pop();
		if (dist[x][y] < cost)
		{
			continue;
		}
		for (int i = 0; i < 2; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				ll nc = cost + v[nx][ny];
				if (dist[nx][ny] > nc)
				{
					dist[nx][ny] = nc;
					pq.push(make_tuple(nc, nx, ny));
				}
			}
		}
	}
	if (dist[n - 1][m - 1] > k)
	{
		cout << "NO";
	}
	else
	{
		cout << format("{}\n{}", "YES", dist[n - 1][m - 1]);
	}
	return 0;
}