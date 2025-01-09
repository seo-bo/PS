#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		vector<int>v;
		for (auto& i : str)
		{
			v.push_back(i - '0');
		}
		int len = str.size();
		for (int i = 0; i < len; ++i)
		{
			int p = min(len - 1, i + 9);
			int idx = i, cur = v[i];
			for (int j = i + 1; j <= p; ++j)
			{
				int temp = v[j] + i - j;
				if (temp > cur)
				{
					cur = temp;
					idx = j;
				}
			}
			if (idx != i)
			{
				int tt = v[idx] + i - idx;
				for (int j = idx; j > i; --j)
				{
					v[j] = v[j - 1];
				}
				v[i] = tt;
			}
		}
		for (auto& i : v)
		{
			cout << i;
		}
		cout << '\n';
	}
}
