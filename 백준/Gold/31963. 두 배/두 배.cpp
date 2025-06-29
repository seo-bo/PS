#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, ans = 0;
	cin >> n;
	pll pivot = make_pair(0LL, 1LL);
	for (ll i = 0; i < n; ++i)
	{
		auto [a, b] = pivot;
		ll temp = 0, cnt = 0;
		cin >> temp;
		ll pa = min(b, temp), pb = max(b, temp);
		while (pa < pb)
		{
			pa <<= 1;
			cnt++;
		}
		pivot.second = temp;
		if (temp < b)
		{
			cnt = -cnt;
		}
		else
		{
			if (pa != pb)
			{
				cnt--;
			}
		}
		ll p = max(0LL, a - cnt);
		ans += p;
		pivot.first = p;
	}
	cout << ans;
	return 0;
}