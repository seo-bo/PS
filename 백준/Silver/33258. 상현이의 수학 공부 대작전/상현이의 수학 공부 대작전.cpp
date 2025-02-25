#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, l = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> l;
	ll left = 1, right = 1e10, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pivot = 0;
		for (auto& i : v)
		{
			if (mid >= i)
			{
				pivot += mid;
			}
			else
			{
				pivot += (2 * (mid - i));
			}
		}
		if (pivot >= l)
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