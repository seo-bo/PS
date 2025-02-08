#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<bool>visited(2000002, false);
	function<void(int, int)> dfs = [&](int depth, int sum) ->void
		{
			if (depth == n)
			{
				visited[sum] = true;
				return;
			}
			dfs(depth + 1, sum + v[depth]);
			dfs(depth + 1, sum);
		};
	dfs(0, 0);
	int idx = 1;
	while (visited[idx])
	{
		idx++;
	}
	cout << idx;
	return 0;
}