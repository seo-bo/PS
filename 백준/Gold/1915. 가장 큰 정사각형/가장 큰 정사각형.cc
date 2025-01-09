#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; ++j)
		{
			v[i][j] = str[j - 1] - '0';
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (v[i][j])
			{
				v[i][j] = min({ v[i - 1][j], v[i][j - 1], v[i - 1][j - 1] }) + 1;
				ans = max(v[i][j], ans);
			}
		}
	}
	cout << ans * ans;
	return 0;
}