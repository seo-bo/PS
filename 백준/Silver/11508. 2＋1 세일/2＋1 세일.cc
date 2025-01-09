#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll sum = 0;
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < n; ++i)
	{
		if (i % 3 != 2)
		{
			sum += v[i];
		}
	}
	cout << sum;
	return 0;
}