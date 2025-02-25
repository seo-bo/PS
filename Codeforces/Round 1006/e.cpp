#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll k = 0;
		cin >> k;
		if (k == 0)
		{
			cout << 1 << '\n';
			cout << "0 0" << '\n';
			continue;
		}
		ll pivot = 2;
		auto cal = [&](ll a)
			{
				return a * (a - 1) / 2;
			};
		for (;; ++pivot)
		{
			if (cal(pivot) > k)
			{
				pivot--;
				break;
			}
		}
		vector<ll>per;
		ll ans = 0;
		while (k)
		{
			if (cal(pivot) <= k)
			{
				k -= cal(pivot);
				per.push_back(pivot);
				ans += pivot;
				continue;
			}
			pivot--;
		}
		cout << ans << '\n';
		ll x = -1e7, y = -1e7;
		for (auto& i : per)
		{
			ll pp = max(x + 100000, y + 100000);
			x = pp, y = pp;
			for (int j = 0; j < i; ++j)
			{
				cout << x << ' ' << y << '\n';
				y++;
			}
		}
	}
	return 0;
}
