#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<int>col(m, 0);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		bool tg = false;
		if (str[0] == '1')
		{
			tg = true;
		}
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j] - '0';
			if (tg)
			{
				v[i][j] ^= 1;
			}
			col[j] += v[i][j];
		}
	}
	int pivot = 0, idx = 0;
	for (int i = 0; i < m; ++i)
	{
		if (col[i] > pivot)
		{
			pivot = col[i];
			idx = i;
		}
	}
	if (!pivot)
	{
		cout << n + 1;
		return 0;
	}
	else if (pivot > 2)
	{
		cout << 0;
		return 0;
	}
	int ans = 0;
	vector<int>temp;
	for (int i = 0; i < n; ++i)
	{
		if (v[i][idx])
		{
			temp.push_back(i);
		}
	}
	auto toggle = [&](int p)
		{
			vector<vector<int>>t = v;
			for (int i = 0; i < m; ++i)
			{
				t[p][i] ^= 1;
			}
			int ma = 0;
			for (int i = 0; i < m; ++i)
			{
				int tt = 0;
				for (int j = 0; j < n; ++j)
				{
					tt += t[j][i];
				}
				ma = max(ma, tt);
			}
			return (ma <= 1);
		};
	for (auto& i : temp)
	{
		if (toggle(i))
		{
			ans++;
		}
	}
	cout << ans + (pivot == 1);
	return 0;
}