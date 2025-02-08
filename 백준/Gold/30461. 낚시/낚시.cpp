#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<vector<ll>>v(n + 1, vector<ll>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<ll>>prefix(n + 1, vector<ll>(m + 1, 0));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			prefix[j][i] = prefix[j - 1][i] + v[j][i];
		}
	}
	vector<vector<ll>>ans(n + 1, vector<ll>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			ans[i][j] = prefix[i][j];
			ans[i][j] += ans[i - 1][j - 1];
		}
	}
	while (q--)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		cout << ans[a][b] << '\n';
	}
	return 0;
}