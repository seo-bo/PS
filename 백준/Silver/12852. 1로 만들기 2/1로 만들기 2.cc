#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int N = 0;
pair<int, int> visited[1000005];

void dfs(int i)
{
	cout << i << " ";
	if (visited[i].second == -1)
	{
		return;
	}
	dfs(visited[i].second);
}

void bfs()
{
	queue<int>q;
	q.push(1);
	visited[1] = make_pair(1, -1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == N)
		{
			cout << visited[N].first - 1 << "\n";
			dfs(N);
			return;
		}
		if (cur + 1 <= 1000005 && !visited[cur + 1].first)
		{
			visited[cur + 1].first = visited[cur].first + 1;
			visited[cur + 1].second = cur;
			q.push(cur + 1);
		}
		if (cur * 2 <= 1000005 && !visited[cur * 2].first)
		{
			visited[cur * 2].first = visited[cur].first + 1;
			visited[cur * 2].second = cur;
			q.push(cur * 2);
		}
		if (cur * 3 <= 1000005 && !visited[cur * 3].first)
		{
			visited[cur * 3].first = visited[cur].first + 1;
			visited[cur * 3].second = cur;
			q.push(cur * 3);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	bfs();
	return 0;
}