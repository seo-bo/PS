#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	bool check = true;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		if (v[i])
		{
			check = false;
		}
	}
	if (check)
	{
		cout << 0;
		return 0;
	}
	vector<int>prefix(1, 0);
	for (int k = 1; k <= 2; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			prefix.push_back(prefix.back() + 1);
		}
	}
	auto sv = [&](int a)
		{
			return a + n;
		};
	int left = 1, right = 1, dir = 1;
	ll ans = 0;
	while (!v[left])
	{
		left--;
		if (left == 0)
		{
			left = n;
		}
	}
	while (!v[right])
	{
		right++;
		if (right == n + 1)
		{
			right = 1;
		}
		ans++;
	}
	while (left != right)
	{
		ll cost = prefix[sv(right)] - prefix[left];
		if (v[left] < v[right])
		{
			ans += cost * 2LL * (ll)v[left];
			v[right] -= v[left];
			v[left] = 0;
			if (dir == 2)
			{
				ans -= cost;
				v[right]++;
			}
			while (!v[left])
			{
				left--;
				if (left == 0)
				{
					left = n;
				}
			}
			dir = 1;
		}
		else if (v[right] < v[left])
		{
			ans += cost * 2LL * (ll)v[right];
			v[left] -= v[right];
			v[right] = 0;
			if (dir == 1)
			{
				ans -= cost;
				v[left]++;
			}
			while (!v[right])
			{
				right++;
				if (right == n + 1)
				{
					right = 1;
				}
			}
			dir = 2;
		}
		else
		{
			ans += cost * 2LL * (ll)v[left] - cost;
			if (dir == 1)
			{
				v[right] = 0;
				v[left] = 1;
				while (!v[right])
				{
					right++;
					if (right == n + 1)
					{
						right = 1;
					}
				}
				dir = 2;
			}
			else if (dir == 2)
			{
				v[left] = 0;
				v[right] = 1;
				while (!v[left])
				{
					left--;
					if (left == 0)
					{
						left = n;
					}
				}
				dir = 1;
			}
		}
	}
	ans += max((ll)v[left] - 1LL, 0LL) * n;
	cout << ans;
	return 0;
}