#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	if (n == k)
	{
		cout << 0;
		return 0;
	}
	vector<vector<int>>visited(2, vector<int>(500001, INT_MAX));
	queue<pii>q;
	visited[0][n] = 0;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		int cost = b + 1, p = cost % 2;
		if (a + 1 <= 500000 && visited[p][a + 1] > cost)
		{
			visited[p][a + 1] = cost;
			q.push(make_pair(a + 1, cost));
		}
		if (a - 1 >= 0 && visited[p][a - 1] > cost)
		{
			visited[p][a - 1] = cost;
			q.push(make_pair(a - 1, cost));
		}
		if (a * 2 <= 500000 && visited[p][a * 2] > cost)
		{
			visited[p][a * 2] = cost;
			q.push(make_pair(a * 2, cost));
		}
	}
	for (int i = 0; i <= 500000; ++i)
	{
		int pos = k + i * (i + 1) / 2;
		if (pos > 500000)
		{
			break;
		}
		if (visited[i % 2][pos] <= i)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}