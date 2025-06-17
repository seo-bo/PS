#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<ll>prefix(n + 3), suffix(n + 3);
	prefix[1] = v[1], suffix[n] = v[n];
	for (int i = 2; i <= n; ++i)
	{
		prefix[i] = max(v[i], prefix[i - 1] + v[i]);
	}
	for (int i = n - 1; i >= 1; --i)
	{
		suffix[i] = max(v[i], suffix[i + 1] + v[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << prefix[i] + suffix[i] - v[i] << ' ';
	}
	return 0;
}