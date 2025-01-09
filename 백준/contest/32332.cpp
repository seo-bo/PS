#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<ll, ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	bool flag = false;
	ll y1 = 0, m1 = 0, d1 = 0, y2 = 0, m2 = 0, d2 = 0;
	lb s1 = 0, s2 = 0, e1 = 0, e2 = 0;
	cin >> y1 >> m1 >> d1 >> s1 >> s2;
	cin >> y2 >> m2 >> d2 >> e1 >> e2;
	ll pivot1 = y1 * 360 + (m1 - 1) * 30 + d1;
	ll pivot2 = y2 * 360 + (m2 - 1) * 30 + d2;
	ll diff = llabs(pivot1 - pivot2);
	ll temp = diff / 360;
	if (pivot2 > pivot1)
	{
		y1 -= temp;
		flag = true;
	}
	else
	{
		y1 += temp;
	}
	diff %= 360;
	if (flag)
	{
		while (diff--)
		{
			d1--;
			if (d1 == 0)
			{
				m1--;
				d1 = 30;
			}
			if (m1 == 0)
			{
				y1--;
				m1 = 12;
			}
		}
	}
	else
	{
		while (diff--)
		{
			d1++;
			if (d1 == 31)
			{
				m1++;
				d1 = 1;
			}
			if (m1 == 13)
			{
				y1++;
				m1 = 1;
			}
		}
	}
	s1 = s1 + (s1 - e1);
	s2 = s2 + (s2 - e2);
	cout << y1 << ' ' << m1 << ' ' << d1 << ' ';
	cout << fixed << setprecision(3) << s1 << ' ' << s2;
	return 0;
}
