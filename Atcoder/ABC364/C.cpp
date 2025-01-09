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
	ll n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<ll> A(n);
	vector<ll> B(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> B[i];
	}
	vector <pll> v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = { A[i], B[i] };
	}
	sort(v.begin(), v.end(), [](const pll& a, const pll& b)
		{
			return max(a.first, a.second) > max(b.first, b.second);
		});
	auto ca = [&](ll l, const vector<ll>& v)
		{
			vector<pll> idx;
			for (int i = 0; i < n; ++i)
			{
				idx.push_back({ v[i], i });
			}
			sort(idx.rbegin(), idx.rend());
			ll sum = 0, cnt = 0;
			for (const auto& [value, idx] : idx)
			{
				sum += value;
				cnt++;
				if (sum > l)
				{
					return cnt;
				}
			}
			return n;
		};
	cout << min(ca(x, A), ca(y, B));
	return 0;
}
