#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	else if (n == 2)
	{
		cout << "2 1";
		return 0;
	}
	else if (n % 2)
	{
		cout << -1;
		return 0;
	}
	vector<int>ans(n);
	for (int i = 0, p = n; i < n; i += 2, p -= 2)
	{
		ans[i] = p;
	}
	for (int i = 1, p = 1; i < n; i += 2, p += 2)
	{
		ans[i] = p;
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}