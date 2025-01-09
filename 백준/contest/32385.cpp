#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>ans;
	if (n % 2)
	{
		ans.push_back(n * n);
	}
	int pivot = n / 2;
	ll num = -2;
	for (int i = 0; i < pivot; ++i)
	{
		ans.push_back(num--);
	}
	num = 2;
	for (int i = 0; i < pivot; ++i)
	{
		ans.push_back(num++);
	}
	sort(ans.begin(), ans.end());
	if (n % 2)
	{
		ans.push_back(n);
	}
	else
	{
		ans.push_back(0);
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}
