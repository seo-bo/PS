#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	vector<ll>v;
	ll cur = 0, p = 0;
	while (q--)
	{
		int a = 0;
		cin >> a;
		if (a == 1)
		{
			v.push_back(cur);
		}
		else if (a == 2)
		{
			ll temp = 0;
			cin >> temp;
			cur += temp;
		}
		else
		{
			ll temp = 0;
			cin >> temp;
			ll target = cur - temp;
			if (target < 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				if (p >= v.size())
				{
					cout << 0 << '\n';
				}
				else
				{
					ll it = upper_bound(v.begin() + p, v.end(), target) - (v.begin() + p);
					cout << it << '\n';
					p += it;
				}
			}
		}
	}
	return 0;
}
