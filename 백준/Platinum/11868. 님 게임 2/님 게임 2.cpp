#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll pivot = 0;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		pivot ^= temp;
	}
	if (!pivot)
	{
		cout << "cubelover";
	}
	else
	{
		cout << "koosaga";
	}
	return 0;
}