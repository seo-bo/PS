#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef tuple<ll, ll, ll> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, atk = 0;
	cin >> n >> atk;
	vector<ti>v(n);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	ll left = 1, right = 1e17, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		bool check = true;
		ll hp = mid, at = atk;
		for (auto& [a, b, c] : v)
		{
			if (a == 2)
			{
				at += b, hp = min(hp + c, mid);
			}
			else
			{
				ll p = (c + at - 1) / at;
				hp -= (p - 1) * b;
				if (hp <= 0)
				{
					check = false;
					break;
				}
			}
		}
		if (check)
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