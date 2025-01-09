#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<double>::infinity()
typedef double lb;
typedef tuple<int, int, int>ti;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	auto cal = [&](int px1, int py1, int px2, int py2) -> lb
		{
			lb res = 1;
			return sqrt((res * px1 - px2) * (res * px1 - px2) + (res * py1 - py2) * (res * py1 - py2));
		};
	int x1 = 0, y1 = 0, n = 0;
	lb pivot = 0, zero = 0;
	cin >> x1 >> y1 >> n;
	vector<vector<pair<int, lb>>>graph(n + 2);
	vector<lb>dis(n + 2, INF);
	vector<ti>v = { make_tuple(0,0,0) };
	pivot = cal(0, 0, x1, y1);
	for (int i = 1; i <= n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v.push_back(make_tuple(a, b, i));
	}
	v.push_back(make_tuple(x1, y1, n + 1));
	for (int i = 0; i < n + 2; ++i)
	{
		auto& [tx1, ty1, p1] = v[i];
		for (int j = i + 1; j < n + 2; ++j)
		{
			auto& [tx2, ty2, p2] = v[j];
			lb temp = cal(tx1, ty1, tx2, ty2);
			if (temp > pivot)
			{
				continue;
			}
			lb non = (lb)2 - ((v[i] == make_tuple(0, 0, 0)) + (v[j] == make_tuple(x1, y1, n + 1)));
			graph[p1].push_back(make_pair(p2, max(zero, temp - non)));
			graph[p2].push_back(make_pair(p1, max(zero, temp - non)));
		}
	}
	priority_queue<pair<lb, int>, vector<pair<lb, int>>, greater<pair<lb, int>>>pq;
	dis[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty())
	{
		auto [w, v] = pq.top();
		pq.pop();
		if (dis[v] < w)
		{
			continue;
		}
		for (auto& [nv, nw] : graph[v])
		{
			if (dis[nv] > dis[v] + nw)
			{
				dis[nv] = dis[v] + nw;
				pq.push(make_pair(dis[nv], nv));
			}
		}
	}
	cout << fixed << setprecision(12) << dis[n + 1];
	return 0;
}