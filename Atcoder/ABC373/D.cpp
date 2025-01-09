#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<pll>>graph(n + 1);
	vector<ll>ans(n + 1, 0);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, -c));
	}
	vector<bool>visited(n + 1, false);
	queue<ll>q;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ans[i] = 0;
			q.push(i);
			visited[i] = true;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (auto& [z, j] : graph[cur])
				{
					if (!visited[z])
					{
						ans[z] = ans[cur] + j;
						visited[z] = true;
						q.push(z);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
