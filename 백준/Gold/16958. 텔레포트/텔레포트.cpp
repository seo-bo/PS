#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, T = 0;
	cin >> n >> T;
	vector<pii>v(n + 1);
	vector<int>ok, dist(n + 1, 1e8);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		auto& [a, b] = v[i];
		cin >> temp >> a >> b;
		if (temp)
		{
			ok.push_back(i);
		}
	}
	auto cal = [&](int a, int b)
		{
			return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
		};
	for (int i = 1; i <= n; ++i)
	{
		for (auto& j : ok)
		{
			dist[i] = min(dist[i], cal(i, j));
		}
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		cout << min(cal(a, b), dist[a] + dist[b] + T) << '\n';
	}
	return 0;
}