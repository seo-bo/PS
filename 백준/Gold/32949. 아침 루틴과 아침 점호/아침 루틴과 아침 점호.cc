#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, ll> tl;
int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, t = 0;
	cin >> n >> t;
	vector<vector<ll>>dp(103, vector<ll>(t + 1, -1));
	vector<tl>v(n);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
		a++;
	}
	sort(v.begin(), v.end());
	dp[0][0] = 0;
	ll ans = 0;
	for (auto& [a, b, c] : v)
	{
		for (int i = a; i >= a - 1; --i)
		{
			for (int j = t; j >= b; --j)
			{
				if (dp[i][j - b] != -1)
				{
					dp[a][j] = max(dp[a][j], dp[i][j - b] + c);
					ans = max(ans, dp[a][j]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}