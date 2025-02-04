#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	ll left = 1, right = 0;
	for (auto& i : v)
	{
		cin >> i;
	}
	for (auto& i : v)
	{
		ll temp = 0;
		cin >> temp;
		i = (i + temp - 1) / temp;
		right = max(right, i);
	}
	ll ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (auto& i : v)
		{
			cnt += max(0LL, i - mid);
		}
		if (cnt <= mid)
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}