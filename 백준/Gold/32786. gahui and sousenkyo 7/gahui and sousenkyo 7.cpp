#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, c = 0, k = 0;
	cin >> n >> c >> k;
	vector<int>ans(n);
	vector<pii>per;
	iota(ans.begin(), ans.end(), 1);
	int p = 0;
	if (k == 0)
	{
		for (int i = 0; i < c; ++i)
		{
			for (auto& j : ans)
			{
				cout << j << ' ';
				j++;
			}
			cout << '\n';
		}
		return 0;
	}
	else
	{
		int pre = 0;
		vector<int>v(k);
		for (auto& i : v)
		{
			cin >> i;
			p = max(p, i);
			--i;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < k; ++i)
		{
			per.push_back(make_pair(pre, v[i]));
			pre = v[i] + 1;
		}
	}
	int cur = n + 3;
	for (int i = 0; i < c; ++i)
	{
		for (auto& [l, r] : per)
		{
			deque<int>temp;
			for (int j = l; j <= r; ++j)
			{
				temp.push_back(ans[j]);
			}
			temp.push_back(temp.front());
			temp.pop_front();
			int idx = 0;
			for (int j = l; j <= r; ++j)
			{
				ans[j] = temp[idx++];
			}
			for (int j = l; j <= r; ++j)
			{
				cout << ans[j] << ' ';
			}
		}
		int cnt = 0;
		for (int j = p; j < n; ++j)
		{
			cout << cur + cnt++ << ' ';
			if (cur + cnt > 1000000)
			{
				cur = n + 3;
			}
		}
		cout << '\n';
		cur++;
	}
	return 0;
}