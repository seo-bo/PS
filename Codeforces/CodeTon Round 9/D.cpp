#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>div(100002);
	for (int i = 1; i <= 100000; ++i)
	{
		for (int j = 2 * i; j <= 100000; j += i)
		{
			div[j].push_back(i);
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<int>v(m);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.rbegin(), v.rend());
		vector<int>ans(n + 1, -1);
		bool check = true;
		for (int i = 1; i <= n; ++i)
		{
			vector<int>used;
			for (auto& j : div[i])
			{
				if (j < i)
				{
					used.push_back(ans[j]);
				}
			}
			sort(used.begin(), used.end());
			used.erase(unique(used.begin(), used.end()), used.end());
			int sel = -1;
			for (auto& j : v)
			{
				if (j < 1 || j > n)
				{
					continue;
				}
				if (!binary_search(used.begin(), used.end(), j))
				{
					sel = j;
					break;
				}
			}
			if (sel == -1)
			{
				check = false;
				break;
			}
			ans[i] = sel;
		}
		if (check)
		{
			for (int i = 1; i <= n; ++i)
			{
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
	return 0;
}
