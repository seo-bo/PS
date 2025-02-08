#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pii>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	priority_queue<pii, vector<pii>, greater<>>pq;
	vector<int>ans(n + 1, INT_MAX);
	ans[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		auto [a, b] = pq.top();
		pq.pop();
		if (ans[b] < a)
		{
			continue;
		}
		for (auto& [i, j] : graph[b])
		{
			if (ans[i] > ans[b] + j)
			{
				ans[i] = ans[b] + j;
				pq.push(make_pair(ans[i], i));
			}
		}
	}
	cout << ans[n];
	return 0;
}