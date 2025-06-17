#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, len = 0;
	cin >> n;
	vector<vector<int>>v(n);
	for (int i = 0; i < n; ++i)
	{
		while (1)
		{
			int temp = 0;
			cin >> temp;
			if (temp == -1)
			{
				break;
			}
			v[i].push_back(temp);
		}
		len = max(len, (int)v[i].size());
	}
	for (int i = 1; i <= len; ++i)
	{
		set<vector<int>>ss;
		int cnt = 1;
		for (auto& j : v)
		{
			vector<int>temp;
			for (int k = 0; k < i; ++k)
			{
				if ((int)j.size() <= k)
				{
					temp.push_back(0);
				}
				else
				{
					temp.push_back(j[k]);
				}
			}
			ss.insert(temp);
			if (cnt != ss.size())
			{
				break;
			}
			cnt++;
		}
		if (ss.size() == n)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}