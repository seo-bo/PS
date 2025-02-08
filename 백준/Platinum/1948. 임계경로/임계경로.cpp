#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vertex = 0, edge = 0, start = 0, fin = 0;
vector<pair<int, int>>graph[10001];
vector<pair<int, int>>chase[10001];
int degree[10001], visited[10001] = { 0, };;
ll dp[10001] = { 0, }, result = 0;

void topo_sort()
{
	queue<pair<int, ll>>q;
	q.push(make_pair(start, 0));
	dp[start] = 0;
	while (!q.empty())
	{
		pair<int, ll> temp = q.front();
		q.pop();
		for (auto& i : graph[temp.first])
		{
			dp[i.first] = max(dp[i.first], dp[temp.first] + i.second);
			if (!(--degree[i.first]))
			{
				q.push(make_pair(i.first, dp[i.first]));
			}
		}
	}
}

void back_track()
{
	queue < pair<int, ll> > q;
	q.push(make_pair(fin, 0));
	visited[fin] = 1;
	while (!q.empty())
	{
		pair<int, ll>current = q.front();
		q.pop();
		for (auto& i : chase[current.first])
		{
			if (dp[current.first] - i.second == dp[i.first])
			{
				result++;
				if (!visited[i.first])
				{
					visited[i.first] ^= 1;
					q.push(i);
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex >> edge;
	for (int i = 0; i < edge; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		chase[b].push_back(make_pair(a, c));
		degree[b]++;
	}
	cin >> start >> fin;
	topo_sort();
	back_track();
	cout << dp[fin] << "\n";
	cout << result;
	return 0;
}