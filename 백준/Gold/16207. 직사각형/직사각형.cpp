#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // 변 하나 만들고, 다른 변 하나 만들고...
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	vector<ll>temp;
	for (int i = 0; i < n - 1; ++i)
	{
		if (v[i] - v[i + 1] <= 1)
		{
			if (!temp.empty())
			{
				ans += temp.back() * v[i + 1];
				temp.pop_back();
			}
			else
			{
				temp.push_back(v[i + 1]);
			}
			++i;
		}
	}
	cout << ans;
	return 0;
}