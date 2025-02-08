#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll div = sqrt(n), pivot = (n + div - 1) / div;
	vector<int>v(pivot + 2, 0), per(n + 2, 0);
	while (m--)
	{
		ll a = 0, b = 0, ans = 0;
		cin >> a >> b;
		while (a)
		{
			ll p = (b + div - 1) / div * div, sum = min(a, min(p, n) - b + 1);
			a -= sum;
			if (sum == div || b + sum - 1 == n)
			{
				v[p / div]++;
				ans += v[p / div];
			}
			else
			{
				ll ed = min({ p,n,b + sum - 1 });
				for (int i = b; i <= ed; ++i)
				{
					per[i]++;
					ans += per[i];
				}
			}
			b = p + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
