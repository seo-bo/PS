#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll ans = 0, cnt = 2;
	sort(v.begin(), v.end(), [&](const int& a, const int& b)
		{
			return a > b;
		});
	for (auto& i : v)
	{
		ans = max(ans,i + cnt);
		cnt++;
	}
	cout << ans;
	return 0;
}