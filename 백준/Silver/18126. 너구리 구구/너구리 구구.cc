#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<pair<ll, ll>>graph[5001];
bool visited[5001];
ll result = 0;

void dfs(int cur = 1, ll sum = 0)
{
	visited[cur] = true;
	result = max(result, sum);
	for (auto& i : graph[cur])
	{
		if (!visited[i.first])
		{
			visited[i.first] = true;
			dfs(i.first, sum + i.second);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	for (int i = 0; i < num - 1; ++i)
	{
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		graph[start].push_back(make_pair(end, weight));
		graph[end].push_back(make_pair(start, weight));
	}
	dfs();
	cout << result;
	return 0;
}
