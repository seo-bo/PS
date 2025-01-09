#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string pivot = "ABCDE";
	vector<vector<char>>ans(n, vector<char>(5));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		vector<int>temp;
		int g = 0, b = 0, y = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (str[j] == 'G')
			{
				ans[i][j] = pivot[j];
				g++;
			}
			else if (str[j] == 'B')
			{
				ans[i][j] = 'Z';
				b++;
			}
			else
			{
				ans[i][j] = pivot[j];
				temp.push_back(j);
				y++;
			}
		}
		if (y == 1)
		{
			if (!b)
			{
				cout << "IMPOSSIBLE";
				return 0;
			}
			else
			{
				int idx = temp.front();
				for (int j = 0; j < 5; ++j)
				{
					if (j != idx && ans[i][j] == 'Z')
					{
						ans[i][idx] = pivot[j];
					}
				}
			}
		}
		else if (y > 0)
		{
			for (int j = 0; j < temp.size() - 1; ++j)
			{
				swap(ans[i][temp[j]], ans[i][temp[j + 1]]);
			}
		}
	}
	cout << pivot << '\n';
	for (auto& i : ans)
	{
		for (auto& j : i)
		{
			cout << j;
		}
		cout << '\n';
	}
	return 0;
}