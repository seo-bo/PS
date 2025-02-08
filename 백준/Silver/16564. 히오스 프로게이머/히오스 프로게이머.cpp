#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 0, right = 1e14, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (auto& i : v)
		{
			cnt += max(0LL, mid - i);
		}
		if (cnt <= k)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}