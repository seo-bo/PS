#include <bits/stdc++.h>
#define P 500
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	set<pll>s;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		s.insert(make_pair(a, b));
	}
	string str;
	cin >> str;
	int x = 0, y = 0;
	for (auto& i : str)
	{
		int nx = x, ny = y;
		if (i == 'U')
		{
			ny++;
		}
		else if (i == 'D')
		{
			ny--;
		}
		else if (i == 'R')
		{
			nx++;
		}
		else if (i == 'L')
		{
			nx--;
		}
		if (s.find(make_pair(nx, ny)) == s.end())
		{
			x = nx;
			y = ny;
		}
	}
	cout << x << ' ' << y << '\n';
	return 0;
}