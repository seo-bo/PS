#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, g = 0, pivot = 0;
	cin >> n >> g;
	vector<vector<bool>>graph(n, vector<bool>(n, false));
	vector<vector<int>>v(n, vector<int>(n, 0));
	for (int i = 0; i < g; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a--, b--;
		graph[a][b] = graph[b][a] = true;
	}
	cin >> pivot;
	vector<vector<bool>>h(n, vector<bool>(n, false));
	for (int i = 0; i < pivot; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a--, b--;
		h[a][b] = h[b][a] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			cin >> v[i][j];
			v[j][i] = v[i][j];
		}
	}
	vector<int>per(n);
	iota(per.begin(), per.end(), 0);
	int ans = INT_MAX;
	do
	{
		int cur = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (graph[per[i]][per[j]] != h[i][j])
				{
					cur += v[i][j];
				}
			}
		}
		ans = min(ans, cur);
	} while (next_permutation(per.begin(), per.end()));
	cout << ans;
	return 0;
}
