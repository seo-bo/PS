#include <bits/stdc++.h>
#define INF 1e18
typedef long long ll;
typedef long double lb;
using namespace std;

struct edge
{
	ll vertex;
	ll weight;
	ll broke;
};

vector<edge>graph[100001]; // 정점 번호, 가중치, 부서지는 시간
ll mindis[100001] = { 0, };
int n = 0, m = 0;

bool dijkstra(ll start)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
	for (int i = 1; i <= n; ++i)
	{
		mindis[i] = INF;
	}
	mindis[1] = start;
	pq.push(make_pair(start, 1));
	while (!pq.empty())
	{
		pair<ll,ll> cur = pq.top();
		pq.pop();
		if (mindis[cur.second] < cur.first)
		{
			continue;
		}
		for (auto& i : graph[cur.second])
		{
			if (cur.first + i.weight <= i.broke && mindis[i.vertex] > cur.first + i.weight)
			{
				mindis[i.vertex] = cur.first + i.weight;
				pq.push({ mindis[i.vertex], i.vertex });
			}
		}
	}
	return mindis[n] != INF;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll start = 0, end = 0, weight = 0, brok = 0;
		cin >> start >> end >> weight >> brok;
		graph[start].push_back({ end, weight, brok });
		graph[end].push_back({ start, weight, brok });
	}
	ll left = 0, right = 1e18, result = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		if (dijkstra(mid))
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << result;
	return 0;
}