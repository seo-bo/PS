#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	while (1)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<int>temp, parent(n + 1, 0), rank(n + 1, 0);
		function<int(int)> find = [&](int root)
			{
				if (parent[root] == root)
				{
					return parent[root];
				}
				return parent[root] = find(parent[root]);
			};
		auto merge = [&](int root1, int root2)
			{
				int r1 = find(root1);
				int r2 = find(root2);
				if (r1 != r2)
				{
					if (rank[r2] > rank[r1])
					{
						parent[r1] = r2;
					}
					else if (rank[r2] < rank[r1])
					{
						parent[r2] = r1;
					}
					else
					{
						parent[r2] = r1;
						rank[r1]++;
					}
				}
			};
		iota(parent.begin(), parent.end(), 0);
		temp = parent;
		if (!n && !m)
		{
			break;
		}
		vector<ti>graph(m);
		for (auto& [a, b, c] : graph)
		{
			cin >> b >> c >> a;
		}
		sort(graph.begin(), graph.end()); // 간선의 가중치를 오름차순으로 정렬하기!?
		int ans = INT_MAX, pre = -1;
		for (int left = 0; left < m;)
		{
			while (left < m && pre == get<0>(graph[left]))
			{
				left++;
			}
			if (left == m)
			{
				break;
			}
			pre = get<0>(graph[left]);
			parent = temp;
			vector<int>(n + 1, 0).swap(rank);
			int e = 0;
			for (int right = left; right < m; ++right)
			{
				auto [w, a, b] = graph[right];
				int r1 = find(a), r2 = find(b);
				if (r1 != r2)
				{
					merge(a, b);
					e++;
				}
				if (e == n - 1)
				{
					ans = min(ans, w - pre);
					break;
				}
			}
		}
		cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
	}
	return 0;
}