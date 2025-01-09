#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	cout << m - gcd(n, m);
	return 0;
}