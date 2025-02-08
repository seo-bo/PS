#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

lb L = 0, R = 0, N = 0;
vector<pair<lb, lb>>v;

void change(int color)
{
	if (v[color].first == v[color].second)
	{
		return;
	}
	lb avg = (v[color].first + v[color].second) / 2;
	lb temp = avg + fabs(avg - L);
	L = avg;
	if (temp > R)
	{
		R = temp;
	}
	for (int i = color + 1; i < 3; ++i)
	{
		v[i].first = avg + fabs(avg - v[i].first);
		v[i].second = avg + fabs(avg - v[i].second);
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	R = N;
	v.resize(3);
	for (int i = 0; i < 3; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < 3; ++i)
	{
		change(i);
	}
	cout << fixed << setprecision(1) << floor((R - L) * 10) / 10;
	return 0;
}