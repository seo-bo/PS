#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, int, int, int> ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0, t = 0, q = 0;
	cin >> n >> m >> k >> t >> q;
	vector<vector<int>>v(n + 1, vector<int>(m + 1));
	vector<vector<pii>>tel(n + 1, vector<pii>(m + 1, make_pair(-1, -1)));
	vector<vector<vector<ll>>>dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(t + 1, LLONG_MAX)));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < k; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		tel[a][b] = make_pair(c, d);
	}
	priority_queue<ti, vector<ti>, greater<ti>>pq;
	dp[1][1][0] = 0;
	pq.push(make_tuple(0, 1, 1, 0));
	while (!pq.empty())
	{
		auto [w, a, b, c] = pq.top();
		pq.pop();
		if (dp[a][b][c] < w)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = a + dir[i][0];
			int ny = b + dir[i][1];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				ll nw = w;
				if (v[nx][ny] > 0)
				{
					nw += v[nx][ny];
				}
				if (dp[nx][ny][c] > nw)
				{
					dp[nx][ny][c] = nw;
					pq.push(make_tuple(nw, nx, ny, c));
				}
			}
		}
		if (c < t && tel[a][b] != make_pair(-1, -1))
		{
			int nx = tel[a][b].first;
			int ny = tel[a][b].second;
			if (dp[nx][ny][c + 1] > w)
			{
				dp[nx][ny][c + 1] = w;
				pq.push(make_tuple(w, nx, ny, c + 1));
			}
		}
	}
	vector<vector<ll>>ans(n + 1, vector<ll>(m + 1, LLONG_MAX));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 0; k <= t; ++k)
			{
				ans[i][j] = min(ans[i][j], dp[i][j][k]);
			}
		}
	}
	while (q--)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (ans[b][c] <= a)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}