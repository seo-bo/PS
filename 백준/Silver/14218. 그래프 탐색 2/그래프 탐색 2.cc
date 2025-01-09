#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>graph[1001];

int main(void) // 플로이드 워셜을 쓰면 안될지도
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	int q = 0;
	cin >> q;
	while (q--)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
		vector<int>dis(n + 1, -1); // 방문 역할도 하고, 거리 재는 용도
		queue<int>q;
		q.push(1);
		dis[1] = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (auto& i : graph[cur])
			{
				if (dis[i] == -1) // 방문 안했으면
				{
					dis[i] = dis[cur] + 1;
					q.push(i);
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			cout << dis[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}