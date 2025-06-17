#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, x = 0, ans = 0, siz = 0;
	cin >> n >> x;
	x <<= 1;
	map<ll, ll>mm;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (temp * 2 >= x)
		{
			ans++;
			continue;
		}
		mm[temp * 2]++;
		siz++;
	}
	while (siz > 1)
	{
		siz -= 2;
		auto it = mm.begin();
		--it->second;
		auto [a, b] = *it;
		if (b == 0)
		{
			mm.erase(it);
		}
		auto jt = mm.lower_bound(x - x / 2 - a);
		if (jt == mm.end())
		{
			auto kt = mm.begin();
			--kt->second;
			auto [c, d] = *kt;
			if (d == 0)
			{
				mm.erase(kt);
			}
			mm[a + c + x / 2]++;
			siz++;
		}
		else
		{
			if (--jt->second == 0)
			{
				mm.erase(jt);
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}