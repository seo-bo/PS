#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) //큰거 2개 or 작은거 2개 or 안합치기
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	ll sum = 0;
	vector<ll>maxi(2, LLONG_MIN), mini(2, LLONG_MAX);
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
		if (i > maxi[0])
		{
			maxi[1] = maxi[0];
			maxi[0] = i;
		}
		else if (i > maxi[1])
		{
			maxi[1] = i;
		}
		if (i < mini[0])
		{
			mini[1] = mini[0];
			mini[0] = i;
		}
		else if (i < mini[1])
		{
			mini[1] = i;
		}
	}
	ll pivot = max(2 * maxi[0] * maxi[1] - maxi[0] - maxi[1], 2 * mini[0] * mini[1] - mini[0] - mini[1]);
	if (pivot > 0)
	{
		cout << sum + pivot;
	}
	else
	{
		cout << sum;
	}
	return 0;
}