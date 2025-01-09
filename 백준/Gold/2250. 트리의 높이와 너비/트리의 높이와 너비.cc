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
	int n = 0;
	cin >> n;
	vector<vector<pii>>graph(n + 1);
	vector<int>in(n + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, -1));
		graph[a].push_back(make_pair(c, 1));
		if (b != -1)
		{
			in[b]++;
		}
		if (c != -1)
		{
			in[c]++;
		}
	}
	int start = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!in[i])
		{
			start = i;
			break;
		}
	}
	vector<vector<pii>>level(n + 4);
	int cnt = 0;
	function<void(int, int)> dfs = [&](int depth, int node)
		{
			bool flag = false;
			for (auto& [i, j] : graph[node])
			{
				if (j == -1)
				{
					if (i == -1)
					{
						continue;
					}
					dfs(depth + 1, i);
				}
				else if (j == 1)
				{
					if (i != -1)
					{
						level[depth].push_back(make_pair(cnt++, node));
						flag = true;
						dfs(depth + 1, i);
					}
				}
			}
			if (!flag)
			{
				level[depth].push_back(make_pair(cnt++, node));
			}
		};
	dfs(1, start);
	int pivot = 0, ans = 0;
	for (int i = 1; ; ++i)
	{
		if (level[i].empty())
		{
			break;
		}
		int temp = level[i].back().first - level[i].front().first + 1;
		if (temp > pivot)
		{
			pivot = temp;
			ans = i;
		}
	}
	cout << ans << ' ' << pivot;
	return 0;
}