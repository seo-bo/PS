#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	vector<pii>v;
	int start = -1;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '1')
		{
			if (start == -1)
			{
				start = i;
			}
		}
		else
		{
			if (start != -1)
			{
				v.push_back(make_pair(start, i - 1));
				start = -1;
			}
		}
	}
	if (start != -1)
	{
		v.push_back(make_pair(start, n - 1));
	}
	vector<int>p = { v[k - 2].first, v[k - 2].second, v[k - 1].first, v[k - 1].second };
	string ans = str;
	for (int i = p[1] + 1; i <= p[3]; ++i)
	{
		str[i] = (i <= p[1] + (p[3] - p[2] + 1)) ? '1' : '0';
	}
	cout << str;
	return 0;
}
