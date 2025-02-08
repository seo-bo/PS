#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll mi = 0;
	ll result = 0;
	vector<pair<ll, ll>>v(11);
	for (int i = 0; i < 11; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair <ll, ll>& b)
		{
			if (a.first == b.first)
			{
				return a.second > b.second;
			}
			return a.first < b.first;
		});
	for (auto& i : v)
	{
		result += (mi + i.first) + (20 * i.second);
		mi += i.first;
	}
	cout << result;
	return 0;
}
