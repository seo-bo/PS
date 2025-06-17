#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	ll len = str.size(), ans = 0;
	reverse(str.begin(), str.end());
	for (auto& i : str)
	{
		ans += ((ll)(i - '0') - (ans % 10) + 10) % 10;
	}
	cout << ans + len;
	return 0;
}
