#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	ll left = 0, right = n / 2, ans = 0;
	// 큰떡 + 큰떡? 근데 이미 작은떡 + 큰떡에서 처리 되지 않으려나 그런 조합은 ㅇㅇ
	while (left < n / 2 && right < n)
	{
		if (v[left] * 2 <= v[right])
		{
			left++, right++, ans++;
		}
		else
		{
			right++;
		}
	}
	cout << ans;
	return 0;
}
