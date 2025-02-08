#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, result = 0, idx = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; ++i)
	{
		if (str.substr(0, n - idx) == str.substr(idx, n - idx))
		{
			idx = 0;
			result++;
		}
		idx++;
	}
	cout << result;
	return 0;
}