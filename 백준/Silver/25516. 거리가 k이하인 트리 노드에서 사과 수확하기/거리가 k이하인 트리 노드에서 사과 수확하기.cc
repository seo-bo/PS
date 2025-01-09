#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
vector<int>graph[100001];
int apple[100001] = { 0, };
int visited[100001] = { 0, };
ll result = 0;
int edge = 0, dis = 0;

void dfs(int start = 0, int depth = 0)
{
	if (depth > dis)
	{
		return;
	}
	result += apple[start];
	visited[start] = 1;
	for (auto& i : graph[start])
	{
		if (!visited[i])
		{
			dfs(i, depth + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> edge >> dis;
	for (int i = 0; i < edge - 1; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 0; i < edge; ++i)
	{
		cin >> apple[i];
	}
	dfs();
	cout << result;
	return 0;
}