#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pii>v(3);
	vector<int>tr;
	for (auto& i : v)
	{
		cin >> i.first >> i.second;
	}
	auto sv = [&](pii a, pii b) 
		{
			int dx = a.first - b.first;
			int dy = a.second - b.second;
			return dx * dx + dy * dy;
		};
	int d1 = sv(v[0], v[1]);
	int d2 = sv(v[1], v[2]);
	int d3 = sv(v[2], v[0]);
	if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
