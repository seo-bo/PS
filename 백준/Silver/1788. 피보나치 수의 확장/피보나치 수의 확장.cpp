#include <bits/stdc++.h>
#define p 1000000
#define MOD 1000000000
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(2000500, 0);
	v[1 + p] = v[-1 + p] = 1;
	if (n > 0)
	{
		for (int i = 2 + p; i <= n + p; ++i)
		{
			v[i] = (v[i - 1] + v[i - 2]) % MOD;
		}
	}
	else if (n < 0)
	{
		for (int i = p - 2; i >= n + p; --i)
		{
			v[i] = (v[i + 2] - v[i + 1]) % MOD;
		}
	}
	if (v[p + n] > 0)
	{
		cout << 1 << '\n';
	}
	else if (v[p + n] < 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
	cout << abs(v[p + n]);
	return 0;
}