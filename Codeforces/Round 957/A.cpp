#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll ans = LLONG_MIN;
		vector<ll>v(3);
		for (auto& i : v)
		{
			cin >> i;
		}
		function<void(int)> dfs = [&](int depth)
			{
				if (depth == 5)
				{
					ans = max(ans, v[0] * v[1] * v[2]);
					return;
				}
				for (int i = 0; i < 3; ++i)
				{
					v[i]++;
					dfs(depth + 1);
					v[i]--;
				}
			};
		dfs(0);
		cout << ans << '\n';
	}
	return 0;
}
