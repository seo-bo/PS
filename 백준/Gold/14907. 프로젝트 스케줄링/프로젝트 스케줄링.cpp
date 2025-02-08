#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>graph[30];
int degree[30] = { 0, };
int cost[30] = { 0, };
int vertex = 0;
ll dp[30] = { 0, };
ll result = 0;

void topo_sort()
{
	queue<int>q;
	for (int i = 1; i <= 29; ++i)
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
			result = max(result, dp[i]);
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
	string str;
	while (getline(cin, str))
	{
		int start = str[0] - 'A' + 1;
		int k = 2, num = 0;
		while ('0' <= str[k] && str[k] <= '9')
		{
			num = num * 10 + (str[k] - '0');
			k++;
		}
		cost[start] = num;
		if (k == str.length())
		{
			continue;
		}
		k++;
		for (int i = k; i < str.length(); i++)
		{
			int end = str[i] - 'A' + 1;
			graph[start].push_back(end);
			degree[end]++;
		}
	}
	topo_sort();
	cout << result;
	return 0;
}