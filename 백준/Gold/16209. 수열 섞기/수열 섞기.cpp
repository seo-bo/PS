#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>minus, plus;
	ll zero = 0;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (temp == 0)
		{
			zero++;
		}
		else if (temp < 0)
		{
			minus.push_back(temp);
		}
		else
		{
			plus.push_back(temp);
		}
	}
	sort(minus.rbegin(), minus.rend());
	sort(plus.begin(), plus.end());
	int left = 0, right = minus.size() - 1, d = 0, idx = 0;
	vector<ll>ans(n);
	while (idx < (int)minus.size())
	{
		if (d == 0)
		{
			ans[right--] = minus[idx++];
		}
		else
		{
			ans[left++] = minus[idx++];
		}
		d = (d + 1) % 2;
	}
	left = n - plus.size(), right = n - 1, d = 0, idx = 0;
	while (idx < (int)plus.size())
	{
		if (d == 1)
		{
			ans[right--] = plus[idx++];
		}
		else
		{
			ans[left++] = plus[idx++];
		}
		d = (d + 1) % 2;
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}