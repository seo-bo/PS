#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>>v(3, { 0,0 });

void ccw()
{
	ll temp = v[0].first * v[1].second + v[1].first * v[2].second + v[2].first * v[0].second;
	temp -= v[0].second * v[1].first + v[1].second * v[2].first + v[2].second * v[0].first;
	if (temp > 0)
	{
		cout << 1;
	}
	else if (!temp)
	{
		cout << 0;
	}
	else
	{
		cout << -1;
	}
	exit(0);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	ccw();
	return 0;
}