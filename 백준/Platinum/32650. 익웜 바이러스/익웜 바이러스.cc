#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0);
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? parent[root] : parent[root] = find(parent[root]);
		};
	vector<vector<int>>vers(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		vers[i].push_back(i);
	}
	auto merge = [&](int a, int b)
		{
			int r1 = find(a), r2 = find(b);
			if (r1 != r2)
			{
				if (rank[r1] < rank[r2])
				{
					parent[r1] = r2;
					for (auto& i : vers[r1])
					{
						vers[r2].push_back(i);
					}
					vers[r1].clear();
				}
				else
				{
					parent[r2] = r1;
					for (auto& i : vers[r2])
					{
						vers[r1].push_back(i);
					}
					vers[r2].clear();
					if (rank[r1] == rank[r2])
					{
						rank[r1]++;
					}
				}
			}
		};
	ll ans = 0;
	vector<deque<pii>>graph(n + 1);
	unordered_map<int, int>zero;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		zero[i] = temp;
		ans += temp;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!graph[i].empty())
		{
			sort(graph[i].begin(), graph[i].end());
		}
	}
	vector<int>id(n + 1, -1);
	int cnt = 0;
	auto bfs = [&](int node)
		{
			id[node] = cnt;
			queue<int>q;
			q.push(node);
			while (!q.empty())
			{
				int a = q.front();
				q.pop();
				for (auto& [_, b] : graph[a])
				{
					if (id[b] == -1)
					{
						id[b] = cnt;
						q.push(b);
					}
				}
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (id[i] == -1)
		{
			cnt++;
			bfs(i);
		}
	}
	if (cnt > k)
	{
		cout << -1;
		return 0;
	}
	vector<int>value(cnt + 1);
	for (int i = 1; i <= n; ++i)
	{
		value[id[i]]++;
	}
	int pivot = n;
	auto del = [&]
		{
			int wei = INT_MAX, v1 = -1, v2 = -1, vot = -1;
			vector<pii>mini(n + 1, make_pair(INT_MAX, -1));
			vector<int>vv;
			for (auto& [i, b] : zero) // 정점, 가중치
			{
				if (value[id[i]] == 1)
				{
					continue;
				}
				if (mini[find(i)].first == INT_MAX)
				{
					vv.push_back(find(i));
				}
				if (mini[find(i)].first > b)
				{
					mini[find(i)] = make_pair(b, i);
				}
			}
			for (auto& i : vv) // 정점 쌍.
			{
				int b = mini[i].first;
				for (auto& a : vers[i])
				{
					while (!graph[a].empty())
					{
						auto [c, d] = graph[a].front(); // 가중치, 정점
						int r1 = find(a), r2 = find(d);
						if (r1 == r2)
						{
							graph[a].pop_front();
							continue;
						}
						int temp = -b + c;
						if (temp < wei)
						{
							wei = temp;
							v1 = a, v2 = d, vot = mini[i].second;
						}
						break;
					}
				}
			}
			return make_tuple(v1, v2, wei, vot);
		};
	while (pivot > k)
	{
		auto [v1, v2, cost, vot] = del();
		merge(v1, v2);
		ans += cost;
		zero.erase(vot);
		graph[v1].pop_front();
		pivot--;
		value[id[v1]]--;
		int p = find(v1);
	}
	while (1)
	{
		auto [v1, v2, cost, vot] = del();
		if (cost >= 0)
		{
			break;
		}
		merge(v1, v2);
		ans += cost;
		zero.erase(vot);
		graph[v1].pop_front();
		pivot--;
		value[id[v1]]--;
		int p = find(v1);
	}
	cout << ans;
	return 0;
}