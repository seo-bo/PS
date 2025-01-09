#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, b = 0, k = 0;
	cin >> a >> b >> k;
	vector<int>ans;
	ans.push_back(a);
	int cnt = 0;
	for (int i = a + 1; i <= b - 1 && cnt < k - 2; ++i)
	{
		if (i % a == 0 && b % i == 0)
		{
			ans.push_back(i);
			cnt++;
		}
	}
	ans.push_back(b);
	if (ans.size() != k)
	{
		cout << -1;
		return 0;
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}