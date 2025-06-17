#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, T = 0;
	cin >> n >> T;
	vector<pii>v(n);
	ll left = 1, right = INT_MAX, ans = -1;
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
		left = max(left, (ll)a);
	}
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll l = 0, r = 0;
		for (auto& [a, b] : v)
		{
			l += a;
			r += min(mid, (ll)b);
		}
		if (l <= T && T <= r)
		{
			ans = mid;
			right = mid - 1;
			continue;
		}
		if (T > r)
		{
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