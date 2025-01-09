#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n + 1);
	vector<ll>mindis(n + 1, LLONG_MAX);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<vector<pll>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	mindis[1] = v[1];
	pq.push(make_pair(v[1], 1));
	while (!pq.empty())
	{
		auto [a, b] = pq.top();
		pq.pop();
		if (a > mindis[b])
		{
			continue;
		}
		for (auto& i : graph[b])
		{
			auto [c, d] = i;
			if (mindis[b] + d + v[c] < mindis[c])
			{
				mindis[c] = mindis[b] + d + v[c];
				pq.push(make_pair(mindis[c], c));
			}
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		cout << mindis[i] << ' ';
	}
	return 0;
}
