#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<int>ans;
	int p = 0;
	for (auto& i : str)
	{
		if (i == '-')
		{
			p++;
		}
		else if (i == '|')
		{
			if (p > 0)
			{
				ans.push_back(p);
				p = 0;
			}
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
