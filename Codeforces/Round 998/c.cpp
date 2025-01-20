#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, k = 0;
		cin >> n >> k;
		vector<ll>v(n);
		map<ll, ll>mm;
		for (auto& i : v)
		{
			cin >> i;
			mm[i]++;
		}
		ll ans = 0;
		if (!(k % 2))
		{
			if (mm.find(k / 2) != mm.end())
			{
				ans += mm[k / 2] / 2;
			}
		}
		for (auto& [a, b] : mm)
		{
			if (2 * a < k)
			{
				if (mm.find(k - a) != mm.end())
				{
					ans += min(b, mm[k - a]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
