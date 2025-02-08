#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int m = 0, n = 0;
	cin >> m >> n;
	vector<vector<int>>v(m);
	for (int i = 0; i < m; ++i)
	{
		vector<int>temp(n);
		for (auto& j : temp)
		{
			cin >> j;
		}
		vector<int>cp = temp;
		sort(cp.begin(), cp.end());
		for (auto& j : temp)
		{
			v[i].push_back(upper_bound(cp.begin(), cp.end(), j) - cp.begin());
		}
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = i + 1; j < m; ++j)
		{
			if (v[i] == v[j])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}