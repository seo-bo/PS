#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (400 % n)
	{
		cout << -1;
	}
	else
	{
		cout << 400 / n;
	}
	return 0;
}
