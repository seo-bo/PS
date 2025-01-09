#include <bits/stdc++.h>
#define MOD 1000000007
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
	vector<ll>v(117);
	v[1] = v[2] = v[3] = 1;
	for (int i = 4; i <= n; ++i)
	{
		v[i] = v[i - 1] + v[i - 3];
	}
	cout << v[n];
	return 0;
}