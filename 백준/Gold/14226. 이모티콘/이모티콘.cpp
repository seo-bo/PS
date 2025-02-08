#include <bits/stdc++.h>
using namespace std;

int visited[1001][1001] = { 0, };
queue<pair<pair<int, int>, int>>q;
int bfs(int num)
{
	visited[1][0] = 1;
	q.push(make_pair(make_pair(1, 0), 0));
	while (!q.empty())
	{
		pair<pair<int, int>, int> check = q.front();
		q.pop();
		if (check.first.first == num)
		{
			return check.second;
		}
		if (!visited[check.first.first][check.first.first])
		{
			visited[check.first.first][check.first.first] = 1;
			q.push(make_pair(make_pair(check.first.first, check.first.first), check.second + 1));
		}
		if (check.first.first - 1 >= 0 && !visited[check.first.first - 1][check.first.second])
		{
			visited[check.first.first - 1][check.first.second] = 1;
			q.push(make_pair(make_pair(check.first.first - 1, check.first.second), check.second + 1));
		}
		if (check.first.first + check.first.second < 1001 && check.first.second && !visited[check.first.first + check.first.second][check.first.second])
		{
			visited[check.first.first + check.first.second][check.first.second] = 1;
			q.push(make_pair(make_pair(check.first.first + check.first.second, check.first.second), check.second + 1));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	cout << bfs(num);
	return 0;
}