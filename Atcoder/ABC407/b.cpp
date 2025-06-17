#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int x = 0, y = 0;
	cin >> x >> y;
	int pivot = 36, ans = 0;
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			if (i + j >= x || abs(i - j) >= y)
			{
				ans++;
			}
		}
	}
	cout << fixed << setprecision(15) << (double)ans / pivot;
	return 0;
}
