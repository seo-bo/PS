#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A = 0, B = 0, n = 0, m = 0;
	cin >> A >> B >> n >> m;
	vector<bool>visited(100001, false);
	queue<pii>q;
	vector<int>dir = { 1,-1,A,-A,B,-B };
	visited[n] = true;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		auto [cur, b] = q.front();
		q.pop();
		if (cur == m)
		{
			cout << b;
			return 0;
		}
		for (auto& i : dir)
		{
			int nx = cur + i;
			if (0 <= nx && nx <= 100000 && !visited[nx])
			{
				visited[nx] = true;
				q.push(make_pair(nx, b + 1));
			}
		}
		if (cur * A <= 100000 && !visited[cur * A])
		{
			visited[cur * A] = true;
			q.push(make_pair(cur * A, b + 1));
		}
		if (cur * B <= 100000 && !visited[cur * B])
		{
			visited[cur * B] = true;
			q.push(make_pair(cur * B, b + 1));
		}
	}
	return 0;
}