#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int result[10] = { 0, };
int visited[10] = { 0, };
int n = 0, m = 0;

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
	int lastpick = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] && v[i] != lastpick)
		{
			visited[i] = 1;
			result[idx] = v[i];
			dfs(idx + 1, i);
			visited[i] = 0;
			lastpick = v[i];
		}

	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	dfs(0, 0);
}
