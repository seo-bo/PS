#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, res = 0;
		cin >> n;
		vector<int>v(n);
		vector<int>ans;
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		int maxi = v.back();
		v.pop_back();
		for (int i = 0; i < v.size(); ++i)
		{
			if (!(i % 2))
			{
				ans.push_back(v[i]);
			}
		}
		ans.push_back(maxi);
		for (int i = v.size() - 1; i >= 0; --i)
		{
			if ((i % 2))
			{
				ans.push_back(v[i]);
			}
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			res = max(res, abs(ans[i] - ans[(i + 1) % ans.size()]));
		}
		cout << res << '\n';
	}
	return 0;
}