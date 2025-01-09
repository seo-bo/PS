#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 누적합 dp구나
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		map<ll, ll>mm;
		mm[0] = -1;
		ll sum = 0, ans = 0, pre = -1;
		for (int i = 0; i < n; ++i)
		{
			sum += v[i];
			if (mm.find(sum) != mm.end())
			{
				ll p = mm[sum];
				if (p >= pre)
				{
					ans++;
					pre = i;
				}
			}
			mm[sum] = i;
		}
		cout << ans << '\n';
	}
	return 0;
}
