#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	for (int a = 1; a <= n; ++a)
	{
		for (int b = a; b <= n; ++b) // 정사각형 생각해야함
		{
			int c = n - a - b;
			if (b > c) // 이렇게 되면 중복을 세게 되는듯 ㅇㅇ
			{
				break;
			}
			if (a + b > c) // 작은놈에서 늘려갈거니까? c가 제일 큰놈이 될 수 있도록
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}