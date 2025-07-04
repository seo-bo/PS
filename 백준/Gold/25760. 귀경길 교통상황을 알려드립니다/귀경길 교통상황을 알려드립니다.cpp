#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
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
	vector<bool>ok(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp)
		{
			ok[i] = true;
		}
	}
	vector<int>node, depth(n + 1, -1);
	queue<int>q;
	q.push(1);
	depth[1] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (ok[cur])
		{
			node.push_back(depth[cur]);
		}
		for (auto& i : graph[cur])
		{
			if (depth[i] == -1)
			{
				depth[i] = depth[cur] + 1;
				q.push(i);
			}
		}
	}
	sort(node.rbegin(), node.rend());
	int ans = 0, cnt = 0;
	for (auto& i : node)
	{
		ans = max(ans, i + cnt++);
	}
	cout << ans;
	return 0;
}