#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 하........
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	function<int(int, int)> dfs = [&](int parent, int node)
		{
			vector<int>temp;
			for (auto& i : graph[node])
			{
				if (i == parent)
				{
					continue;
				}
				temp.push_back(dfs(node, i));
				ans = max(ans, temp.back());
			}
			sort(temp.rbegin(), temp.rend());
			if (temp.size() >= 4)
			{
				ans = max(ans, 1 + temp[0] + temp[1] + temp[2] + temp[3]);
			}
			if (temp.size() >= 3)
			{
				return 1 + temp[0] + temp[1] + temp[2];
			}
			else
			{
				return 0;
			}
		};
	dfs(0, 1);
	cout << ((ans) ? ans * 3 + 2 : -1);
	return 0;
}
