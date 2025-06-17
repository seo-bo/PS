#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	map<pii, int>visited;
	visited[make_pair(0, 0)] = 0;
	queue<pii>q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		pii base = q.front();
		q.pop();
		auto [pa, pb] = base;
		if (pa == c && pb == d)
		{
			cout << visited[base];
			return 0;
		}
		int ta = min(pa, b - pb), tb = min(pb, a - pa);
		vector<pii>temp = { make_pair(a, pb) ,make_pair(pa, b),make_pair(0, pb)
		, make_pair(pa, 0) ,make_pair(pa - ta, pb + ta), make_pair(pa + tb, pb - tb) };
		for (auto& i : temp)
		{
			if (i == base)
			{
				continue;
			}
			if (visited.find(i) == visited.end() || visited[i] > visited[base] + 1)
			{
				visited[i] = visited[base] + 1;
				q.push(i);
			}
		}
	}
	cout << -1;
	return 0;
}