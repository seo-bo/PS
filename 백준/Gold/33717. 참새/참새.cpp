#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 자꾸 투포인터로 하니까 틀리네 아오
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	vector<ll>v(n + 1);
	for (ll i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	if (n == 2)
	{
		if (v[1] == v[2] && v[1] == 1)
		{
			cout << 1 << ' ' << 0;
			return 0;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	// 앞에서 부터 그냥 채워갈까? 아니면 뒤부터 앞으로?
	ll r = n - v[1]; // r -> 1의 개수
	if (v[n] != r)
	{
		cout << -1;
		return 0;
	}
	auto sv1 = [&]
		{
			vector<ll>ans(n + 1, -1);
			ans[1] = 1, ans[n] = 0; // 이거는 고정
			ll cnt = 1;
			for (ll i = 2; i <= n - 1; ++i)
			{
				if (v[i] == cnt)
				{
					ans[i] = 0;
				}
				else if (v[i] == v[1] - (i - cnt) + 1)
				{
					ans[i] = 1;
					cnt++;
				}
				else
				{
					return;
				}
			}
			if (cnt != r)
			{
				return;
			}
			vector<ll>prefix(n + 3), suffix(n + 3);
			for (ll i = 1; i <= n; i++)
			{
				prefix[i] = prefix[i - 1] + (ans[i] == 1);
			}
			for (ll i = n; i >= 1; i--)
			{
				suffix[i] = suffix[i + 1] + (ans[i] == 0);
			}
			for (ll i = 1; i <= n; i++)
			{
				if (ans[i] == 0)
				{
					if (prefix[i - 1] != v[i])
					{
						return;
					}
				}
				else
				{
					if (suffix[i + 1] != v[i])
					{
						return;
					}
				}
			}
			for (ll i = 1; i <= n; ++i)
			{
				cout << ans[i] << ' ';
			}
			exit(0);
		};
	auto sv2 = [&]
		{
			vector<ll>ans(n + 1, -1);
			ans[1] = 1, ans[n] = 0; // 이거는 고정
			ll cnt = 1;
			for (ll i = 2; i <= n - 1; ++i)
			{
				if (v[i] == v[1] - (i - cnt) + 1)
				{
					ans[i] = 1;
					cnt++;
				}
				else if (v[i] == cnt)
				{
					ans[i] = 0;
				}
				else
				{
					return;
				}
			}
			if (cnt != r)
			{
				return;
			}
			vector<ll>prefix(n + 3), suffix(n + 3);
			for (ll i = 1; i <= n; i++)
			{
				prefix[i] = prefix[i - 1] + (ans[i] == 1);
			}
			for (ll i = n; i >= 1; i--)
			{
				suffix[i] = suffix[i + 1] + (ans[i] == 0);
			}
			for (ll i = 1; i <= n; i++)
			{
				if (ans[i] == 0)
				{
					if (prefix[i - 1] != v[i])
					{
						return;
					}
				}
				else
				{
					if (suffix[i + 1] != v[i])
					{
						return;
					}
				}
			}
			for (ll i = 1; i <= n; ++i)
			{
				cout << ans[i] << ' ';
			}
			exit(0);
		};
	sv1();
	sv2();
	cout << -1;
	return 0;
}