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
		bool flag = true;
		for (; (int)ans.size() < n - 1 && i <= m; ++i)
		{
			if (i & (~m))
			{
				flag = false;
				break;
			}
			ans.push_back(i);
			p |= i;
		}
		if (flag)
		{
			if ((p | i) == m)
			{
				ans.push_back(i);
			}
			else
			{
				ans.push_back(m);
			}
		}
		while ((int)ans.size() < n)
		{
			ans.push_back(m);
		}
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
