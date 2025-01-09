#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<ll>arrow(6);
	vector<ll>target(6);
	for (auto& i : arrow)
	{
		cin >> i;
	}
	for (auto& i : target)
	{
		cin >> i;
	}
	ll x1 = max(arrow[0], target[0]), x2 = min(arrow[1], target[1]);
	ll y1 = max(arrow[2], target[2]), y2 = min(arrow[3], target[3]);
	if (x1 >= x2 || y1 >= y2)
	{
		cout << -1;
		return 0;
	}
	ll st = (arrow[4] - target[5]) + 1;
	ll ed = (arrow[5] - target[4]) - 1;
	ll ans = max(st, 0LL);
	if (ans <= ed)
	{
		cout << ans;
	}
	else
	{
		cout << -1;
	}
	return 0;
}