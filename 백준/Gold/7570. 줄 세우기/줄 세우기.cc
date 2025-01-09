#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) // swap이 아니고 맨 앞, 맨 뒤로 보내는거라.. 순싸클X, LIS X, counting inversions X 흠
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 1, len = 1;
	cin >> n;
	vector<pii>v(n);
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b] = v[i];
		cin >> a;
		b = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; ++i)
	{
		if (v[i].second < v[i + 1].second)
		{
			len++;
		}
		else
		{
			ans = max(ans, len);
			len = 1;
		}
	}
	cout << n - max(ans, len);
	return 0;
}