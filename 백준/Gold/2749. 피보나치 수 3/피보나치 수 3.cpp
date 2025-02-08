#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	n--;
	vector<vector<ll>>base = { {1,1},{1,0} };
	auto mul = [&](vector<vector<ll>>a, vector<vector<ll>>b)
		{
			vector<vector<ll>>c(2, vector<ll>(2, 0));
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					for (int k = 0; k < 2; ++k)
					{
						c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
					}
				}
			}
			return c;
		};
	vector<vector<ll>>ans = { {1,0},{0,1} };
	while (n > 0)
	{
		if (n % 2)
		{
			ans = mul(ans, base);
		}
		base = mul(base, base);
		n /= 2;
	}
	cout << ans[0][0];
	return 0;
}