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
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0, k = 0;
		cin >> n >> m >> k;
		vector<int>ans;
		for (int i = n; i > m; --i)
		{
			ans.push_back(i);
		}
		for (int i = 1; i <= m; ++i)
		{
			ans.push_back(i);
		}
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
