#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	string pivot = str;
	sort(pivot.begin(), pivot.end());
	vector<pii>ans;
	int len = str.size();
	for (int i = 0; i < len; ++i)
	{
		if (pivot[i] == str[i])
		{
			continue;
		}
		char p = str[i];
		for (int j = i + 1; j < len; ++j)
		{
			if (p == pivot[j])
			{
				if (pivot[j] > pivot[i])
				{
					ans.push_back(make_pair(j + 1, i + 1));
				}
				else
				{
					ans.push_back(make_pair(i + 1, j + 1));
				}
				swap(pivot[i], pivot[j]);
				break;
			}
		}
	}
	for (auto& [a, b] : ans)
	{
		cout << a << ' ' << b << '\n';
	}
	return 0;
}