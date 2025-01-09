#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>a(n + 1), b(n + 1), ans(n + 1, LLONG_MAX);
	vector<vector<ll>>graph(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	for (int i = 1; i <= n; ++i)
	{
		bool check = false;
		if (i + a[i] > n || i - a[i] < 1)
		{
			check = true;
		}
		if (check)
		{
			if (b[i] < ans[i])
			{
				ans[i] = b[i];
				pq.push(make_pair(ans[i], i));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i + a[i] <= n)
		{
			graph[i + a[i]].push_back(i);
		}
		if (i - a[i] >= 1)
		{
			graph[i - a[i]].push_back(i);
		}
	}
	while (!pq.empty())
	{
		auto [A, B] = pq.top();
		pq.pop();
		if (ans[B] < A)
		{
			continue;
		}
		for (auto& i : graph[B])
		{
			if (ans[i] > ans[B] + b[i])
			{
				ans[i] = ans[B] + b[i];
				pq.push(make_pair(ans[i], i));
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}