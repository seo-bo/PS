#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

void dfs(vector<int>graph[], vector<bool>& visited, int start)
{
	for (auto& i : graph[start])
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(graph, visited, i);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll result = 0;
		int n = 0;
		cin >> n;
		vector<int>graph[1001];
		vector<bool>visited(n + 1, false);
		for (int i = 1; i <= n; ++i)
		{
			int temp = 0;
			cin >> temp;
			graph[i].push_back(temp);
		}
		for (int i = 1; i <= n; ++i)
		{
			if (!visited[i])
			{
				result++;
				dfs(graph, visited, i);
			}
		}
		cout << result << "\n";
	}
	return 0;
}