#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0;
		cin >> n >> m;
		if (n == 1)
		{
			cout << m << '\n';
			continue;
		}
		vector<ll>ans;
		ll p = 0, i = 0;
		for (; (int)ans.size() < n - 1 && i <= m; ++i)
		{
			if (i & (~m))
			{
				continue;
			}
			ans.push_back(i);
			p |= i;
		}
		ll aa = m ^ p;
		if (aa == 0)
		{
			for (; (int)ans.size() < n && i <= m; ++i)
			{
				if (i & (~m))
				{
					continue;
				}
				ans.push_back(i);
				p |= i;
			}
			while ((int)ans.size() < n)
			{
				ans.push_back(0);
			}
		}
		else
		{
			ans.push_back(aa);
			for (; (int)ans.size() < n && i <= m; ++i)
			{
				if (i & (~m))
				{
					continue;
				}
				ans.push_back(i);
				p |= i;
			}
			while ((int)ans.size() < n)
			{
				ans.push_back(0);
			}
		}
		ll res = 0;
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
