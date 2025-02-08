#include <bits/stdc++.h>
using namespace std;

vector<int>v;
pair<int, int>lastpick = { 0,0 };
int result[10] = { 0, };
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
	for (int i = start; i < n; i++)
	{
		if (v[i] != lastpick.second || idx != lastpick.first)
		{
			result[idx] = v[i];
			dfs(idx + 1, i);
			lastpick = make_pair(idx, v[i]);
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
