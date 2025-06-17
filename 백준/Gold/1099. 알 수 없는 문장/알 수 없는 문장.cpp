#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string base;
	int n = 0;
	cin >> base >> n;
	int len = base.size();
	map<string, set<string>>mm;
	for (int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a;
		b = a;
		sort(a.begin(), a.end());
		mm[a].insert(b);
	}
	vector<int>dp(len + 2, -1);
	auto sv = [&](string a, string b)
		{
			int cnt = 0, siz = a.size();
			for (int i = 0; i < siz; ++i)
			{
				cnt += (a[i] != b[i]);
			}
			return cnt;
		};
	function<int(int)> dfs = [&](int idx)
		{
			if (idx == len + 1)
			{
				return 0;
			}
			if (dp[idx] != -1)
			{
				return dp[idx];
			}
			int res = 1e6;
			string temp;
			for (int i = idx; i <= len; ++i)
			{
				temp += base[i - 1];
				string tt = temp;
				sort(tt.begin(), tt.end());
				for (auto& j : mm[tt])
				{
					res = min(res, dfs(i + 1) + sv(temp, j));
				}
			}
			return dp[idx] = res;
		};
	int res = dfs(1);
	cout << ((res >= 1e6) ? -1 : res);
	return 0;
}