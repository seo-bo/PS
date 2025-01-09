#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int ary[4] = { 0, };

int main(void)
{
	bool check = false;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a = 0, b = 0;
	cin >> a >> b;
	ary[a] = 1;
	ary[b] = 1;
	if (a == b)
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= 3; ++i)
	{
		if (!ary[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
