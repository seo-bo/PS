#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl;

int main(void) // weight는 mod 4만 저장하면 되지않음?
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>pivot(4, INT_MAX);
	pll a, b;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	queue<tl>q;
	q.push(make_tuple(a.first, a.second, 0));
	vector<vector<vector<bool>>>visited(1001, vector<vector<bool>>(1001, vector<bool>(4, false)));
	visited[a.first + 500][a.second + 500][0] = true;
	auto [x, y] = b;
	while (!q.empty())
	{
		auto [n, i, w] = q.front(); // 정수, 허수
		if (n == x && i == y)
		{
			pivot[w % 4] = min(pivot[w % 4], w);
		}
		q.pop();
		if (llabs(n + 1) <= 500 && !visited[n + 501][i + 500][(w + 1) % 4])
		{
			visited[n + 501][i + 500][(w + 1) % 4] = true;
			q.push(make_tuple(n + 1, i, w + 1));
		}
		if (llabs(n * 2) <= 500 && llabs(i * 2) <= 500 && !visited[n * 2 + 500][i * 2 + 500][(w + 1) % 4])
		{
			visited[n * 2 + 500][i * 2 + 500][(w + 1) % 4] = true;
			q.push(make_tuple(n * 2, i * 2, w + 1));
		}
		if (!visited[-i + 500][n + 500][(w + 1) % 4])
		{
			visited[-i + 500][n + 500][(w + 1) % 4] = true;
			q.push(make_tuple(-i, n, w + 1));
		}
	}
	int qe = 0;
	cin >> qe;
	while (qe--)
	{
		int a = 0;
		cin >> a;
		if (pivot[a % 4] <= a && pivot[a % 4] != INT_MAX)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}