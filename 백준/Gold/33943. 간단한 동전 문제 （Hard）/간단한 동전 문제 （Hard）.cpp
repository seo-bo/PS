#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	m += 15000;
	vector<int>visited(30002, INT_MAX);
	visited[15000] = 0;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	queue<int>q;
	q.push(15000);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == m)
		{
			cout << visited[cur];
			return 0;
		}
		for (auto& i : v)
		{
			int pivot = cur + i;
			if (!(pivot >= 0 && pivot <= 30000))
			{
				continue;
			}
			if (visited[pivot] > visited[cur] + 1)
			{
				visited[pivot] = visited[cur] + 1;
				q.push(pivot);
			}
		}
	}
	cout << -1;
	return 0;
}