#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>graph[300000];
int visited[300050] = { 0, };
int N = 0, M = 0, S = 0, E = 0;

void bfs()
{
	queue<int>q;
	visited[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == E)
		{
			cout << visited[cur] - 1;
			return;
		}
		if (cur - 1 >= 0 && !visited[cur - 1])
		{
			visited[cur - 1] = visited[cur] + 1;
			q.push(cur - 1);
		}
		if (cur + 1 <= N && !visited[cur + 1])
		{
			visited[cur + 1] = visited[cur] + 1;
			q.push(cur + 1);
		}
		for (auto& i : graph[cur])
		{
			if (!visited[i])
			{
				visited[i] = visited[cur] + 1;
				q.push(i);
			}
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	bfs();
	return 0;
}