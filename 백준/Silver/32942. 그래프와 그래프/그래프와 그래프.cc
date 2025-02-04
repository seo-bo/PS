#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	vector<vector<int>>graph(11);
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			if (a * i + b * j == c)
			{
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= 10; ++i)
	{
		if (graph[i].empty())
		{
			cout << 0 << '\n';
			continue;
		}
		sort(graph[i].begin(), graph[i].end());
		for (auto& j : graph[i])
		{
			cout << j << ' ';
		}
		cout << '\n';
	}
	return 0;
}