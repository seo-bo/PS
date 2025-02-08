#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<int>v;
int result[9] = { 0, };
int visited[9] = { 0, };

void dfs(int idx, int start)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			result[idx] = v[i];
			dfs(idx + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	dfs(0, 1);
	return 0;
}