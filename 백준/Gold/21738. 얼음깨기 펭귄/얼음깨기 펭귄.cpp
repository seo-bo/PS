#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, s = 0, p = 0, degree = 0;
	cin >> n >> s >> p;
	priority_queue<int>pq;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	function<bool(int, int, int)> dfs = [&](int sum, int parent, int node)
		{
			if (node == p)
			{
				pq.push(sum - 1);
				if ((int)pq.size() > 2)
				{
					pq.pop();
				}
				return true;
			}
			for (auto& i : graph[node])
			{
				if (parent == i)
				{
					continue;
				}
				if (dfs(sum + 1, node, i))
				{
					return true;
				}
			}
			return false;
		};
	for (int i = 1; i <= s; ++i)
	{
		dfs(1, -1, i);
	}
	while (!pq.empty())// 아 ㅅㅂ
	{
		n -= pq.top();
		pq.pop();
	}
	cout << n - 1;
	return 0;
}