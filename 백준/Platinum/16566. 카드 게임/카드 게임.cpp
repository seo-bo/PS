#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0, pivot = 0;
	cin >> n >> m >> k;
	vector<int>parent(n + 1);
	iota(parent.begin(), parent.end(), 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		parent[a] = a;
		pivot = max(pivot, a);
	}
	function<int(int)> find = [&](int root)
		{
			return (parent[root] == root) ? root : parent[root] = find(parent[root]);
		};
	while (k--)
	{
		int a = 0, ans = 0;
		cin >> a;
		ans = find(a + 1);
		cout << ans << '\n';
		if (ans == pivot)
		{
			continue;
		}
		parent[ans] = find(ans + 1);
	}
	return 0;
}