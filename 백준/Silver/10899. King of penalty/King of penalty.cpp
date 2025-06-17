#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll p = 0, n = 0;
	cin >> p >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	ll cnt = 0, last = 0;
	for (auto& i : v)
	{
		if (last + i >= p)
		{
			break;
		}
		cnt++;
		last += i;
	}
	ll left = 0, right = INT_MAX, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) >> 1;
		ll pivot = 0, st = mid;
		for (auto& i : v)
		{
			if (st + i >= p)
			{
				break;
			}
			pivot++;
			st += i;
		}
		if (pivot < cnt)
		{
			right = mid - 1;
		}
		else
		{
			ans = mid;
			left = mid + 1;
		}
	}
	sort(v.begin(), v.begin() + cnt, greater<int>());
	ll res = 0, now = ans;
	for (int i = 0; i < cnt; ++i)
	{
		now += v[i];
		res += now;
	}
	cout << cnt << ' ' << res;
	return 0;
}