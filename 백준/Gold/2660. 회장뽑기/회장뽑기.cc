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
	int n = 0, pivot = INT_MAX;
	cin >> n;
	vector<vector<int>>graph(n + 1);
	vector<int>ans(n + 1, 1);
	while (1)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == -1 && b == -1)
		{
			break;
		}
		else if (a == b)
		{
			continue;
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	auto bfs = [&](int st)
		{
			int depth = 0;
			ll mask = (1LL << st);
			queue<pii>q;
			q.push(make_pair(0, st));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (auto& i : graph[b])
				{
					if (!(mask & (1LL << i)))
					{
						mask |= (1LL << i);
						q.push(make_pair(a + 1, i));
						depth = max(a + 1, depth);
					}
				}
			}
			ans[st] = max(ans[st], depth);
			pivot = min(pivot, ans[st]);
		};
	for (int i = 1; i <= n; ++i)
	{
		bfs(i);
	}
	vector<int>aa;
	for (int i = 1; i <= n; ++i)
	{
		if (ans[i] == pivot)
		{
			aa.push_back(i);
		}
	}
	cout << pivot << ' ' << aa.size() << '\n';
	for (auto& i : aa)
	{
		cout << i << ' ';
	}
	return 0;
}