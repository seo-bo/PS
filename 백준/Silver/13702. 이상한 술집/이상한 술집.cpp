#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, right = 0;
	cin >> n >> k;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		right = max(right, i);
	}
	ll left = 1, ans = LLONG_MAX;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (auto& i : v)
		{
			sum += i / mid;
		}
		if (sum >= k)
		{
			left = mid + 1;
			ans = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	if (ans == LLONG_MAX)
	{
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}