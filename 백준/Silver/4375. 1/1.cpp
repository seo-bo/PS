#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	while (cin >> n)
	{
		int temp = 1;
		int ans = 1;
		while (1)
		{
			if (!(temp % n))
			{
				break;
			}
			ans++;
			temp = (temp * 10 + 1) %n;
		}
		cout << ans << '\n';
	}
	return 0;
}