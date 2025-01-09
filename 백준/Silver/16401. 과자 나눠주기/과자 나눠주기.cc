#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m = 0, n = 0;
	ll sum = 0;
	cin >> m >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	if (sum < m)
	{
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	ll left = 0, right = INT_MAX, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (auto& i : v)
		{
			if (mid <= i)
			{
				cnt += i / mid;
			}
		}
		if (cnt < m)
		{
			right = mid - 1;
		}
		else
		{
			ans = mid;
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}