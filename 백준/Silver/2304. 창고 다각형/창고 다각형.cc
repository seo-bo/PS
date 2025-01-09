#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

struct c
{
	int x, y, idx;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, maxi = 0, idx = 0, ans = 0;
	cin >> n;
	vector<c> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].x >> v[i].y;
		v[i].idx = i;
		if (maxi < v[i].y)
		{
			maxi = v[i].y;
			idx = v[i].idx;
		}
	}
	sort(v.begin(), v.end(), [&](const c& a, const c& b)
		{
			return a.x < b.x;
		});
	int pre = 0, pidx = 0;
	for (int i = 0; i < n; ++i)
	{
		if (pre <= v[i].y)
		{
			ans += (v[i].x - pidx) * pre;
			if (v[i].idx == idx)
			{
				break;
			}
			pre = v[i].y; pidx = v[i].x;
		}
	}
	pre = 0, pidx = v[n - 1].x;
	for (int i = n - 1; i >= 0; --i)
	{
		if (pre <= v[i].y)
		{
			ans += (pidx - v[i].x) * pre;
			if (v[i].idx == idx)
			{
				break;
			}
			pre = v[i].y; pidx = v[i].x;
		}
	}
	cout << ans + maxi;
	return 0;
}