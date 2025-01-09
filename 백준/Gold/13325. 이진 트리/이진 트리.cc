#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[(1 << 21)] = { 0, };
ll dp[(1 << 21)] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	ll result = 0;
	cin >> num;
	for (int i = 2; i <= (1 << (num + 1)) - 1; ++i)
	{
		cin >> ary[i];
		dp[i] = dp[i / 2] + ary[i]; // 부모 노드 받아서 연속합 구하기
	}

	for (int i = (1 << num) - 1; i >= 1; --i)
	{
		ll left = dp[i * 2];
		ll right = dp[i * 2 + 1];
		if (left > right)
		{
			ary[i] += llabs(left - right);
			dp[i] = left;
		}
		else if (left < right)
		{
			ary[i] += llabs(left - right);
			dp[i] = right;
		}
		else
		{
			dp[i] = left;
		}
	}

	for (int i = 1; i <= (1 << (num + 1)) - 1; ++i)
	{
		//cout << ary[i] << " ";
		result += ary[i];
	}
	cout << result;
	return 0;
}