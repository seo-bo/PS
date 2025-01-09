#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	bool a1 = (a == b + c) || (b == a + c) || (c == a + b);
	bool a2 = (a == b) || (b == c);
	cout << ((a1 || a2) ? "Yes" : "No");
	return 0;
}
