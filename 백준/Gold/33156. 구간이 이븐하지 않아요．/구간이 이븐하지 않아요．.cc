#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int ary[5005] = { 0, };
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>temp(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> temp[i].first;
		temp[i].second = i;
	}
	sort(temp.begin(), temp.end());
	int pre = -1, cur = 0;
	for (int i = 0; i < n; ++i)
	{
		if (temp[i].first != pre)
		{
			cur++;
			pre = temp[i].first;
			temp[i].first = cur;
		}
		else
		{
			temp[i].first = cur;
		}
	}
	sort(temp.begin(), temp.end(), [&](const pii& a, const pii& b)
		{
			return a.second < b.second;
		});
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = temp[i].first;
	}
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		int left = i - 1, right = i, pivot = 0;
		while (left >= 0 && right < n)
		{
			if (++ary[v[left]] == 1)
			{
				pivot++;
			}
			else if (ary[v[left]] == 0)
			{
				pivot--;
			}
			if (--ary[v[right]] == -1)
			{
				pivot++;
			}
			else if (ary[v[right]] == 0)
			{
				pivot--;
			}
			if (!pivot)
			{
				ans = max(ans, right - left + 1);
			}
			left--;
			right++;
		}
		memset(ary, 0, sizeof(ary));
	}
	cout << ans;
	return 0;
}