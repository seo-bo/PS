#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>s, b;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (temp > 0)
		{
			s.push_back(make_pair(i, temp));
		}
		else
		{
			b.push_back(make_pair(i, -temp));
		}
	}
	int i = 0, j = 0;
	ll ans = 0;
	while (i < s.size() && j < b.size())
	{
		auto& [sdx, sell] = s[i];
		auto& [bdx, buy] = b[j];
		ll p = min(sell, buy);
		ans += llabs(sdx - bdx) * p;
		sell -= p;
		buy -= p;
		if (!sell)
		{
			i++;
		}
		if (!buy)
		{
			j++;
		}
	}
	cout << ans;
	return 0;
}