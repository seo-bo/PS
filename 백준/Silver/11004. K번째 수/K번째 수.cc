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
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[k - 1];
	return 0;
}