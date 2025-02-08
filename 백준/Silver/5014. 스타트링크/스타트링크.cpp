#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int f = 0, s = 0, g = 0, u = 0, d = 0;
	cin >> f >> s >> g >> u >> d;
	vector<bool>visited(f + 1);
	visited[s] = true;
	queue<pii>q;
	q.push(make_pair(s, 0));
	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		if (cur.first == g)
		{
			cout << cur.second;
			return 0;
		}
		if (cur.first + u <= f && !visited[cur.first + u])
		{
			visited[cur.first + u] = true;
			q.push(make_pair(cur.first + u, cur.second + 1));
		}
		if (cur.first - d >= 1 && !visited[cur.first - d])
		{
			visited[cur.first - d] = true;
			q.push(make_pair(cur.first - d, cur.second + 1));
		}
	}
	cout << "use the stairs";
	return 0;
}