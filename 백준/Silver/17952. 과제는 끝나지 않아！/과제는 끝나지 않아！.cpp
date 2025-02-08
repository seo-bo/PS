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
	int n = 0, ans = 0;
	cin >> n;
	deque<pii>dq;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a;
		if (a)
		{
			cin >> b >> c;
			dq.push_back(make_pair(b, c - 1));
		}
		else
		{
			if (!dq.empty())
			{
				dq.back().second -= 1;
			}
		}
		if (!dq.empty() && dq.back().second == 0)
		{
			ans += dq.back().first;
			dq.pop_back();
		}
	}
	cout << ans;
	return 0;
}