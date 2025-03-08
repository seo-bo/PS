#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll now = 0;
	vector<pll>v(10), cost(10);
	vector<ll>time(10);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	for (ll i = 0; i < 10; ++i)
	{
		cin >> cost[i].first >> cost[i].second;
		cin >> time[i];
	}
	for (ll _ = 0; _ < 3; ++_)
	{
		for (ll i = 0; i < 10; ++i)
		{
			if (now < time[i])
			{
				now += v[i].first + v[i].second;
				time[i] = max(time[i], now - v[i].second);
			}
			else
			{
				ll pivot = cost[i].first + cost[i].second;
				time[i] += (now - time[i]) / pivot * pivot;
				ll temp = (now - time[i]) % pivot;
				now += v[i].first + v[i].second;
				now += (temp < cost[i].first) ? cost[i].first - temp : 0;
				time[i] = max(time[i] + pivot, now - v[i].second);
			}
		}
	}
	cout << now - v[9].second;
	return 0;
}