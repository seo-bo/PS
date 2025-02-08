#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n;
	vector<int>cr(n);
	for (auto& i : cr)
	{
		cin >> i;
	}
	cin >> m;
	vector<int>bx(m);
	for (auto& i : bx)
	{
		cin >> i;
	}
	sort(cr.begin(), cr.end(), greater<int>());
	sort(bx.begin(), bx.end(), greater<int>());
	if (bx[0] > cr[0])
	{
		cout << -1;
		return 0;
	}
	int ans = 0;
	while (!bx.empty())
	{
		ans++;
		auto it = bx.begin();
		for (auto& i : cr)
		{
			if (it == bx.end())
			{
				break;
			}
			while (it != bx.end())
			{
				if (i >= *it)
				{
					it = bx.erase(it);
					break;
				}
				else
				{
					++it;
				}
			}
		}
	}
	cout << ans;
	return 0;
}