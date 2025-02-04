#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	for (int _ = 1;; ++_)
	{
		string str;
		cin >> str;
		if (str == "#")
		{
			break;
		}
		int len = str.size(), ok = 1, idx = 0;
		vector<vector<int>>graph(20001);
		int ans1 = 0, ans2 = 0;
		function<void(int, int)> dfs = [&](int depth, int parent)
			{
				ans1 = max(ans1, depth);
				while (idx < len)
				{
					if (str[idx++] == 'd')
					{
						graph[parent].push_back(++ok);
						dfs(depth + 1, ok);
					}
					else
					{
						return;
					}
				}
			};
		dfs(0, 1);
		queue<int>q;
		vector<int>depth(ok + 2, 0);
		depth[1] = 0;
		q.push(1);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int i = 1; i <= (int)graph[cur].size(); ++i)
			{
				int node = graph[cur][i - 1];
				depth[node] = depth[cur] + i;
				q.push(node);
			}
		}
		cout << format("Tree {}: {} => {}\n", _, ans1, *max_element(depth.begin(), depth.end()));
	}
	return 0;
}