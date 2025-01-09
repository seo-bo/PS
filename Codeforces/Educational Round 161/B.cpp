#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		map<ll, ll>m;
		for (int i = 0; i < n; ++i)
		{
			ll temp = 0;
			cin >> temp;
			m[temp]++;
		}
		ll ans = 0;
		ll sum = 0;
		for (auto& i : m)
		{
			if (i.second >= 3)
			{
				ans += i.second * (i.second - 1) * (i.second - 2) / 6;
			}
			if (i.second >= 2)
			{
				ans += i.second * (i.second - 1) / 2 * sum;
			}
			sum += i.second;
		}
		cout << ans << "\n";
	}
	return 0;
}
