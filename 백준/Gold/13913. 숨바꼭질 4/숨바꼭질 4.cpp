#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

int N = 0, K = 0;
pair<int, int> visited[100001];

void bfs()
{
	queue<int>q;
	q.push(N);
	visited[N].first = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == K)
		{
			return;
		}
		if (cur - 1 >= 0 && !visited[cur - 1].first)
		{
			q.push({ cur - 1 });
			visited[cur - 1].first = visited[cur].first + 1;
			visited[cur - 1].second = cur;
		}
		if (cur + 1 <= 100000 && !visited[cur + 1].first)
		{
			q.push({ cur + 1 });
			visited[cur + 1].first = visited[cur].first + 1;
			visited[cur + 1].second = cur;
		}
		if (cur * 2 <= 100000 && !visited[cur * 2].first)
		{
			q.push({ cur * 2 });
			visited[cur * 2].first = visited[cur].first + 1;
			visited[cur * 2].second = cur;
		}
	}
}

void dfs(int start)
{
	if (start == N)
	{
		cout << N << " ";
		return;
	}
	dfs(visited[start].second);
	cout << start << " ";
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	bfs();
	cout << visited[K].first - 1 << "\n";
	dfs(K);
	return 0;
}