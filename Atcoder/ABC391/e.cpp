#include <bits/stdc++.h>
#define P 15
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>three(P, 1);
	for (ll i = 1; i < P - 1; ++i)
	{
		three[i] = three[i - 1] * 3LL;
	}
	ll n = 0;
	string str;
	cin >> n >> str;
	vector<vector<ll>>BIT(P);
	for (ll i = 0; i < three[n]; ++i)
	{
		BIT[n].push_back((str[i] == '1'));
	}
	for (ll i = n - 1; i >= 0; --i)
	{
		for (ll j = 0; j < three[i]; ++j)
		{
			ll sum = 0;
			sum += BIT[i + 1][3 * j] + BIT[i + 1][3 * j + 1] + BIT[i + 1][3 * j + 2];
			BIT[i].push_back((sum >= 2));
		}
	}
	vector<vector<ll>>dp1(P, vector<ll>(1600000, LLONG_MAX));
	vector<vector<ll>>dp2(P, vector<ll>(1600000, LLONG_MAX));
	for (ll i = 0; i < three[n]; ++i)
	{
		dp1[n][i] = 0;
		dp2[n][i] = 1;
		if (str[i] != '0')
		{
			dp1[n][i] ^= 1;
			dp2[n][i] ^= 1;
		}
	}
	for (ll i = n - 1; i >= 0; --i)
	{
		for (ll j = 0; j < three[i]; ++j)
		{
			ll a = 3 * j, b = 3 * j + 1, c = 3 * j + 2;
			vector<ll>z = { dp1[i + 1][a], dp1[i + 1][b] ,dp1[i + 1][c] };
			vector<ll>o = { dp2[i + 1][a], dp2[i + 1][b] ,dp2[i + 1][c] };
			dp1[i][j] = min(dp1[i][j], z[0] + z[1] + z[2]);
			dp1[i][j] = min(dp1[i][j], o[0] + z[1] + z[2]);
			dp1[i][j] = min(dp1[i][j], z[0] + o[1] + z[2]);
			dp1[i][j] = min(dp1[i][j], z[0] + z[1] + o[2]);
			dp2[i][j] = min(dp2[i][j], o[0] + o[1] + o[2]);
			dp2[i][j] = min(dp2[i][j], z[0] + o[1] + o[2]);
			dp2[i][j] = min(dp2[i][j], o[0] + z[1] + o[2]);
			dp2[i][j] = min(dp2[i][j], o[0] + o[1] + z[2]);
		}
	}
	if (BIT[0][0])
	{
		cout << dp1[0][0];
	}
	else
	{
		cout << dp2[0][0];
	}
	return 0;
}
