#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int s = 0;
	cin >> s;
	vector<vector<pll>>v(s, vector<pll>(2));
	for (auto& i : v)
	{
		for (auto& [a, b] : i)
		{
			cin >> a >> b;
		}
	}
	auto sv = [&](vector<pll>s, vector<pll>e)
		{
			auto ccw = [&](pll a, pll b, pll c)
				{
					ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
					temp -= a.second * b.first + b.second * c.first + c.second * a.first;
					return (temp > 0) ? 1 : (temp < 0) ? -1 : 0;
				};
			ll xy = ccw(s[0], s[1], e[0]) * ccw(s[0], s[1], e[1]);
			return xy < 0;
		};
	int t = 0;
	cin >> t;
	while (t--)
	{
		vector<pll>temp(2);
		for (auto& [a, b] : temp)
		{
			cin >> a >> b;
		}
		int cnt = 0;
		for (int i = 0; i < s; ++i)
		{
			if (sv(v[i], temp))
			{
				cnt++;
			}
		}
		if (cnt % 2)
		{
			cout << "different\n";
		}
		else
		{
			cout << "same\n";
		}
	}
	return 0;
}