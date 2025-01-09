#include <bits/stdc++.h>
#define MOD 1000
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct mat
{
	int v[5][5];
};
mat A, result;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> A.v[i][j];
		}
	}
	auto mul = [&](const mat& a, const mat& b)
		{
			mat temp;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					temp.v[i][j] = 0;
					for (int k = 0; k < n; ++k)
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
	for (int i = 0; i < n; ++i)
	{
		result.v[i][i] = 1;
	}
	while (k)
	{
		if (k & 1)
		{
			result = mul(result, A);
		}
		A = mul(A, A);
		k /= 2;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << result.v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}