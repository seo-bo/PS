#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>graph[201];
	vector<bool>visited(201, false);
	vector<int>match(201, 0);
	ll result = 0;
	for (int i = 1; i <= n; ++i)
	{
		int s = 0;
		cin >> s;
		for (int j = 0; j < s; ++j)
		{
			int temp = 0;
			cin >> temp;
			graph[i].push_back(temp);
		}
	}
	function<bool(int)> dfs = [&](int cow) -> bool
		{
			for (auto& i : graph[cow])
			{
				if (!visited[i])
				{
					visited[i] = true;
					if (!match[i] || dfs(match[i]))
					{
						match[i] = cow;
						return true;
					}
				}
			}
			return false;
		};
	for (int i = 1; i <= n; ++i)
	{
		if (dfs(i))
		{
			result++;
		}
		vector<bool>(201, false).swap(visited);
	}
	cout << result;
	return 0;
}