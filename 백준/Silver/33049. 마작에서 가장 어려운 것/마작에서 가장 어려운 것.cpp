#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	ll sum = a + b + c, mini = (a + 2) / 3, maxi = sum / 3, ans1 = -1, ans2 = -1;
	for (int i = mini; i <= maxi; ++i)
	{
		ll pivot = i * 3;
		ll ov = sum - pivot;
		if (ov < 0)
		{
			break;
		}
		if (ov % 4)
		{
			continue;
		}
		ll tt = ov / 4;
		if (pivot < a || ov < b)
		{
			continue;
		}
		ans1 = i, ans2 = tt;
		break;
	}
	if (ans1 == -1)
	{
		cout << -1;
	}
	else
	{
		cout << ans1 << ' ' << ans2;
	}
	return 0;
}