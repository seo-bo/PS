#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cost[10001] = { 0, };
int degree[10001] = { 0, };
vector<int>graph[10001];
ll dp[10001] = { 0, };
int vertex = 0, temp = 0, num = 0;
ll result = 0;

void topo()
{
	queue<int>q;
	for (int i = 1; i <= vertex; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
			dp[i] = cost[i];
			result = max(dp[i], result);
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (auto& i : graph[current])
		{
			dp[i] = max(dp[i], dp[current] + cost[i]);
			result = max(dp[i], result);
			if (!(--degree[i]))
			{
				q.push(i);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> vertex;
	for (int i = 1; i <= vertex; ++i)
	{
		cin >> cost[i] >> temp;
		for (int k = 0; k < temp; ++k)
		{
			cin >> num;
			graph[num].push_back(i);
			degree[i]++;
		}
	}
	topo();
	cout << result;
	return 0;
}
