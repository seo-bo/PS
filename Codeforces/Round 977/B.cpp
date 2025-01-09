#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, x = 0;
		cin >> n >> x;	
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		int idx = 0;
		ll ans = 0;
		map<ll, map<ll, ll>>mm;
		for (; idx < n; ++idx)
		{
			if (ans == v[idx])
			{
				ans++;
			}
			else if (ans > v[idx])
			{
				mm[v[idx] % x][v[idx]]++;
				continue;
			}
			else // i가 ans보다 크면 성립 ㄴㄴ
			{
				break;
			}
		}
		for (; idx < n; idx++)
		{
			mm[v[idx] % x][v[idx]]++;
		}
		int p = ans;
		for (;;)
		{
			int pivot = ans % x;
			if (mm[pivot].empty())
			{
				break;
			}
			auto it = mm[pivot].begin();
			if (it->first > ans)
			{
				break;
			}
			if (!(--it->second))
			{
				mm[pivot].erase(it->first);
			}
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
