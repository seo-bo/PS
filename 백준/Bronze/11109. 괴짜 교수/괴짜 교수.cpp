#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		ll pa = a + d * b;
		ll pb = b * c;
		if (pa > pb)
		{
			cout << "do not parallelize\n";
		}
		else if (pa < pb)
		{
			cout << "parallelize\n";
		}
		else
		{
			cout << "does not matter\n";
		}
	}
	return 0;
}