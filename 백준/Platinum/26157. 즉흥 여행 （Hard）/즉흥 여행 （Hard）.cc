#include <bits/stdc++.h>
#include <unordered_set>
#define INF INT_MAX
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, ver = 1, cnt = 0;
	cin >> n >> m;
	vector<vector<int>>temp(n + 1);
	vector<int>num(n + 1, 0), low(n + 1, 0), id(n + 1, -1), s;
	vector<bool>in(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		temp[a].push_back(b);
	}
	function<void(int)> scc = [&](int node)
		{
			num[node] = low[node] = ++cnt;
			s.push_back(node);
			in[node] = true;
			for (auto& i : temp[node])
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
					id[a] = ver;
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
	vector<vector<int>>nodes(ver + 1);
	vector<vector<int>>graph(ver + 1);
	vector<int>indegree(ver + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		nodes[id[i]].push_back(i);
		for (auto& k : temp[i])
		{
			if (id[i] != id[k])
			{
				graph[id[i]].push_back(id[k]);
				indegree[id[k]]++;
			}
		}
	}
	vector<int>visited(ver + 1, 0);
	int pivot = -1;
	queue<pii>q;
	for (int i = 1; i < ver; ++i)
	{
		if (!indegree[i])
		{
			q.push(make_pair(i, 0));
			visited[0]++;
			pivot = i;
		}
	}
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		for (auto& i : graph[a])
		{
			if (!(--indegree[i]))
			{
				visited[b + 1]++;
				q.push(make_pair(i, b + 1));
			}
		}
	}
	for (int i = 0; i < ver - 1; ++i)
	{
		if (visited[i] != 1)
		{
			cout << 0;
			return 0;
		}
	}
	vector<int>ans;
	for (auto& i : nodes[pivot])
	{
		ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}