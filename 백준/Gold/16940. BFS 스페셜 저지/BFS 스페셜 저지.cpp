#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int>ti;
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
	vector<int>pri(n + 1, 0), order(n + 1, 0);
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		cin >> order[i];
		pri[order[i]] = i;
	}
	priority_queue<ti, vector<ti>, greater<ti>>pq;
	pq.push(make_tuple(1, pri[1], 1)); // 삽입, 우선순위, 정점 번호
	visited[1] = true;
	int idx = 1, psh = 1;
	while (!pq.empty())
	{
		auto [cnt, _, ver] = pq.top();
		pq.pop();
		if (order[idx] != ver)
		{
			cout << 0;
			return 0;
		}
		idx++;
		for (auto& i : graph[ver])
		{
			if (!visited[i])
			{
				visited[i] = true;
				pq.push(make_tuple(psh, pri[i], i));
			}
		}
		psh++;
	}
	cout << 1;
	return 0;
}