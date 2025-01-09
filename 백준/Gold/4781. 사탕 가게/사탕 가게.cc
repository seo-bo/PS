#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	string a;
	while (cin >> n >> a)
	{
		if (n == 0 && a == "0.00")
		{
			break;
		}
		auto cal = [&](string p)
			{
				string str;
				for (auto& i : p)
				{
					if (i == '.')
					{
						continue;
					}
					str += i;
				}
				return stoi(str);
			};
		m = cal(a);
		vector<pii>v(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			auto& [x, y] = v[i];
			int aa = 0;
			string bb;
			cin >> aa >> bb;
			x = aa;
			y = cal(bb);
		}
		ll ans = 0;
		vector<ll>dp(m + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = v[i].second; j <= m; ++j)
			{
				dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);
				ans = max(ans, dp[j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}