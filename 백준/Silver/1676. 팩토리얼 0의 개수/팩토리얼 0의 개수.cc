#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) // 5 , 25, 125이렇게 늘어남 5의 배수일때마다 1개씩
{
	ios::sync_with_stdio(false); // 모듈러 연산으로 구해봐도 좋을거같은데
	cin.tie(0);
	int n = 0;
	cin >> n;
	ll ans = 0;
	while (n)
	{
		if (!(n % 125))
		{
			ans += 3;
		}
		else if (!(n % 25))
		{
			ans += 2;
		}
		else if (!(n % 5))
		{
			ans++;
		}
		n--;
	}
	cout << ans;
	return 0;
}