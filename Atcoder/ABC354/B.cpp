#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum = 0;
	int num = 0;
	cin >> num;
	vector<pair<string, int>>v(num);
	for (int i = 0; i < num; ++i)
	{
		cin >> v[i].first >> v[i].second;
		sum += v[i].second;
	}
	sum %= num;
	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b)
		{
			return a.first < b.first;
		});
	cout << v[sum].first;
	return 0;
}
