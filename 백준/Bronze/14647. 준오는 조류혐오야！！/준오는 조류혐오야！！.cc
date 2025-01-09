#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, t = 0;
	cin >> n >> m;
	vector<vector<string>>v(n, vector<string>(m));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
			for (auto& k : j)
			{
				if (k == '9')
				{
					t++;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < m; ++j)
		{
			for (auto& k : v[i][j])
			{
				if (k == '9')
				{
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	for (int i = 0; i < m; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			for (auto& k : v[j][i])
			{
				if (k == '9')
				{
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << t - ans;
	return 0;
}