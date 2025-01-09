#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1), inv(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		inv[b].push_back(a);
	}
	vector<int>visited(n + 1, -1);
	queue<int>q;
	q.push(1);
	visited[1] = 0;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& i : inv[a])
		{
			if (visited[i] == -1)
			{
				visited[i] = visited[a] + 1;
				q.push(i);
			}
		}
	}
	int ans = INT_MAX;
	for (auto& i : graph[1])
	{
		if (visited[i] != -1)
		{
			ans = min(ans, 1 + visited[i]);
		}
	}
	cout << ((ans == INT_MAX) ? -1 : ans);
	return 0;
}
