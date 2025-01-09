#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, cnt = 0, ver = 0, p = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<pii>degree(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		graph[i].push_back(temp);
		degree[i].first = i;
		degree[temp].second++;
	}
	sort(degree.begin() + 1, degree.end(), [&](const pii& a, const pii& b)
		{
			return a.second < b.second;
		});
	vector<int>num(n + 1, 0), low(n + 1, 0), s, id(n + 1, -1);
	vector<bool>in(n + 1, false);
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
			if (low[node] == num[node])
			{
				bool c = false;
				while (!s.empty())
				{
					if (!c)
					{
						ver++;
						c = true;
					}
					int a = s.back();
					s.pop_back();
					in[a] = false;
					id[a] = ver;
				}
				p++;
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b] = degree[i];
		if (!num[a])
		{
			scc(a);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(id[i], ans);
	}
	if (ans == 1 && p == 1)
	{
		cout << 0;
	}
	else
	{
		cout << ans;
	}
	return 0;
}