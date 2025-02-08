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
		int n = 0, ans = INT_MAX;
		cin >> n;
		vector<string>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		if (n > 32)
		{
			cout << 0 << '\n';
			continue;
		}
		auto check = [&](int a, int b) ->int
			{
				int cnt = 0;
				for (int i = 0; i < 4; ++i)
				{
					if (v[a][i] != v[b][i])
					{
						cnt++;
					}
				}
				return cnt;
			};
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					ans = min(ans, check(i, j) + check(i, k) + check(j, k));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}