#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll k = 0, n = 0;
		cin >> k >> n;
		vector<vector<ll>>v(4, vector<ll>(n, 0));
		vector<ll>A, B;
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				cin >> j;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				A.push_back(v[0][i] + v[1][j]);
				B.push_back(v[2][i] + v[3][j]);
			}
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		ll ans = INT_MAX;
		for (auto& i : A)
		{
			auto it = lower_bound(B.begin(), B.end(), k - i);
			if (it != B.end())
			{
				ll pivot = *it + i;
				ll p1 = llabs(k - ans), p2 = llabs(k - pivot);
				if (p2 < p1 || (p2 == p1 && pivot < ans))
				{
					ans = pivot;
				}
			}
			if (it != B.begin())
			{
				--it;
				ll pivot = *it + i;
				ll p1 = llabs(k - ans), p2 = llabs(k - pivot);
				if (p2 < p1 || (p2 == p1 && pivot < ans))
				{
					ans = pivot;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}