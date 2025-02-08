#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>>v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	ll result = 0;
	cin >> num;
	v.resize(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)
		{
			return (a.first == b.first) ? a.second > b.second : a.first < b.first;
		});
	ll start = v[0].first, end = v[0].second;
	result += llabs(start - end);
	int len = v.size();
	for (int i = 1; i < len; ++i)
	{
		if (v[i].first >= end || v[i].second > end)
		{
			start = max(end, v[i].first);
			end = max(end, v[i].second);
			result += llabs(start - end);
		}
	}
	cout << result;
	return 0;
}