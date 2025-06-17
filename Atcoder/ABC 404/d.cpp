#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>cost(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
	}
	ll ans = LLONG_MAX;
	vector<vector<int>>zoo(n);
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int temp = 0;
			cin >> temp;
			--temp;
			zoo[temp].push_back(i);
		}
	}
	for (int i = 0; i < (1 << (2 * n)); ++i)
	{
		vector<int>cnt(m, 0);
		ll money = 0;
		for (int j = 0; j < 2 * n; ++j)
		{
			if (!(i & (1 << j)))
			{
				continue;
			}
			int pivot = j % n;
			money += cost[pivot];
			for (auto& k : zoo[pivot])
			{
				cnt[k]++;
			}
		}
		bool flag = true;
		for (int i = 0; i < m; ++i)
		{
			if (cnt[i] < 2)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans = min(ans, money);
		}
	}
	cout << ans;
	return 0;
}
