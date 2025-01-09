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
	ll n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	n--;
	ll a = 1; // 총 길이
	while (1)
	{
		ll pivot = (a + 1) / 2; // 앞 자리
		if (n <= 9 * pow(10, (pivot - 1)))
		{
			string ans = to_string((ll)pow(10, (pivot - 1)) + n - 1); // 왜냐면 0도 있을것이기 때문, 그래서 -1 빼주기
			for (int i = pivot; i < a; ++i) // 홀수 짝수 동일하게 처리해주기
			{
				ans += ans[a - i - 1];
			}
			cout << ans;
			return 0;
		}
		else
		{
			n -= 9 * (ll)pow(10, (pivot - 1));
			a++;
		}
	}
	return 0;
}
