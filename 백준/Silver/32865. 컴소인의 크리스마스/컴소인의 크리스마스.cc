#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, idx1 = 0, idx2 = 0, cnt = 1;
	cin >> n;
	vector<pii>v(n);
	ll sum = 0;
	for (auto& [a, b] : v)
	{
		cin >> a;
		b = cnt++;
		sum += (ll)a + 1LL;
	}
	if (sum != 2 * n - 1)
	{
		cout << -1;
		return 0;
	}
	sort(v.begin(), v.end());
	while (idx2 < v.size())
	{
		if (v[idx2].first)
		{
			break;
		}
		idx2++;
	}
	while (idx1 < v.size())
	{
		if (v[idx1].first != 0)
		{
			break;
		}
		cout << v[idx1++].second << '\n';
		if (idx2 < v.size())
		{
			cout << v[idx2].second << '\n';
			if (--v[idx2].first == 0)
			{
				idx2++;
			}
		}
	}
	return 0;
}