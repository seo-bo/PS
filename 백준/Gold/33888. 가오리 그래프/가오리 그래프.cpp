#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1);
	for (int i = 0; i < n + 3; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++;
		degree[b]++;
	}
	int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
	set<int>temp;
	for (int i = 1; i <= n; ++i)
	{
		if (degree[i] == 2)
		{
			continue;
		}
		if (degree[i] == 1)
		{
			F = i;
		}
		else
		{
			temp.insert(i);
		}
	}
	function<bool(int, int)> dfs = [&](int par, int node)
		{
			for (auto& i : graph[node])
			{
				if (i == par)
				{
					continue;
				}
				if (temp.find(i) != temp.end())
				{
					E = i;
					temp.erase(E);
					return true;
				}
				if (dfs(node, i))
				{
					return true;
				}
			}
			return false;
		};
	dfs(0, F);
	for (auto& i : temp)
	{
		if (degree[i] == 4 && i != E)
		{
			C = i;
			break;
		}
	}
	temp.erase(C);
	vector<int>visited(n + 1, false);
	visited[F] = visited[E] = visited[C] = true;
	queue<int>q;
	q.push(E);
	vector<int>tt;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (visited[i])
			{
				continue;
			}
			visited[i] = true;
			if (temp.find(i) != temp.end())
			{
				tt.push_back(i);
				temp.erase(i);
			}
			else
			{
				q.push(i);
			}
		}
	}
	D = max(tt[0], tt[1]);
	B = min(tt[0], tt[1]);
	A = *temp.begin();
	cout << format("{} {} {} {} {} {}", A, B, C, D, E, F);
	return 0;
}