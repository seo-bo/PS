#include <bits/stdc++.h>
#define NUM 1000000000000000000
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0;
	cin >> q;
	ll left = -NUM, right = NUM;
	ll ans = 0;
	bool check = false;
	for (int i = 1; i <= q; ++i)
	{
		ll a = 0;
		char b;
		cin >> a >> b;
		if (b == '^')
		{
			left = max(left, a + 1);
		}
		else
		{
			right = min(right, a - 1);
		}
		if (left == right && !check)
		{
			check = true;
			ans = i;
		}
		else if (left > right)
		{
			cout << "Paradox!" << '\n' << i;
			return 0;
		}
	}
	if (check)
	{
		cout << "I got it!" << '\n' << ans;
	}
	else
	{
		cout << "Hmm...";
	}
	return 0;
}