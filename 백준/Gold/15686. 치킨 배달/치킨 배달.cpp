#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, ans = INT_MAX;
	cin >> n >> m;
	vector<pii>chi;
	vector<pii>home;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 2)
			{
				chi.push_back(make_pair(i, j));
			}
			else if (temp == 1)
			{
				home.push_back(make_pair(i, j));
			}
		}
	}
	vector<pii>temp;
	function<void(int, int)> dfs = [&](int mask, int start)
		{
			if (temp.size() == m)
			{
				int sum = 0;
				for (auto& [a, b] : home)
				{
					int mini = INT_MAX;
					for (auto& [c, d] : temp)
					{
						mini = min(mini, abs(a - c) + abs(b - d));
					}
					sum += mini;
				}
				ans = min(ans, sum);
				return;
			}
			for (int i = start; i < chi.size(); ++i)
			{
				if ((1 << i) & mask)
				{
					continue;
				}
				temp.push_back(chi[i]);
				dfs((mask | (1 << i)), i + 1);
				temp.pop_back();
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}