#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<string, int>mm;
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		if (++mm[str] == 5)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}