#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	ll sum = 0;
	vector<vector<ll>>v(n, vector<ll>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
			sum += j;
		}
	}
	if (!sum)
	{
		cout << 0;
		return 0;
	}
	ll left = 0, right = 20000000, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll temp = 0;
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				temp += min(j, mid);
			}
		}
		if ((sum + 1) / 2 <= temp)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}