#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	function<void(int)> dfs = [&](int sum) ->void
		{
			if (v.size() <= 2)
			{
				ans = max(ans, sum);
				return;
			}
			for (int i = 1; i < v.size() - 1; ++i)
			{
				int temp = v[i - 1] * v[i + 1];
				int rm = v[i];
				v.erase(v.begin() + i);
				dfs(sum + temp);
				v.insert(v.begin() + i, rm);
			}
		};
	dfs(0);
	cout << ans;
	return 0;
}