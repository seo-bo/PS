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
	vector<bool>visited(1001, false);
	int st = 0, ed = 0, n = 0, ans = 0;
	cin >> st >> ed >> n;
	ans = abs(st - ed);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		ans = min(ans, abs(temp - ed) + 1);
	}
	cout << ans;
	return 0;
}