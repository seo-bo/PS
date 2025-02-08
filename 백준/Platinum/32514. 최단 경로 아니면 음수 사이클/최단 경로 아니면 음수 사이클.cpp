#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, s = 0;
	cin >> n >> m >> s;
	vector<ti>graph(m);
	vector<pii>dis(n, make_pair(INF, -1));
	for (auto& [a, b, c] : graph)
	{
		cin >> a >> b >> c;
	}
	bool flag = true;
	dis[s] = make_pair(0, -1);
	int x = -1;
	for (int k = 1; k <= n; ++k)
	{
		for (auto& [st, ed, c] : graph)
		{
			if (dis[st].first == INF)
			{
				continue;
			}
			if (dis[ed].first > dis[st].first + c)
			{

				dis[ed].first = dis[st].first + c;
				dis[ed].second = st;
				if (k == n)
				{
					x = ed;
					flag = false;
				}
			}
		}
	}
	if (flag)
	{
		cout << "PATH" << '\n';
		for (auto& [a, _] : dis)
		{
			cout << a << ' ';
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			x = dis[x].second;
		}
		cout << "CYCLE" << '\n';
		vector<int>ans;
		int start = x;
		do
		{
			ans.push_back(x);
			x = dis[x].second;
		} while (start != x);
		int len = ans.size();
		cout << len << '\n';
		ans.push_back(start);
		for (int i = len; i >= 0; --i)
		{
			cout << ans[i] << ' ';
		}
	}
	return 0;
}