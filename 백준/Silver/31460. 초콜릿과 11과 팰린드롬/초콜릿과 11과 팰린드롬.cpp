#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		if (n == 1)
		{
			cout << 0 << "\n";
			continue;
		}
		cout << 1;
		for (int i = 0; i < n - 2; ++i)
		{
			cout << 2;
		}
		cout << 1 << "\n";
	}
	return 0;
}