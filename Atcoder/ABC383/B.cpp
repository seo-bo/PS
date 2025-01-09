#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0, D = 0;
	cin >> h >> w >> D;
	vector<vector<char>>v(h, vector<char>(w));
	vector<pii>temp;
	for (int i = 0; i < h; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < w; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] == '.')
			{
				temp.push_back(make_pair(i, j));
			}
		}
	}
	int len = temp.size();
	vector<vector<int>>p(len);
	for (int i = 0; i < len; i++)
	{
		auto [a, b] = temp[i];
		for (int j = 0; j < len; j++)
		{
			auto [c, d] = temp[j];
			int pivot = abs(a - c) + abs(b - d);
			if (pivot <= D)
			{
				p[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			vector<bool>ok(len, false);
			for (auto& k : p[i])
			{
				ok[k] = true;
			}
			for (auto& k : p[j])
			{
				ok[k] = true;
			}
			int cnt = 0;
			for (int k = 0; k < len; ++k)
			{
				if (ok[k])
				{
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}
