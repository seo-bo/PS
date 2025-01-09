#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<vector<int>>graph(n);
	vector<bool>visited(n, false);
	visited[0] = true;
	vector<ll>siz(n, 0), v(n - 1, 0);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[--a].push_back(--b);
		graph[b].push_back(a);
	}
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	function<int(int)> dfs = [&](int node) ->int
		{
			siz[node] = 1;
			for (auto& i : graph[node])
			{
				if (!siz[i])
				{
					visited[i] = true;
					siz[node] += dfs(i);
				}
			}
			return siz[node];
		};
	dfs(0);
	for (int i = 0; i < n; ++i)
	{
		// 경로의 갯수는 서브트리 정점 갯수 * (모든 정점 - 서브트리 정점)
		siz[i] = siz[i] * (n - siz[i]);
	}
	sort(siz.begin(), siz.end(), greater<ll>());
	ll ans = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		ans = (ans + siz[i] * v[i]) % MOD;
	}
	cout << ans;
	return 0;
}