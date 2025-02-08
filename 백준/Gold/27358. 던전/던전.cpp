#include <bits/stdc++.h>
#define MOD 10000000LL
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0;
		cin >> n;
		vector<ll>v(n), cost(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		string str;
		cin >> str;
		for (auto& i : cost)
		{
			cin >> i;
		}
		auto cal = [&](tp& A)
			{
				auto& [a, b, c] = A;
				if (c < 0)
				{
					b--;
					c += 10;
				}
				if (b < 0)
				{
					a--;
					b += MOD;
				}
				b += c / 10;
				c %= 10;
				if (c < 0)
				{
					c += 10;
				}
				a += b / MOD;
				b %= MOD;
			};
		ll left = 1, right = LLONG_MAX, ans = 0;
		while (left <= right)
		{
			ll mid = left + (right - left) / 2LL;
			tp pivot = make_tuple(0LL, 0LL, 0LL);
			auto& [a, b, c] = pivot;
			c = mid;
			cal(pivot);
			bool flag = true;
			for (ll i = 0; i < n; ++i)
			{
				a--;
				c += MOD * 10LL - v[i];
				cal(pivot);
				if (a == 0 && b == 0 && c == 0 || (a < 0))
				{
					flag = false;
					break;
				}
				if (str[i] == '+')
				{
					c += cost[i];
					cal(pivot);
				}
				else
				{
					b *= cost[i];
					c *= cost[i];
					cal(pivot);
				}
			}
			if (flag)
			{
				ans = mid;
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}