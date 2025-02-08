#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int visited[100005];
bool first_visit = false;
int st = INT_MAX;
int way = 0;
int N = 0, K = 0;

void bfs()
{
	queue<pair<int, int>>q; // 위치, cnt;
	q.push(make_pair(N, 0));
	visited[N] = 1;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		visited[cur.first] = 1;
		if (first_visit && st == cur.second && cur.first == K)
		{
			way++;
		}
		if (!first_visit && cur.first == K) // 카운트 재주기(처음처리까지 ㅇㅋ)
		{
			st = cur.second;
			first_visit = true;
			way++;
		}
		if (cur.first - 1 >= 0 && cur.first - 1 <= 100000 && !visited[cur.first - 1])
		{
			q.push(make_pair(cur.first - 1, cur.second + 1));
		}
		if (cur.first + 1 >= 0 && cur.first + 1 <= 100000 && !visited[cur.first + 1])
		{
			q.push(make_pair(cur.first + 1, cur.second + 1));
		}
		if (cur.first * 2 >= 0 && cur.first * 2 <= 100000 && !visited[cur.first * 2])
		{
			q.push(make_pair(cur.first * 2, cur.second + 1));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	bfs();
	cout << st << "\n" << way;
	return 0;
}