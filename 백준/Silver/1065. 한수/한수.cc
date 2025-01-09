#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>prefix(n + 1, 0);
	for (int i = 1; i <= min(n, 99); ++i)
	{
		prefix[i] = i;
	}
	for (int i = 100; i <= n; ++i)
	{
		string str = to_string(i);
		if ((str[2] - '0') - (str[1] - '0') == (str[1] - '0') - (str[0] - '0'))
		{
			prefix[i] = prefix[i - 1] + 1;
		}
		else
		{
			prefix[i] = prefix[i - 1];
		}
	}
	cout << prefix[n];
	return 0;
}