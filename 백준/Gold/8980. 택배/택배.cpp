#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) // 약간 회의실 배정 이랑 비?슷?한거같은데
// 무조건 빨리 배송하는게 이득? 증명은 어떻게하지? 근데 대충 맞는거 같은데..
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, w = 0, ans = 0;
	cin >> n >> m >> w;
	vector<tuple<int, int, int>>v(w);
	vector<int>vv(n + 1, 0);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	sort(v.begin(), v.end(), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
		{
			return get<1>(a) < get<1>(b);
		});
	for (auto& [a, b, c] : v)
	{
		int lim = *max_element(vv.begin() + a, vv.begin() + b), sum = 0;
		lim + c <= m ? sum = c : sum = m - lim;
		ans += sum;
		for (int j = a; j < b; ++j)
		{
			vv[j] += sum;
		}
	}
	cout << ans;
	return 0;
}