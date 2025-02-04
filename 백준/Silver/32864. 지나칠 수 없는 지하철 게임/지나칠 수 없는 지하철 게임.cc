#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, cnt = 0;
	cin >> n >> cnt;
	for (int i = 2; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		if (a == 1)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	if (cnt % 2)
	{
		cout << "alsdkffhgk";
	}
	else
	{
		cout << "mnx";
	}
	return 0;
}