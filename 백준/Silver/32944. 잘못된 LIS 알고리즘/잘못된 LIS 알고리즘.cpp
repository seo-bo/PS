#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	if (m == n)
	{
		cout << -1;
		return 0;
	}
	vector<int>ans;
	for (int i = 1; i <= k - 1; ++i)
	{
		ans.push_back(i);
	}
	ans.push_back(n);
	for (int i = k; i <= m - 1; ++i)
	{
		ans.push_back(i);
	}
	for (int i = n - 1; i >= m; --i)
	{
		ans.push_back(i);
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}