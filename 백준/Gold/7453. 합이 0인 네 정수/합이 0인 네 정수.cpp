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
	vector<int>a(n);
	vector<int>b(n);
	vector<int>c(n);
	vector<int>d(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<int>left(n*n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			left[cnt++] = a[i] + b[j];
		}
	}
	sort(left.begin(), left.end());
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int target = -(c[i] + d[j]);
			ans += upper_bound(left.begin(), left.end(), target) - lower_bound(left.begin(), left.end(), target);
		}
	}
	cout << ans;
	return 0;
}