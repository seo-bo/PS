#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll l = 0, w = 0, h = 0, n = 0;
	cin >> l >> w >> h >> n;
	vector<pll>v(n);
	for (auto& [i, j] : v)
	{
		cin >> i >> j;
		i = (1LL << i);
	}
	ll vv = 0, ans = 0;
	for (auto it = v.rbegin(); it != v.rend(); ++it)
	{
		vv <<= 3; // 2의 거듭제곱이니까
		ll pivot = min(it->second, (l / it->first) * (w / it->first) * (h / it->first) - vv);
		ans += pivot;
		vv += pivot;
	}
	cout << ((vv == l * w * h) ? ans : -1);
	return 0;
}