#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) //높이를 정한다음 최소 겉넓이를 구하자?
{
	// 실수연산 때문에 틀린거야 오버플로우때문에 틀린거야?
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll k = 0;
	cin >> k;
	vector<ll>ans(4, 0);
	vector<ll>v(4, 0);
	ans[0] = LLONG_MAX;
	// 최소 겉넓이가 뭐지? -> 갭이 크게? -> 한층에 최소한으로 수용할 수 있게끔
	for (ll i = 1; i <= 1005000; ++i) // 겉넓이가 제일 클때는 정육면체일때니까 높이는 10^6까지?
	{
		ll capa = (k + i - 1) / i; // 한층에 수용가능한 최대상자들
		ll pivot = sqrt(capa); // 정육면체 가로 , 세로 len
		if (pivot * pivot < capa)
		{
			pivot++;
		}
		ll temp = pivot * pivot - capa;
		ll gap = sqrt(temp);
		ll cmp = pivot * i * 2 + pivot * pivot - gap * gap;
		v[0] = cmp, v[1] = pivot - gap, v[2] = pivot + gap, v[3] = i;
		sort(v.begin() + 1, v.end());
		ans = min(ans, v);
	}
	for (int i = 1; i <= 3; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}