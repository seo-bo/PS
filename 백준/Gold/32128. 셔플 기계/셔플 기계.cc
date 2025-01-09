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
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<int>ans(n + 1, 0);
	iota(ans.begin(), ans.end(), 0);
	vector<vector<int>>change(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> change[i][j];
		}
	}
	auto mul = [&](vector<int>& a, vector<int>& b)
		{
			vector<int>res(n + 1, 0);
			for (int i = 1; i <= n; ++i)
			{
				res[i] = a[b[i]];
			}
			return res;
		};
	auto power = [&](vector<int>& base, ll exp)
		{
			vector<int>res(n + 1, 0);
			iota(res.begin(), res.end(), 0);
			vector<int>cur = base;
			while (exp)
			{
				if (exp & 1)
				{
					res = mul(res, cur);
				}
				cur = mul(cur, cur);
				exp >>= 1;
			}
			return res;
		};
	for (int i = 0; i < k; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		vector<int>temp(n + 1, 0);
		vector<int> pivot = power(change[a], b);
		for (int i = 1; i <= n; ++i)
		{
			temp[pivot[i]] = ans[i];
		}
		ans = temp;		
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}