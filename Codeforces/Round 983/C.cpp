#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		ll left = 1, right = n, ans = n;
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			if (mid == 1)
			{
				ans = min(n - 1, ans);
				left = mid + 1;
				continue;
			}
			bool check = true;
			for (int i = 0; i <= n - mid; ++i)
			{
				if (v[i] + v[i + 1] > v[i + mid - 1])
				{
					check = false;
					break;
				}
			}
			if (!check)
			{
				ans = min(n - mid, ans);
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
