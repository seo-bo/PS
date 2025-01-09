#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

int ary[1000010] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, K = 0, d = 0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int g = 0, x = 0;
		cin >> g >> x;
		ary[x] = g;
	}
	ll sum = 0, result = 0;
	for (int i = 0; i <= 1000000; ++i)
	{
		if (i >= 2 * K + 1) // 왼쪽 포인터 당겨주기
		{
			sum -= ary[i - 2 * K - 1];
		}
		sum += ary[i]; // 오른쪽 포인터 당겨주기
		result = max(result, sum); // 최댓값 갱신
	}
	cout << result;
	return 0;
}
