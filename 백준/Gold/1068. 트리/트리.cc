#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, start = 0;
	cin >> n;
	vector<vector<int>>graph(n);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp == -1)
		{
			start = i;
			continue;
		}
		graph[temp].push_back(i);
	}
	int ans = 0, banned = 0;
	cin >> banned;
	function<void(int)> dfs = [&](int node)
		{
			if (graph[node].empty())
			{
				ans++;
				return;
			}
			int cnt = 0;
			for (auto& i : graph[node])
			{
				if (i == banned)
				{
					continue;
				}
				dfs(i);
				cnt++;
			}
			if (!cnt)
			{
				ans++;
			}
		};
	if (start != banned)
	{
		dfs(start);
	}
	cout << ans;
	return 0;
}