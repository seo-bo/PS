#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, l = 0;
	cin >> n >> l;
	vector<ll>A(n), B(n);
	for (auto& i : A)
	{
		cin >> i;
	}
	for (auto& i : B)
	{
		cin >> i;
	}
	ll pivot = 1;
	for (int i = 0; i < n; ++i)
	{
		if (B[i])
		{
			ll GCD = gcd(pivot, A[i]);
			ll temp = pivot / GCD;
			if (temp > l / A[i])
			{
				cout << -1;
				return 0;
			}
			pivot = temp * A[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (!B[i])
		{
			if (A[i] == 1 || !(pivot % A[i]))
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << pivot;
	return 0;
}