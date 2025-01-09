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
		ll n = 0, x = 0, ans = 0;
		cin >> n >> x;
		for (int i = 1; i <= x; ++i)
		{
			for (int j = 1; j <= x; ++j)
			{
				ll ij = i * j;
				if (ij >= n)
				{
					break;
				}
				ll mc = min(x - (i + j), (n - ij) / (i + j));
				if (mc >= 1)
				{
					ans += mc;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
