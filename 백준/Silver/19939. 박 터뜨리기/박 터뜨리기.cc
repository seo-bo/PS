#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	int sum = k * (k + 1) / 2;
	if (n < sum)
	{
		cout << -1;
		return 0;
	}
	n -= sum;
	n % k ? cout << k : cout << k - 1;
	return 0;
}