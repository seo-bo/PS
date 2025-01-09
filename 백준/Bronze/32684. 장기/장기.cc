#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, lb> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>v = { {2,13.0},{2,7.0},{2,5.0},{2,3.0},{2,3.0},{5,2.0} };
	lb a = 0, b = 0;
	for (int i = 0; i < 6; ++i)
	{
		ll temp = 0;
		cin >> temp;
		a += v[i].second * temp;
	}
	for (int i = 0; i < 6; ++i)
	{
		ll temp = 0;
		cin >> temp;
		b += v[i].second * temp;
	}
	b += 1.5;
	if (a > b)
	{
		cout << "cocjr0208";
	}
	else
	{
		cout << "ekwoo";
	}
	return 0;
}