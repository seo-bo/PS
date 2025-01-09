#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, l = 0;
	cin >> n >> m >> l;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	v.push_back(0), v.push_back(l);
	sort(v.begin(), v.end());
	vector<int>temp;
	for (int i = 1; i < v.size(); ++i)
	{
		temp.push_back(v[i] - v[i - 1]);
	}
	int left = 1, right = l, ans = l;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		for (auto& i : temp)
		{
			cnt += (i - 1) / mid;
		}
		if (cnt <= m)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}