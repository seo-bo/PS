#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, temp = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;
		if (temp % 2 != i % 2)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}