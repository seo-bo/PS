#include <bits/stdc++.h>
using namespace std;

int visited[1000010][2] = { 0, };
int a = 0, b = 0;

int bfs(int start)
{
	queue<pair<int, int>>q;
	q.push(make_pair(start, 0));
	while (!q.empty())
	{
		pair<int, int> current = q.front();
		q.pop();
		if (current.first == b) // 10배를 안쓰는게 최단경로일수도 있음 ㅇㅇ
		{
			if (!visited[current.first][0])
			{
				return visited[current.first][1];
			}
			else if (!visited[current.first][1])
			{
				return visited[current.first][0];
			}
			return min(visited[current.first][0], visited[current.first][1]);
		}
		if (current.first + 1 <= b && !visited[current.first + 1][current.second])
		{
			int temp = current.first + 1;
			q.push(make_pair(temp, current.second));
			visited[temp][current.second] = visited[current.first][current.second] + 1;
		}
		if (current.first * 2 <= b && !visited[current.first * 2][current.second])
		{
			int temp = current.first * 2;
			q.push(make_pair(temp, current.second));
			visited[temp][current.second] = visited[current.first][current.second] + 1;
		}
		if (!current.second && current.first * 10 <= b && !visited[current.first * 10][1])
		{
			int temp = current.first * 10;
			q.push(make_pair(temp, 1));
			visited[temp][1] = visited[current.first][current.second] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	cout << bfs(a);
	return 0;
}