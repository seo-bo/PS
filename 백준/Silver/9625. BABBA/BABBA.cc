#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	int a = 1, b = 0;
	for (int i = 1; i <= n; ++i)
	{
		int tempa = b;
		int tempb = a;
		a = tempa;
		b += tempb;
	}
	cout << a << ' ' << b << '\n';
	return 0;
}