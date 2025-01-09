#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, sum = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
			sum += i;
		}
		if (sum % n)
		{
			cout << "NO" << '\n';
			continue;
		}
		ll pivot = sum / n;
		for (int i = n - 1; i >= 2; --i)
		{
			v[i - 2] += v[i] - pivot;
			v[i] = pivot;
		}
		if (v[0] == pivot)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "No" << '\n';
		}
	}
}
