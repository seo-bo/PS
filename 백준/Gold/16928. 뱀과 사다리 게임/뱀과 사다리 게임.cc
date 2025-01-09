#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int>v(101);
	iota(v.begin(), v.end(), 0);
	vector<bool>visited(101, false);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < n + m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a] = b;
	}
	queue<pii>q;
	q.push(make_pair(1, 0));
	visited[1] = true;
	while (!q.empty())
	{
		auto [a, b] = q.front();
		if (a == 100)
		{
			cout << b;
			return 0;
		}
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int nx = a + i;
			if (nx <= 100 && !visited[v[nx]])
			{
				visited[v[nx]] = true;
				q.push(make_pair(v[nx], b + 1));
			}
		}
	}
	return 0;
}