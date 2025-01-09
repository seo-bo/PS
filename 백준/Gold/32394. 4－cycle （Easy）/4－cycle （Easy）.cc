#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 그냥 무지성 백트래킹 돌리니까 시간초과지....
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!graph[i].empty())
		{
			sort(graph[i].begin(), graph[i].end());
		}
	}
	ll ans = 0;
	auto cal = [&](int a, int b)
		{
			ll cnt = 0;
			int idx = 0, jdx = 0;
			int alen = graph[a].size(), blen = graph[b].size();
			while (idx < alen && jdx < blen)
			{
				if (graph[a][idx] == graph[b][jdx])
				{
					cnt++;
					idx++;
					jdx++;
				}
				else if (graph[a][idx] < graph[b][jdx])
				{
					idx++;
				}
				else
				{
					jdx++;
				}
			}
			return cnt;
		};
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			ll pivot = cal(i, j);
			if (pivot >= 2)
			{
				ans += (pivot * (pivot - 1)) / 2;
			}
		}
	}
	cout << ((ans / 2) % MOD);
	return 0;
}