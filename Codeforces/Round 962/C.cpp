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
		int n = 0, q = 0;
		cin >> n >> q;
		string a, b;
		cin >> a >> b;
		vector<vector<int>>A(n + 1, vector<int>(27, 0)), B(n + 1, vector<int>(27, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				A[i + 1][j] = A[i][j];
				B[i + 1][j] = B[i][j];
			}
			A[i + 1][a[i] - 'a']++;
			B[i + 1][b[i] - 'a']++;
		}
		while (q--)
		{
			int l = 0, r = 0;
			ll ans = 0;
			cin >> l >> r;
			l--; r--;
			vector<int>fa(27, 0), fb(27, 0);
			for (int i = 0; i < 26; ++i)
			{

				fa[i] = A[r + 1][i] - A[l][i];
				fb[i] = B[r + 1][i] - B[l][i];
			}
			for (int i = 0; i < 26; ++i)
			{
				if (fa[i] < fb[i])
				{
					ans += (fb[i] - fa[i]);
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
