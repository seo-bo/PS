#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, ver = 0, cnt = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<int>num(n + 1, 0), low(n + 1, 0), s;
	vector<bool>in(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	function<void(int)> scc = [&](int node)
		{
			num[node] = low[node] = ++cnt;
			s.push_back(node);
			in[node] = true;
			for (auto& i : graph[node])
			{
				if (!num[i])
				{
					scc(i);
					low[node] = min(low[node], low[i]);
				}
				else if (in[i])
				{
					low[node] = min(low[node], num[i]);
				}
			}
			if (num[node] == low[node])
			{
				while (1)
				{
					int a = s.back();
					s.pop_back();
					in[a] = false;
					if (a == node)
					{
						break;
					}
				}
				ver++;
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!num[i])
		{
			scc(i);
		}
	}
	cout << ((ver == 1) ? "Yes" : "No");
	return 0;
}