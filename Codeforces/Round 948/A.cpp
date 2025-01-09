#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		if (n >= m && !((n - m) % 2))
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}
