#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, h = 0;
	cin >> n >> h;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto& i : v)
	{
		h -= i;
		ans++;
		if (h <= 0)
		{
			cout << ans;
			return 0;
		}
	}
	if (h > 0)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}