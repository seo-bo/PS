#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	vector<vector<int>>rgraph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		int sc = 0, lc = 0;
		vector<bool>visited(n + 1, false);
		queue<int>q;
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int _ = q.front();
			q.pop();
			for (auto& i : graph[_])
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
					sc++;
				}
			}
		}
		vector<bool>(n + 1, false).swap(visited);
		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int _ = q.front();
			q.pop();
			for (auto& i : rgraph[_])
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
					lc++;
				}
			}
		}
		if (sc + lc == n - 1)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}