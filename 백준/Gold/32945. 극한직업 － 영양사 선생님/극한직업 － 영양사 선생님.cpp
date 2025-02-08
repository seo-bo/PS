#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.rbegin(), v.rend());
	vector<pll>p;
	for (int i = 0; i < n; ++i)
	{
		p.push_back(make_pair(i + 1, 0));
		p.push_back(make_pair(i + 1 + v[i], 1));
	}
	sort(p.begin(), p.end(), [&](const pll& a, const pll& b)
		{
			if (a.first == b.first)
			{
				return a.second > b.second;
			}
			return a.first < b.first;
		});
	ll cur = 0, ans = 0;
	for (auto& [a, b] : p)
	{
		if (b)
		{
			cur--;
		}
		else
		{
			cur++;
			ans = max(cur, ans);
		}
	}
	cout << ans;
	return 0;
}