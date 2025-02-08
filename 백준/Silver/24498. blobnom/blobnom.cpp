#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	ll MAX = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		MAX = max(MAX, v[i]);
	}
	for (int i = 1; i < n - 1; ++i)
	{
		MAX = max(MAX, v[i] + min(v[i - 1], v[i + 1]));
	}
	cout << MAX;
}