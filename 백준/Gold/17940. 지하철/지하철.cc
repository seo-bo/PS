#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, ed = 0;
	cin >> n >> ed;
	vector<vector<pii>>graph(n);
	vector<pii>ans(n, make_pair((1 << 24), (1 << 24)));
	vector<int>sub(n, 0);
	for (auto& i : sub)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (!temp)
			{
				continue;
			}
			graph[i].push_back(make_pair(j, temp));
		}
	}
	priority_queue<ti, vector<ti>, greater<ti>>pq;
	ans[0] = make_pair(0, 0);
	pq.push(make_tuple(0, 0, 0)); // 환승 횟수 , 거리, 정점 번호
	while (!pq.empty())
	{
		auto [cnt, dis, node] = pq.top();
		pq.pop();
		if (ans[node].first < cnt || (ans[node].first == cnt && ans[node].second < dis))
		{
			continue;
		}
		for (auto& [i, j] : graph[node])
		{
			int ncnt = cnt + (sub[node] != sub[i]), ndis = j + ans[node].second;
			if (ans[i].first > ncnt || (ans[i].first == ncnt && ans[i].second > ndis))
			{
				ans[i] = make_pair(ncnt, ndis);
				pq.push(make_tuple(ncnt, ndis, i));
			}
		}
	}
	cout << ans[ed].first << ' ' << ans[ed].second;
	return 0;
}