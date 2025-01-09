#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	ll sum = 0, result = 0;
	vector<ll>v(num + 1);
	for (int i = 1; i <= num; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	sum /= num;
	for (int i = 1; i < num; ++i)
	{
		if (v[i] > sum)
		{
			ll temp = v[i] - sum;
			v[i] -= temp;
			v[i + 1] += temp;
			result += temp;
			// 차이만큼 건내주기
		}
		else if (v[i] < sum)
		{
			ll temp = sum - v[i];
			v[i] += temp;
			v[i + 1] -= temp;
			result += temp;
		}
	}
	cout << result;
	return 0;
}