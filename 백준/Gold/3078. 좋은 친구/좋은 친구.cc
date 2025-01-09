#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	ll ans = 0;
	vector<vector<int>>v(21);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		v[str.size()].push_back(i);
	}
	for (int i = 2; i <= 20; ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			auto it = upper_bound(v[i].begin(), v[i].end(), v[i][j] + k);
			it--;
			if (*it < v[i][j] || *it == v[i][j])
			{
				continue;
			}
			int idx = it - v[i].begin();
			ans += idx - j;
		}
	}
	cout << ans;
	return 0;
}