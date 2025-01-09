#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, h = 0;
		cin >> h >> n;
		vector<ll>A(n), B(n);
		for (auto& i : A)
		{
			cin >> i;
			h -= i;
		}
		priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>>pq; // 쿨타임, 공격
		for (int i = 0; i < n; ++i)
		{
			cin >> B[i];
			pq.push(make_tuple(B[i] + 1, A[i], B[i]));
		}
		if (h <= 0)
		{
			cout << 1 << '\n';
			continue;
		}
		ll ans = 1;
		while (h > 0)
		{
			auto [a, b, c] = pq.top();
			ans = a;
			while (!pq.empty() && ans == get<0>(pq.top()))
			{
				auto [i, j, k] = pq.top();
				h -= j;
				pq.pop();
				pq.push(make_tuple(ans + k, j, k));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
