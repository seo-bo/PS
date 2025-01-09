#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>prefix(2 * n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		cin >> temp;
		prefix[n + i] = temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	for (int i = n + 1; i <= 2 * n; ++i)
	{
		prefix[i] = prefix[i] + prefix[i - 1];
	}
	int sum = 0;
	for (int i = k; i <= 2 * n + 1; ++i)
	{
		sum = max(sum, prefix[i] - prefix[i - k]);
	}
	cout << sum;
	return 0;
}