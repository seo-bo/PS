#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct mat
{
	ll v[2][2];
};
mat A = { 1,1,1,0 }, result = { 1,0,0,1 };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll k = 0;
	cin >> k;
	k--;
	auto mul = [&](const mat& a, const mat& b)
		{
			mat temp;
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					temp.v[i][j] = 0;
					for (int k = 0; k < 2; ++k)
					{
						temp.v[i][j] = (temp.v[i][j] + a.v[i][k] * b.v[k][j]) % MOD;
					}
					if (temp.v[i][j] < 0)
					{
						temp.v[i][j] += MOD;
					}
				}
			}
			return temp;
		};
	while (k)
	{
		if (k & 1)
		{
			result = mul(result, A);
		}
		A = mul(A, A);
		k >>= 1;
	}
	cout << result.v[0][0];
	return 0;
}