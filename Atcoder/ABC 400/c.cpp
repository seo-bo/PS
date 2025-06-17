#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll MAX = 1e9 + 1;
	ll n = 0, ans = 0;
	cin >> n;
	auto sv = [&](ll pivot)
		{
			ll left = 0, right = min(pivot, MAX);
			while (left <= right)
			{
				ll mid = (left + right) / 2;
				if (mid * mid == pivot)
				{
					return mid;
				}
				if (mid * mid < pivot)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			return right;
		};
	for (ll i = 1; (1LL << i) <= n && i <= 63; ++i)
	{
		ll pivot = (1LL << i);
		ans += (sv(n / pivot) + 1) / 2;
	}
	cout << ans;
	return 0;
}
