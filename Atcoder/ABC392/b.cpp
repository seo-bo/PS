#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	set<int>ss;
	for (int i = 0; i < m; ++i)
	{
		int temp = 0;
		cin >> temp;
		ss.insert(temp);
	}
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		if (ss.find(i) == ss.end())
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
