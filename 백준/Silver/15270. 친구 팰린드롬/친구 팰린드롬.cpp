#include <bits/stdc++.h>
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
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<pii>graph(m);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[i] = make_pair(a, b);
	}
	function<void(int, int, int)> dfs = [&](int depth, int sum, int mask)
		{
			if (depth == m)
			{
				ans = max(ans, sum);
				return;
			}
			auto [a, b] = graph[depth];
			if (!(mask & (1 << a)) && !(mask & (1 << b)))
			{
				dfs(depth + 1, sum + 1, (mask | (1 << a) | (1 << b)));
			}
			dfs(depth + 1, sum, mask);
		};
	dfs(0, 0, 0);
	ans *= 2;
	cout << (ans < n ? ans + 1 : ans);
	return 0;
}