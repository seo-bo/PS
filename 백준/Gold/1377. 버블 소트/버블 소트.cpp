#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<pii>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, v[i].second - i);
	}
	cout << ans + 1;
	return 0;
}