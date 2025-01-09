#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n);
	vector<int>ans(n, 1);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				continue;
			}
			if (v[i].first < v[j].first && v[i].second < v[j].second)
			{
				ans[i]++;
			}
		}
	}
	for (auto& i : ans)
	{
		cout << i << " ";
	}
	return 0;
}