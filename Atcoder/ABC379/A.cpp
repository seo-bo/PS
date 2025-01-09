#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int a = n / 100;
	int b = (n / 10) % 10;
	int c = n % 10;
	cout << b * 100 + c * 10 + a << ' ' << c * 100 + a * 10 + b;
	return 0;
}
