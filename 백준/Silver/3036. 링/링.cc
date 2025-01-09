#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 1; i < n; ++i)
	{
		int GCD = gcd(v[0], v[i]);
		cout << v[0] / GCD << "/" << v[i] / GCD << "\n";
	}
	return 0;
}