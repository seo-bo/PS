#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	ll sum = 0;
	for (auto& i : v)
	{
		cin >> i;
		sum += i;
	}
	for (auto& i : v)
	{
		sum = max(sum, -i);
	}
	cout << sum;
	return 0;
}