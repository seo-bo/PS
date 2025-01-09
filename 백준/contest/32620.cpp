#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, r = 0;
	cin >> n >> m >> r;
	vector<ll>A(n + 1, 0), B(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> B[i];
	}
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<bool>visited(n + 1, false), in(n + 1, false);
	priority_queue<pll>maxpq;
	priority_queue<pll, vector<pll>, greater<pll>>minpq;
	visited[r] = true;
	ll ans = B[r];
	auto pushing = [&](int pivot)
		{
			for (auto& i : graph[pivot])
			{
				if (!visited[i] && !in[i])
				{
					if (A[i] <= ans)
					{
						maxpq.push(make_pair(B[i], i));
					}
					else
					{
						minpq.push(make_pair(A[i], i));
					}
					in[i] = true;
				}
			}
		};
	pushing(r);
	while (!maxpq.empty())
	{
		auto [w, v] = maxpq.top();
		maxpq.pop();
		if (visited[v])
		{
			continue;
		}
		if (A[v] <= ans)
		{
			visited[v] = true;
			ans += w;
			pushing(v);
		}
		while (!minpq.empty() && minpq.top().first <= ans)
		{
			auto [_, v2] = minpq.top();
			minpq.pop();
			if (!visited[v2])
			{
				maxpq.push(make_pair(B[v2], v2));
			}
		}
	}
	cout << ans;
	return 0;
}
