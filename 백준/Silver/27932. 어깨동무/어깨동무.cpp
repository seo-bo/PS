#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0;
	ll ans = LLONG_MAX;
	cin >> n >> k;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	v.push_back(v[n - 1]); // 아니 N이 1이면 에러네..
	ll left = 0, right = LLONG_MAX;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!i)
			{
				if (abs(v[i] - v[i + 1]) > mid)
				{
					cnt++;
				}
			}
			else
			{
				if (abs(v[i] - v[i + 1]) > mid || abs(v[i] - v[i - 1]) > mid)
				{
					cnt++;
				}
			}
		}
		if (cnt <= k)
		{
			ans = min(ans, mid);
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