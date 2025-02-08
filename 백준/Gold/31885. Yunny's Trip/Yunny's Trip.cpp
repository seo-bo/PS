#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, k = 0, ans = LLONG_MAX;
	cin >> n >> k;
	set<pll>item;
	vector<vector<ll>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		item.insert(make_pair(a, b));
	}
	ll dx = 0, dy = 0;
	cin >> dx >> dy;
	ans = min(ans, llabs(dx) + llabs(dy));
	for (auto& [x, y] : item)
	{
		ans = min(ans, llabs(dx - x) + llabs(dy - y) + 2);
		if (item.find(make_pair(dx - x, dy - y)) != item.end())
		{
			ans = min(ans, 4LL);
		}
		for (int i = 0; i < 4; ++i)
		{
			ll nx = x + dir[i][0];
			ll ny = y + dir[i][1];
			if (item.find(make_pair(dx - nx, dy - ny)) != item.end())
			{
				ans = min(ans, 5LL);
			}
		}
	}
	cout << ((ans > k) ? -1 : ans);
	return 0;
}