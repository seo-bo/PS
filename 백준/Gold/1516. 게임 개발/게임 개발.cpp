#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>graph[501];
int cost[501] = { 0, }; // 각 건물을 생성하는데 걸리는 시간
ll dp[501] = { 0, };
int degree[501] = { 0, };
int vertex = 0;

void topo_sort()
{
	queue<int>q;
	for (int i = 1; i <= vertex; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
			dp[i] = cost[i]; // ? 여기서 dp 테이블 갱신해주는게 맞나?
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (auto& i : graph[current])
		{
			dp[i] = max(dp[i], dp[current] + cost[i]);
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
	int temp = 0;
	cin >> vertex;
	for (int i = 1; i <= vertex; ++i)
	{
		dp[i] = -1;
		int count = 0;
		while (1)
		{
			cin >> temp;
			if (temp == -1)
			{
				break;
			}
			if (!count)
			{
				cost[i] = temp;
			}
			else
			{
				graph[temp].push_back(i);
				degree[i]++;
			}
			count++;
		}
	}
	topo_sort();
	for (int i = 1; i <= vertex; ++i)
	{
		cout << dp[i] << "\n";
	}
	return 0;
}