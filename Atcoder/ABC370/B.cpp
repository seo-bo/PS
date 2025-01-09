#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll>pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> v[i][j];
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (ans >= i)
		{
			ans = v[ans - 1][i - 1];
		}
		else
		{
			ans = v[i - 1][ans - 1];
		}
	}
	cout << ans;
	return 0;
}
