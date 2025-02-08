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
	ll n = 0, k = 0, s = 0, ans = 0;
	cin >> n >> k >> s;
	deque<pll>left, right;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a < s)
		{
			left.push_back(make_pair(llabs(s - a), b));
		}
		else if (a > s)
		{
			right.push_back(make_pair(llabs(s - a), b));
		}
	}
	sort(left.begin(), left.end(), greater<pll>());
	sort(right.begin(), right.end(), greater<pll>());
	while (!left.empty())
	{
		ll capa = k;
		ans += left.front().first * 2;
		while (!left.empty())
		{
			if (capa >= left.front().second)
			{
				capa -= left.front().second;
				left.pop_front();
			}
			else
			{
				left.front().second -= capa;
				break;
			}
		}
	}
	while (!right.empty())
	{
		ll capa = k;
		ans += right.front().first * 2;
		while (!right.empty())
		{
			if (capa >= right.front().second)
			{
				capa -= right.front().second;
				right.pop_front();
			}
			else
			{
				right.front().second -= capa;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}