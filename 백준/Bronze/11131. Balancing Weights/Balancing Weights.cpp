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
		int n = 0, ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int temp = 0;
			cin >> temp;
			ans += temp;
		}
		if (ans == 0)
		{
			cout << "Equilibrium\n";
		}
		else if (ans > 0)
		{
			cout << "Right\n";
		}
		else
		{
			cout << "Left\n";
		}
	}
	return 0;
}