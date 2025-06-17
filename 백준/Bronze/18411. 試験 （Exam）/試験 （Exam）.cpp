#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << max({ a + b,a + c,b + c });
	return 0;
}