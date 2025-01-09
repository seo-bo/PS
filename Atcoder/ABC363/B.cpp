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
	int n = 0, t = 0, p = 0;
	cin >> n >> t >> p;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end(), greater());
	int target = INT_MAX;
	for (int i = 0; i < p; ++i)
	{
		target = min(target, v[i]);
	}
	if (target >= t)
	{
		cout << 0;
	}
	else
	{
		cout << t - target;
	}
	return 0;
}
