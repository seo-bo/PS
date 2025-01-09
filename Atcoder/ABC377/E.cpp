#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 1, 0), ans(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	auto pow = [&](ll mod)
		{
			ll base = 1, mul = 2, kk = k;
			while (kk)
			{
				if (kk & 1)
				{
					base = (base * mul) % mod;
				}
				mul = (mul * mul) % mod;
				kk >>= 1;
			}
			return base;
		};
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		if (visited[v[i]])
		{
			continue;
		}
		ll p = v[i];
		vector<ll>s;
		while (!visited[p])
		{
			visited[p] = true;
			s.push_back(p);
			p = v[p];
		}
		ll pivot = pow(s.size());
		for (int j = 0; j < s.size(); ++j)
		{
			ans[s[j]] = s[(j + pivot) % s.size()];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
