#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
int result[9] = { 0, };

void dfs(int idx, int start)
{
	if (idx == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; ++i)
	{
		result[idx] = i;
		dfs(idx + 1, i);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	dfs(0, 1);
	return 0;
}