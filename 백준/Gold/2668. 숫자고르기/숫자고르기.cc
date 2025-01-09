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
	int n = 0, cnt = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>in(n + 1, 0), ans;
	vector<bool>visited(n + 1, false);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		graph[i].push_back(a);
		in[a]++;
	}
	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (!in[i])
		{
			q.push(i);
			visited[i] = true;
		}
	}
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& i : graph[a])
		{
			if (!(--in[i]))
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}