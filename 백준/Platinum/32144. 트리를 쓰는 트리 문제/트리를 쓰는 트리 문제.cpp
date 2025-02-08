#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)// dfs 총 두번돌려야하나??? 바텀업이랑 탑 다운? 정점 반갈죽?
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<vector<pii>>save(n + 1, vector<pii>(2, make_pair(0, 0))); // 제일 큰거 / 두번째로 큰거 길이, 정점 번호
	vector<int>parent(n + 1, 0), down(n + 1, 0), top(n + 1, 0), ans(n + 1, 0);
	for (int i = 2; i <= n; ++i)
	{
		cin >> parent[i];
		graph[parent[i]].push_back(i);
	}
	function<void(int)> bottom_up = [&](int node) // bottom - up
		{
			int p = parent[node];
			for (auto& i : graph[node])
			{
				bottom_up(i);
			}
			vector<pii> temp = { save[p][0], save[p][1], make_pair(save[node][0].first + 1, node) };
			sort(temp.begin(), temp.end(), [&](const pii& a, const pii& b)
				{
					return a.first > b.first;
				});
			save[p][0] = temp[0], save[p][1] = temp[1];
			down[node] = max(down[node], save[node][0].first + save[node][1].first);
			down[p] = max(down[p], down[node]);
		};
	function<void(int)> top_down = [&](int node) // top - down
		{
			int p = parent[node];
			if (node != 1 && p != 1)
			{
				top[node] = top[p] + 1;
			}
			if (save[p][0].second == node) // 젤 큰거 못가져감
			{
				top[node] = max(top[node], save[p][1].first);
			}
			else // 젤 큰거
			{
				top[node] = max(top[node], save[p][0].first);
			}
			for (auto& i : graph[node])
			{
				top_down(i);
			}
			ans[node] = top[node] + down[node] + 1;
		};
	bottom_up(1);
	top_down(1);
	for (int i = 2; i <= n; ++i)
	{
		cout << max(down[1], ans[i]) << ' ';
	}
	return 0;
}