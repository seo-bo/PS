#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>graph[100001];
ll dp[100001] = { 0, };

void dfs(int node)
{
	for (auto& i : graph[node])
	{
		dp[i] += dp[node];
		dfs(i);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, query = 0;
	cin >> num >> query;
	for (int i = 1; i <= num; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp != -1)
		{
			graph[temp].push_back(i);
		}
	}
	for (int i = 0; i < query; ++i)
	{
		int idx = 0;
		ll value = 0;
		cin >> idx >> value;
		dp[idx] += value;
	}
	dfs(1);
	for (int i = 1; i <= num; ++i)
	{
		cout << dp[i] << " ";
	}
	return 0;
}