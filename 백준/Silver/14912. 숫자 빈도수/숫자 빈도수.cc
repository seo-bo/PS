#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, ans = 0;
	char d;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)
	{
		string str = to_string(i);
		for (auto& j : str)
		{
			if (j == d)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}