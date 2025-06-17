#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	double a = 0;
	cin >> a;
	if (a >= 38.0)
	{
		cout << 1;
		return 0;
	}
	if (a >= 37.5)
	{
		cout << 2;
		return 0;
	}
	cout << 3;
	return 0;
}
