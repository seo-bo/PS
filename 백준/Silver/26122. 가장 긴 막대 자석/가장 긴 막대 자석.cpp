#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	int cur = 0;
	vector<int>v;
	cur += (str[0] == 'N') ? 1 : -1;
	for (int i = 1; i < n; ++i)
	{
		if (cur < 0 && str[i] == 'N')
		{
			v.push_back(cur);
			cur = 1;
		}
		else if (cur > 0 && str[i] == 'S')
		{
			v.push_back(cur);
			cur = -1;
		}
		else
		{
			cur += (str[i] == 'N') ? 1 : -1;
		}
	}
	v.push_back(cur);
	int ans = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		ans = max(ans, min(abs(v[i]), abs(v[i - 1])) * 2);
	}
	cout << ans;
	return 0;
}