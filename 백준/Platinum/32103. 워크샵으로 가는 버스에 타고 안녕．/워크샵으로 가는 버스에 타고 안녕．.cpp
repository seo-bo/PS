#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 1행과 3행에만 에어컨이 있다!?
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<int>>dir = { {0,0,0}, { -1,0 ,0},{1,0,0},{0,-1,-1},{0,1,1} };
	vector<vector<int>>ban(3, vector<int>(n + 3, -1));
	vector<int>base(n + 3, 0);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		a--;
		ban[a][b] = c;
		cnt += c;
		if (!c)
		{
			continue;
		}
		for (int j = 0; j < 5; ++j)
		{
			int na = a + dir[j][0];
			int nb = b + dir[j][1];
			if (na >= 0 && na < 3)
			{
				base[nb] |= (1 << na);
			}
		}
	}
	vector<vector<vector<ll>>>dp((1 << 3), vector<vector<ll>>((1 << 3), vector<ll>(n + 3, -1)));
	vector<vector<int>>per = { {}, { 0 },{2},{0,2} };
	function<ll(ll, ll, ll)> dfs = [&](ll pre, ll cur, ll idx)
		{
			if (idx == n + 1)
			{
				if (pre != 7)
				{
					return 1LL * INT_MAX;
				}
				return 0LL;
			}
			if (dp[pre][cur][idx] != -1)
			{
				return dp[pre][cur][idx];
			}
			ll res = INT_MAX;
			for (auto& i : per)
			{
				ll tp = pre;
				ll tc = cur;
				ll nxt = base[idx + 1];
				for (auto& j : i)
				{
					if (ban[j][idx] != -1)
					{
						continue;
					}
					for (int k = 0; k < 5; ++k)
					{
						int na = j + dir[k][0];
						int nb = idx + dir[k][1];
						if (na >= 0 && na < 3)
						{
							if (dir[k][2] == -1)
							{
								tp |= (1LL << na);
							}
							else if (dir[k][2] == 1)
							{
								nxt |= (1LL << na);
							}
							else
							{
								tc |= (1LL << na);
							}
						}
					}
				}
				if (tp == 7)
				{
					res = min(res, dfs(tc, nxt, idx + 1) + (ll)i.size());
				}
			}
			return dp[pre][cur][idx] = res;
		};
	ll res = dfs(7, base[1], 1);
	if (res >= 1200000)
	{
		cout << -1;
		return 0;
	}
	cout << res + cnt;
	return 0;
}