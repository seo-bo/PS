#include <bits/stdc++.h>
using namespace std;
typedef long double lb;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	ll ans = 0;
	while (n--)
	{
		int num = 0;
		cin >> num;
		ans += num;
		if (ans <= 0 && n)
		{
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
	return 0;
}