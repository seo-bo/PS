#include <bits/stdc++.h>
#define INF LLONG_MAX
typedef long long ll;
typedef long double lb;
using namespace std;

int v = 0, e = 0;
ll result = 0;
vector<pair<ll, ll>>graph[200005];
vector<ll>mindis;
vector<pair<ll, ll>>cost; // 직전 정점, 직전 정점 ~ 다음 정점까지 비용 저장

struct cmp
{
	bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b)
	{
		return a.second > b.second;
	}
};

void dijkstra()
{
	mindis.resize(v + 3, INF);
	cost.resize(v + 3);
	mindis[1] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp>pq; // first = 정점, second = 가중치
	pq.push(make_pair(1, 0));
	while (!pq.empty())
	{
		pair<ll, ll>cur = pq.top();
		pq.pop();
		if (mindis[cur.first] < cur.second)
		{
			continue;
		}
		for (auto& i : graph[cur.first])
		{
			if (mindis[i.first] > (mindis[cur.first] + i.second))
			{
				mindis[i.first] = mindis[cur.first] + i.second;
				pq.push(make_pair(i.first, mindis[i.first]));
				cost[i.first] = make_pair(cur.first, i.second); // i.first의 cost는 cur.first 에서 i.second만큼듬
			}
			else if (mindis[i.first] == (mindis[cur.first] + i.second)) // 2 - 3 - 5 / 2 - 4 - 5 같은거면?, 즉 같을때를 처리해줘야하지않아?
			{
				cost[i.first] = (cost[i.first].second > i.second) ? make_pair(cur.first, i.second) : cost[i.first];
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		ll start = 0, end = 0, wei = 0;
		cin >> start >> end >> wei;
		graph[start].push_back(make_pair(end, wei));
		graph[end].push_back(make_pair(start, wei));
	}
	dijkstra();
	for (int i = 2; i <= v; ++i)
	{
		//cout << i << "번정점 : " << mindis[cost[i].first] << "  " << cost[i].second << "\n";
		// result += (mindis[i]*0.9) + cost[i].second; <- 내가 원하는 정점까지의 최단거리가 아니고, 그 직전까지의 최단거리가 필요함
		result += (mindis[cost[i].first] * 0.9) + cost[i].second;
	}
	cout << result;
	return 0;
}

