#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, cnt = 0, ver = 0;
		cin >> n >> m;
		vector<vector<int>>g(n);
		vector<int>num(n), low(n), id(n, -1), S;
		vector<bool>in(n, false);
		for (int i = 0; i < m; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			g[--a].push_back(--b);
		}
		function<void(int)> scc = [&](int node)
			{
				num[node] = low[node] = ++cnt;
				S.push_back(node);
				in[node] = true;
				for (auto& i : g[node])
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
					while (1)
					{
						int a = S.back();
						S.pop_back();
						in[a] = false;
						id[a] = ver;
						if (a == node)
						{
							break;
						}
					}
					ver++;
				}
			};
		for (int i = 0; i < n; ++i)
		{
			if (!num[i])
			{
				scc(i);
			}
		}
		vector<int>indegree(ver, 0);
		for (int i = 0; i < n; ++i)
		{
			for (auto& k : g[i])
			{
				int a = id[i], b = id[k];
				if (a != b)
				{
					indegree[b]++;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < ver; ++i)
		{
			if (!indegree[i])
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}