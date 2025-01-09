#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double lb;

lb dp[10001] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<lb>v(num + 1);
	for (int i = 1; i <= num; ++i)
	{
		cin >> v[i];
	}
	lb result = dp[1] = v[1];
	for (int i = 2; i <= num; ++i)
	{
		dp[i] = max(dp[i - 1] * v[i], v[i]);
		result = max(result, dp[i]);
	}
	cout << fixed << setprecision(3) << result * 1000 / 1000;
	return 0;
}