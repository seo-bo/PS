#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int m = 0;
	cin >> m;
	vector<ll>v(m, 0), p(m, 0);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (auto& i : p)
	{
		cin >> i;
	}
	for (int i = 0; i < m; ++i)
	{
		if (v[i] >= p[i])
		{
			cout << p[i] << ' ';
			continue;
		}
		else if (v[i] == 1)
		{
			cout << 1 << ' ';
			continue;
		}
		ll left = 0, right = INT_MAX, ans = 0, num = v[i] - 1;
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			ll sum = mid + (mid / num);
			if (mid % num == 0)
			{
				sum--;
			}
			if (sum >= p[i])
			{
				ans = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << ans << ' ';
	}
	return 0;
}